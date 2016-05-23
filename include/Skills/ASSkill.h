#ifndef ASSKILL_H
#define ASSKILL_H

#include <angelscript.h>

#include <Game.h>
#include <Skill.h>
#include <log.h>
#include <iostream>
#include <string>

class ASSkill : public Skill
{
    public:
        void useSkill(Game *game)
        {
            if (!m_isDead->Get()) //ensures that script is not dead
            {
                asIScriptEngine *engine = m_obj->GetEngine(); //Gets the engine
                asIScriptContext *ctx = engine->RequestContext(); //Requests the context from the engine

                //Gets the method
                ctx->Prepare(m_obj->GetObjectType()->GetMethodByDecl("void useSkill(Game@)"));
                ctx->SetObject(m_obj);
                ctx->SetArgObject(0, game);
                ctx->Execute();

                engine->ReturnContext(ctx);
            }
        }

        ///Factory's for the script
        static ASSkill *Factory()
        {
            asIScriptContext *ctx = asGetActiveContext(); //Gets the context calling the function
            asIScriptFunction *func = ctx->GetFunction(0); //Gets the function calling factory

            if (func->GetObjectType() == 0 || std::string(func->GetObjectType() -> GetName()) != "ASSkill")
            {
                ctx->SetException("Skills not properly instantiated.");
            }

            asIScriptObject *obj = reinterpret_cast<asIScriptObject*>(ctx->GetThisPointer(0)); //Changes the void pointer into an object pointer

            return new ASSkill(obj); //makes new class :D
        }

        void AddToGame()
        {
            asIScriptObject *obj = reinterpret_cast<asIScriptObject*>(m_obj->GetEngine()->CreateScriptObject(m_obj->GetObjectType())); //makes new obj based on this obj
            ASSkill *theobj = *reinterpret_cast<ASSkill**>(obj->GetAddressOfProperty(0)); //Makes a pointer based on ASSkill

            theobj->AddRef(); //Makes both sides alive

            //Checks if SkillName is empty.
            if (theobj->getSkillName() == "")
            {
                Loggers::nL.e("Definition of SkillName not found. Insert setSkillName(skillname); into the constructor of skill class " + (std::string)(m_obj->GetObjectType()->GetName()) + ".");
                obj->Release();
                theobj->Release();
                return;
            }

            Game().currentGameInstance->addSkill(theobj); //adds it to the game

            obj->Release(); //Releases this, as it is just a lesser copy of theobj
        }

        //Need this to ensure survivability between C++ and script
        void AddRef()
        {
            m_refCount++; //Increase C++ side (generally, m_refCount shouldn't need to go beyond 1)

            //Increase script side
            if (!m_isDead->Get())
                m_obj->AddRef();
        }

        void Release()
        {
            if (!m_isDead->Get())
                m_obj->Release();

            if (--m_refCount == 0) delete this; //Deletes this class object as well
        }

    protected:
        ASSkill(asIScriptObject *obj) : m_obj(0), m_isDead(0), m_refCount(1) //initializes m_refCount as 1 to inform script that we are alive
        {
            //Links m_isDead as a weak reference flag
            m_isDead = obj->GetWeakRefFlag();
            m_isDead->AddRef();

            m_obj = obj;
        }
        virtual ~ASSkill()
        {
            //Release the ref flag
            m_isDead->Release();
        }

        int m_refCount; //Even until now, I have no idea what this is. But it makes everything work

        asILockableSharedBool *m_isDead; //They share this boolean, and it locks whenever one of the two interfaces tries to do something
        asIScriptObject *m_obj; //The script
    private:
};

#endif // ASSKILL_H
