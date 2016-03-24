#include "DebugItem.h"
#include "Game.h"

DebugItem::DebugItem()
{
    //ctor
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
