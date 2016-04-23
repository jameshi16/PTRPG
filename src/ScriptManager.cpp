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

///Loads everything in the game class (almost everything)
void ScriptManager::WrapGame(asIScriptEngine *engine);

///Loads the EventASScript
void ScriptManager::WrapEvent(asIScriptEngine *engine)
{
    engine->RegisterObjectType("EventASScript_t", 0, asOBJ_REF);
    engine->RegisterObjectBehaviour("EventASScript_t", asBEHAVE_FACTORY, "EventASScript_t @f()", asFUNCTION(EventASScript::Factory), asCALL_CDECL);
    engine->RegisterObjectBehaviour("EventASScript_t", asBEHAVE_ADDREF, "void f()", asMETHOD(FooScripted, AddRef), asCALL_THISCALL);
    engine->RegisterObjectBehaviour("EventASScript_t", asBEHAVE_RELEASE, "void f()", asMETHOD(FooScripted, Release), asCALL_THISCALL);
    engine->RegisterObjectMethod("EventASScript_t", "void useItem()", asMETHOD(FooScripted, useItem), asCALL_THISCALL);
    engine->RegisterObjectProperty("FooScripted_t", "int returnValue", asOFFSET(FooScripted, returnValue));
}

///Loads the ItemASScript
void ScriptManager::WrapItem(asIScriptEngine *engine)
{

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
