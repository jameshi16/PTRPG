#include "ScriptManager.h"
#include <assert.h>

#include <scriptstdstring/scriptstdstring.h> //I'm not sure if I'm supposed to add these to the angelscript folder
#include <scriptbuilder/scriptbuilder.h>

#include "boost/filesystem.hpp"

#include "log.h"

ScriptManager::ScriptManager()
{
    //ctor
}

void ScriptManager::doScriptMagic()
{

    using namespace Loggers; //declare the loggers namespace
    nL.d("doScriptMagic() called");
    /*do AngelScript's magic stuff*/

    //Create a script engine
    asIScriptEngine *engine = asCreateScriptEngine(); //Version number already included

    int r = engine->SetMessageCallback(asFUNCTION(this->MessageCallback), 0, asCALL_CDECL);
    nL.d("ScriptManger line 26 " + its(r)); //Get a human understandable return value (assert kills the program if the value is wrong)
    RegisterStdString(engine); //Register a string type for the scripts
    r = engine->RegisterGlobalFunction("void scriptTest()", asFUNCTION(scriptTest), asCALL_CDECL); assert (r >= 0); //Register functions that scripts would call

    /*Script loading sorcery*/
    //Uses a AngelScript addon because James is a lazy lolicon boy
    CScriptBuilder builder;
    r = builder.StartNewModule(engine, "NewModule"); //Starts a new module
    //TODO: error handling
    r = builder.AddSectionFromFile((boost::filesystem::current_path().string() + "\\addons\\test.as").c_str()); //Adds a section from the file (i.e. loading the damn file)
    //TODO: error handling
    r = builder.BuildModule(); //compiles the file
    //TODO: MORE ERROR HANDLING YAY

    /*Function identification sorcery*/
    asIScriptModule *module = engine->GetModule("NewModule"); //@line 32's module
    asIScriptFunction *func = module->GetFunctionByDecl("void main()"); //Just use void main() for now, we have nothing to lose
    //TODO: error handling
    asIScriptContext *ctx = engine->CreateContext(); //we need context to do basically everything
    ctx->Prepare(func); //Prepares the context by adding the function
    r = ctx->Execute(); //DO IT!
    //TODO: error handling

    /*Clean up sorcery*/
    ctx->Release(); //releases the context, kills itself (don't have to delete this)
    engine->ShutDownAndRelease(); //aye convenient functions do everything now for you, don't they?

}

void ScriptManager::loadScripts(vector<string> s_FileNames)
{
    Loggers.nL.n("Loading AngelScript scripts...");

    for (int iii = 0; iii < s_FileNames.size(); iii++)
    {
        Loggers.nL.n("Processing Script: " + FileNames[iii]);
    }
}

void ScriptManager::scriptTest()
{
    //I'm lazy to code a way to see this now, for now, just put your debugger here
    int done = 1;
    done = done;
}

void ScriptManager::MessageCallback(const asSMessageInfo *msg, void *param)
{
    Loggers.nL.e("Error while parsing. Full error: @Row: " + Loggers.its(msg->row) +
               "and @Column: " + Loggers.its(msg->col) +
               "at section: " + msg->section +
               " " + msg->message); //Logs the error
}

ScriptManager::~ScriptManager()
{
    //dtor
}
