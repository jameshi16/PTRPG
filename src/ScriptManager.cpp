#include "ScriptManager.h"
#include <assert.h>

#include <scriptstdstring/scriptstdstring.h> //I'm not sure if I'm supposed to add these to the angelscript folder
#include <scriptbuilder/scriptbuilder.h>

//All the includes for the script to understand what's going on
#include <Game.h>
#include <Event.h>
#include <Item.h>
#include <Player.h>
#include <EventASScript.h>
#include <ItemASScript.h>

#include "boost/filesystem.hpp"

#include "log.h"

ScriptManager::ScriptManager()
{
    //ctor
}

asIScriptEngine* ScriptManager::MasterEngine = asCreateScriptEngine();

///Allows access to member properties of Game, Event, Item and Player
void ScriptManager::WrapGame(asIScriptEngine *engine)
{
    engine->RegisterObjectType("Game", 0, asOBJ_REF | asOBJ_NOCOUNT); //Registers Game as an object useable by the script
    engine->RegisterObjectType("Event", 0, asOBJ_REF | asOBJ_NOCOUNT); //Registers Event as an object
    engine->RegisterObjectType("Item", 0, asOBJ_REF | asOBJ_NOCOUNT); //Registers Item as an object
    engine->RegisterObjectType("Player", 0, asOBJ_REF | asOBJ_NOCOUNT); //Registers Game as an object

    engine->RegisterObjectMethod("Game", "Event@ getEvent(int)", asMETHODPR(Game, getEvent, (unsigned int), Event*), asCALL_THISCALL); //registers get event
    engine->RegisterObjectMethod("Game", "Item@ getItem(int)", asMETHODPR(Game, getItem, (unsigned int), Item*), asCALL_THISCALL); //registers get item
    engine->RegisterObjectMethod("Game", "Event@ setEvent(int, Event@)", asMETHODPR(Game, setEvent, (unsigned int, Event*), Event*), asCALL_THISCALL); //registers set item
    engine->RegisterObjectMethod("Game", "Event@ addEvent(Event@)", asMETHODPR(Game, addEvent, (Event*), Event*), asCALL_THISCALL); //registers add event
    engine->RegisterObjectMethod("Game", "Item@ setItem(int, Item@)", asMETHODPR(Game, setItem, (unsigned int, Item*), Item*), asCALL_THISCALL); //register set item
    engine->RegisterObjectMethod("Game", "Item@ addItem(Item@)", asMETHODPR(Game, addItem, (Item*), Item*), asCALL_THISCALL); //registers add item

    //TODO: implement getAllEvent() and getAllItems() [not happening soon]

    engine->RegisterObjectMethod("Player", "string setPlayerName(string)", asMETHODPR(Player, setPlayerName, (std::string), std::string), asCALL_THISCALL); //registers changename
    engine->RegisterObjectMethod("Player", "string getPlayerName()", asMETHOD(Player, getPlayerName), asCALL_THISCALL); //registers getname
    engine->RegisterObjectMethod("Player", "int setPlayerHP(int)", asMETHODPR(Player, setPlayerHP, (unsigned int), unsigned int), asCALL_THISCALL); //registers set player hp
    engine->RegisterObjectMethod("Player", "int getPlayerHP()", asMETHOD(Player, setPlayerHP), asCALL_THISCALL); //registers get player hp

    engine->RegisterObjectProperty("Game", "Player @player", asOFFSET(Game, player));
}

///Loads the EventASScript
void ScriptManager::WrapEvent(asIScriptEngine *engine)
{
    engine->RegisterObjectType("EventASScript_t", 0, asOBJ_REF);
    engine->RegisterObjectBehaviour("EventASScript_t", asBEHAVE_FACTORY, "EventASScript_t @f()", asFUNCTION(EventASScript::Factory), asCALL_CDECL);
    engine->RegisterObjectBehaviour("EventASScript_t", asBEHAVE_ADDREF, "void f()", asMETHOD(EventASScript, AddRef), asCALL_THISCALL);
    engine->RegisterObjectBehaviour("EventASScript_t", asBEHAVE_RELEASE, "void f()", asMETHOD(EventASScript, Release), asCALL_THISCALL);
    engine->RegisterObjectMethod("EventASScript_t", "int ExecuteEvent(Game@)", asMETHODPR(EventASScript, ExecuteEvent, (Game*), int), asCALL_THISCALL);
    engine->RegisterObjectMethod("EventASScript_t", "bool canExecute(Game@)", asMETHODPR(EventASScript, canExecute, (Game*), bool), asCALL_THISCALL);
    engine->RegisterObjectMethod("EventASScript_t", "void addEventToList(Game@)", asMETHODPR(EventASScript, addEventToList, (Game*), void), asCALL_THISCALL);
}

///Loads the ItemASScript
void ScriptManager::WrapItem(asIScriptEngine *engine)
{
    engine->RegisterObjectType("ItemASScript_t", 0, asOBJ_REF);
    engine->RegisterObjectBehaviour("ItemASScript_t", asBEHAVE_FACTORY, "ItemASScript_t @f()", asFUNCTION(ItemASScript::Factory), asCALL_CDECL);
    engine->RegisterObjectBehaviour("ItemASScript_t", asBEHAVE_ADDREF, "void f()", asMETHOD(ItemASScript, AddRef), asCALL_THISCALL);
    engine->RegisterObjectBehaviour("ItemASScript_t", asBEHAVE_RELEASE, "void f()", asMETHOD(ItemASScript, Release), asCALL_THISCALL);
    engine->RegisterObjectMethod("ItemASScript_t", "int useItem(Game@)", asMETHODPR(ItemASScript, useItem, (Game*), int), asCALL_THISCALL);
    engine->RegisterObjectMethod("ItemASScript_t", "void addItemToList(Game@)", asMETHODPR(ItemASScript, addItemToList, (Game*), void), asCALL_THISCALL);
}

/**Only call once ever**/
void ScriptManager::loadScripts(vector<string> s_FileNames)
{
    Loggers::nL.n("Loading AngelScript scripts...");

    asIScriptEngine *engine = MasterEngine;

    engine->SetMessageCallback(asFUNCTION(MessageCallback), 0, asCALL_CDECL);
    RegisterStdString(engine);

    /*Registers absolutely everything*/
    WrapGame(engine);
    WrapEvent(engine);
    WrapItem(engine);
    /*done lol*/

    for (int iii = 0; iii < s_FileNames.size(); iii++)
    {
        Loggers::nL.n("Processing Script: " + s_FileNames[iii]);
        CScriptBuilder builder; //creates a builder
        builder.StartNewModule(engine, (s_FileNames[iii] + "module").c_str()); //makes a makeshift name with the filename
        builder.AddSectionFromFile(s_FileNames[iii].c_str()); //adds the script
        builder.BuildModule(); //builds the module

        asIScriptModule *mod = engine->GetModule((s_FileNames[iii] + "module").c_str()); //gets the module
        asIScriptFunction *func = mod->GetFunctionByDecl("void main()"); //runs main (the scripts will have to register it's classes on its own)
        if (func == 0)
        {
            Loggers::nL.e("Script " + s_FileNames[iii] + " does not have void main()");
        }

        asIScriptObject *obj = reinterpret_cast<asIScriptObject*> (engine->CreateScriptObject(mod->GetType ))

        //creates the context
        asIScriptContext *ctx = engine->CreateContext();
        ctx->Prepare(func);
        ctx->Execute();
        //Don't really need to shut down the engine yet

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
    Loggers::nL.e("Error while parsing. Full error: @Row: " + Loggers::its(msg->row) +
               " and @Column: " + Loggers::its(msg->col) +
               " at section: " + msg->section +
               " " + msg->message); //Logs the error
}

ScriptManager::~ScriptManager()
{
    //dtor
}
