#include "EventChangePlayerName.h"
#include "Player.h"

EventChangePlayerName::EventChangePlayerName()
{
    //ctor
}

int EventChangePlayerName::ExecuteEvent()
{
    Player.setPlayerName("Yuki"); //Changes the name
}

int EventChangePlayerName::canExecute()
{
    return true; //no required things to do
}

EventChangePlayerName::~EventChangePlayerName()
{
    //dtor
}
