#ifndef ASENTITYAI_H
#define ASENTITYAI_H

#include "EntityAI.h"
#include "angelscript.h"
#include "string"

class ASEntityAI : EntityAI
{
    public:
        /*Methods*/
        void doAI(Battle *battle)
        {
            if (!m_isDead->Get())
            {
                asIScriptEngine *engine = m_obj->GetEngine();
                asIScriptContext *ctx = engine->RequestContext(); //requests an unprepared context from the engine. Should not be released, but returned to the engine

                ctx->Prepare(m_obj->GetObjectType()->GetMethodByDecl("void doAI(Battle @battle, Entity @entity"));
                ctx->SetObject(m_obj);
                ctx->SetArgObject(0, battle);
                ctx->Execute();

                engine->ReturnContext(ctx); //returns to engine
            }
        }

        //The factory function for ASEntityAI, angelscript
        static ASEntityAI *Factory()
        {
            asIScriptContext *ctx = asGetActiveContext();
            //Gets function calling this function
            asIScriptFunction *func = ctx->GetFunction(0); //and here I thought each context could only contain one function
            if (func->GetObjectType() == 0 || std::string(func->GetObjectType()->GetName()) != "ASEntityAI") //if there is no object type (impossible), or the name of the calling function's object is not ASEntityAI
            {
                ctx->SetException("Failed to initialize ASEntityAI.");
                return 0; //returns a null pointer
            }

            //Get the "this" pointer from the calling function to link C++'s class to AngelScript's script class
            asIScriptObject *obj = reinterpret_cast<asIScriptObject*>(ctx->GetThisPointer(0)); //reinterpret cast the asIScriptObject, as the pointer was converted internally in AngelScript's engine

            return new ASEntityAI(obj); //creates the c++ object
        }

        //This is for the AIController to use, as each object of ASEntityAI controls an individual entity
        ASEntityAI *GenerateCopy()
        {
            //Create another instance of the derived script class from the c++ class
            asIScriptObject *obj = reinterpret_cast<asIScriptObject*>(m_obj->GetEngine()->CreateScriptObject(m_obj->GetObjectType())); //seems familiar?
            ASEntityAI *obj2 = *reinterpret_cast<ASEntityAI**>(obj->GetAddressOfProperty(0)); //Property 0 has to be the "this" pinter, no?

            //Increase the reference of obj2 (so now it's 2. I've no idea how this actually works)
            obj2->AddRef();

            //Release the new obj created
            obj->Release(); //ok so now the whole system is 1. Maybe AddRef() has some magic?

            return obj2; //copy created
        }

        //This function is going to add itself to the game
        void AddToGame()
        {
            //placeholder
        }

        //Reference counting
        void AddRef()
        {
            m_refCount++;
            if (!m_isDead->Get()) //if the lockable shared bool is false
                m_obj->AddRef(); //add a reference to the object as well
        }
        void Release()
        {
            if (!m_isDead->Get()) //if the lockable shared bool is false
                m_obj->Release(); //releases the reference

            if (--m_refCount == 0) delete this; //deletes this.
        }


    protected:
        ASEntityAI(asIScriptObject *obj) : m_obj(0), m_isDead(0), m_refCount(1) //creates an ASEntityAI object with the defaults
        {
            //a weak reference flag to the angelscript object
            m_isDead = obj->GetWeakRefFlag();
            m_isDead->AddRef(); //adds a reference to the angelscript object (a.k.a let both sides know that they exist)

            m_obj = obj;
        }

        ~ASEntityAI()
        {
            //Releases the flag
            m_isDead->Release();
            //gone
        }

        asILockableSharedBool *m_isDead;
        asIScriptObject *m_obj; //angelscript object

        int m_refCount; //the reference count

    private:

};

#endif // ASENTITYAI_H
