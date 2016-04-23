#ifndef EVENTASSCRIPT_H
#define EVENTASSCRIPT_H

#include <Event.h>

#include <angelscript.h>
#include <scriptbuilder/scriptbuilder.h>
#include <scriptstdstring/scriptstdstring.h>


class EventASScript : public Event
{
    public:
        /**@brief This class is used for initializing and adding scripted events.**/

        int ExecuteEvent(Game *game)
        {
            //Checks if script is alive
            if (!m_isDead->Get())
            {
                asIScriptEngine *engine = m_obj->GetEngine(); //imagine the complicated link here and there
                asIScriptContext *ctx = engine->RequestContext(); //gets the context of the thingy

                //GetMethodByDecl will give the virtual function of the script class, therefore when calling it, it will execute the derived method
                ctx->Prepare(m_obj->GetObjectType()->GetMethodByDecl("int ExecuteEvent(Game@)")); //prepares the type
                ctx->SetObject(m_obj);
                ctx->SetArgObject(0, game); //adds an argument
                ctx->Execute(); //runs it

                engine->ReturnContext(ctx); //gives back the context to the VM
            }
        }
        bool canExecute(Game* game)
        {
            //Checks if script is alive
            if (!m_isDead->Get())
            {
                asIScriptEngine *engine = m_obj->GetEngine(); //gets the engine
                asIScriptContext *ctx = engine->RequestContext(); //gets the context of the engine

                ctx->Prepare(m_obj->GetObjectType()->GetMethodByDecl("void canExecute()"));
                ctx->SetObject(m_obj);
                ctx->SetArgObject(0, game); //passes it the whole game
                ctx->Execute(); //runs it

                engine->ReturnContext(ctx); //gives back the context to the VM

                return abilityToExecute; //returns the value (0 or 1)
            }
            return 0;
        }

        int abilityToExecute;

        static EventASScript *Factory()
        {
            asIScriptContext *ctx = asGetActiveContext(); //Gets the active context
            asIScriptFunction *func = ctx->GetFunction(0); //Gets the function calling the factory

            if (func->GetObjectType() == 0 || std::string(func->GetObjectType()->GetName()) != "EventASScript") //If the function is valid, and if the function's object is from "EventASScript"
            {
                ctx->SetException("An attempt to initialize event class failed.");
                return 0; //failed lol
            }

            asIScriptObject *obj = reinterpret_cast<asIScriptObject*>(ctx->GetThisPointer(0)); //basically make a new pointer of asIScriptObject that is equal to ctx->GetThisPointer

            return new EventASScript(obj);
        }

        /*Reference counting*/
        void AddRef()
        {
            ++m_refCount;

            //Increase the reference counter on the script side (just in case one accidentally destroys itself)
            if (!m_isDead->Get())
                m_obj->AddRef();
        }
        void Release()
        {
            //Release the script instance
            if (!m_isDead->Get())
                m_obj->Release(); //If the object dies, changes m_obj to 0

            if (--m_refCount == 0) delete this; //Minus one. If the refcount is 0, then delete this instance of the class
        }
    protected:
        EventASScript(asIScriptObject *obj) : m_isDead(0), m_refCount(1), m_obj(0), abilityToExecute(0)
        {
            m_isDead = obj->GetWeakRefFlag(); //gets the reference flag (like an actual reference identifier)
            m_isDead->AddRef(); //adds 1 to the reference (makes m_isDead usable) (true)

            m_obj = obj;
        }
        ~EventASScript()
        {
            m_isDead->Release(); //becomes false, removes the weakRefFlag
        }

        // C++ holds a weak link (aka a number) to the script side to prevent the script and C++ from looping on each other
        asILockableSharedBool *m_isDead;
        asIScriptObject *m_obj;

        int m_refCount; //it either has a value or 0


    private:
};

#endif // EVENTASSCRIPT_H
