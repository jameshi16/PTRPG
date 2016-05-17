#include "DebugItem.h"
#include "Game.h"
#include "string"

DebugItem::DebugItem()
{
    //ctor
    setItemName("developer.item");
}

///Uses the item
int DebugItem::useItem(Game* game)
{
    game->player->setPlayerHP(100);
    game->player->setPlayerName("debug");
}

DebugItem::~DebugItem()
{
    //dtor
}
