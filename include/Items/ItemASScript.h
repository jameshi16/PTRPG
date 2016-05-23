#ifndef ITEMASSCRIPT_H
#define ITEMASSCRIPT_H

#include <Item.h>
#include <Game.h>
#include <ScriptManager.h>
#include <log.h>

#include <angelscript.h>
#include <scriptbuilder/scriptbuilder.h>
#include <scriptstdstring/scriptstdstring.h>

class ItemASScript : public Item
{
    public:
        int useItem(Game* game)
        {
            if (!m_isDead->Get())
            {
                asIScriptEngine *engine = m_obj->GetEngine(); //gets the engine
                asIScriptContext *ctx = engine->RequestContext(); //requests the current context

                //Use VM to find the same function and execute it
                ctx->Prepare(m_obj->GetObjectType()->GetMethodByDecl("int useItem(Game@)"));
                ctx->SetObject(m_obj);
                ctx->SetArgObject(0, game);
                ctx->Execute();

                engine->ReturnContext(ctx);
                return 1; //perfect execution
            }

            return 0;
        }

        void AddToGame()
        {
            asIScriptObject *obj = reinterpret_cast<asIScriptObject*>(m_obj->GetEngine()->CreateScriptObject(m_obj->GetObjectType())); //Creates a new item object
            ItemASScript *theobj = *reinterpret_cast<ItemASScript**>(obj->GetAddressOfProperty(0)); //Gets the address of property, then somehow make it go through 2 dereferences, and then dereference that shit again

            theobj->AddRef(); //Makes the object come to life again

            //Checks if ItemName is empty.
            if (theobj->getItemName() == "")
            {
                Loggers::nL.e("Definition of ItemName not found. Insert setItemName(itemname); into the constructor of item class " + (std::string)(m_obj->GetObjectType()->GetName()) + ".");
                obj->Release();
                theobj->Release();
                return;
            }

            Game().currentGameInstance->addItem(theobj); //Adds the item to the game

            obj->Release(); //destroys object used to create the Item
        }

        static ItemASScript *Factory()
        {
            asIScriptContext *ctx = asGetActiveContext(); //gets the active context
            //Get the function that called this method to ensure that the correct class is doing the correct things
            asIScriptFunction *func = ctx->GetFunction(0);
            if (func->GetObjectType() == 0 || std::string(func->GetObjectType()->GetName()) != "ItemASScript")
            {
                ctx->SetException("Could not create a new class of Item.");
                return 0;
            }

            //Get the pointer from the calling function
            asIScriptObject *obj = reinterpret_cast<asIScriptObject*>(ctx->GetThisPointer(0));
            return new ItemASScript(obj); //end of factory function
        }

        void AddRef()
        {
            m_refCount++;

            //increase script side
            if (!m_isDead->Get())
                m_obj->AddRef();
        }

        void Release()
        {
            if (!m_isDead->Get())
                m_obj->Release(); //releases the script side

            if (--m_refCount == 0) delete this;
        }

    protected:
        ItemASScript(asIScriptObject *obj) : m_isDead(0), m_obj(0), m_refCount(1)
        {
            //Sets the m_isDead
            m_isDead = obj->GetWeakRefFlag();
            m_isDead->AddRef();

            m_obj = obj;
        }
        ~ItemASScript()
        {
            //Release the flag
            m_isDead->Release();
        }

        int m_refCount; //The reference counter
        asILockableSharedBool *m_isDead; //C++ uses this to check if object is dead
        asIScriptObject *m_obj; //the script object

    private:
};

#endif // ITEMASSCRIPT_H
