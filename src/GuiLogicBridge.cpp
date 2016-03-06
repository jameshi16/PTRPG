#include "GuiLogicBridge.h"
#include "Game.h"
#include "sstream"

GuiLogicBridge::GuiLogicBridge()
{
    //ctor
}

int GuiLogicBridge::update(Game *game)
{
    /*Gui Update Block*/
    if (HpLabel != 0) //if HPLabel is not a null pointer
    {
        stringstream ss;
        ss << game->player->getPlayerHP();
        HpLabel->SetLabel(ss.str()); //updates the HP Label
    }

    if (NameLabel != 0)
    {
        NameLabel->SetLabel(game->player->getPlayerName()); //updates the name label
    }

    return 0; //Everything is ok
}

GuiLogicBridge::~GuiLogicBridge()
{
    //dtor
}
