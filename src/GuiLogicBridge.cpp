#include "GuiLogicBridge.h"
#include "Game.h"
#include "wxCustomListItem.h"
#include "sstream"

GuiLogicBridge::GuiLogicBridge()
{
    //ctor
}

//variables
wxStaticText *GuiLogicBridge::HpLabel = 0; //I should be
wxStaticText *GuiLogicBridge::NameLabel = 0; //zero memorying this
wxListCtrl *GuiLogicBridge::InventoryDisplay = 0; //Zero Memory

int GuiLogicBridge::update(Game *game)
{
    /*Gui Update Block*/
    if (HpLabel != 0) //if HPLabel is not a null pointer
    {
        stringstream ss;
        ss << game->player->getPlayerHP();
        if (HpLabel->GetLabel() != ss.str()) {HpLabel->SetLabel(ss.str());} //updates the HP Label
    }

    if (NameLabel != 0)
    {
        if (NameLabel->GetLabel() != game->player->getPlayerName()) {NameLabel->SetLabel(game->player->getPlayerName());} //updates the name label
    }

    if (game->player->guiUpdate == true)
    for (unsigned int iii = 0; iii < game->player->Inventory.size(); iii++)
    {
        wxCustomListItem cli;
        cli.SetText(game->player->getItem(iii)->getItemName()); //text of item is item name
        cli.setPairedItem(game->player->getItem(iii)); //pair it to the item
        cli.SetId(iii); //sets the item id
        InventoryDisplay->InsertItem(cli); //insert it into the inventory
    }

    /*reset all variables that asks for visual updates*/
    game->player->guiUpdate = false;

    return 0; //Everything is ok
}

GuiLogicBridge::~GuiLogicBridge()
{
    //dtor
}
