#include "EventChangePlayerName.h"
#include "Game.h"

EventChangePlayerName::EventChangePlayerName()
{
    //ctor
}

int EventChangePlayerName::ExecuteEvent(Game *game)
{
    game->player->setPlayerName("Yuki"); //Changes the name
}

bool EventChangePlayerName::canExecute(Game *game)
{
    return true; //no required things to do
}

EventChangePlayerName::~EventChangePlayerName()
{
    //dtor
}
