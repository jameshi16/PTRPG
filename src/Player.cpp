#include "Player.h"
#include "Item.h"
#include "Skill.h"

//For the gui
#include "GuiLogicBridge.h"

#include "boost/thread.hpp" //Include for Mutex
#include "log.h" //log absolutely everything

using namespace boost;
mutex mtx; //Declares a mutex object

Player::Player()
{
    //ctor
}

string Player::setPlayerName(string s_PlayerName)
{
    mtx.lock();
    playerName = s_PlayerName;
    mtx.unlock();
    return s_PlayerName;
}

string Player::setPlayerPic(string s_PlayerPic)
{
    mtx.lock();
    playerPic.LoadFile(s_PlayerPic.c_str());
    guiUpdate = true;
    mtx.unlock();
    return s_PlayerPic;
}

unsigned int Player::setPlayerHP(unsigned int n_HP)
{
    mtx.lock();
    Hp = n_HP;
    mtx.unlock();
    return n_HP;
}

string Player::getPlayerName()
{
    string returnValue = "";
    mtx.lock();
    returnValue = playerName;
    mtx.unlock();
    return returnValue;
}

wxImage Player::getPlayerPic()
{
    wxImage returnValue;
    mtx.lock();
    returnValue = playerPic;
    guiUpdate = true;
    mtx.unlock();
    return returnValue;
}

unsigned int Player::getPlayerHP()
{
    unsigned int returnValue = 0;
    mtx.lock();
    returnValue = Hp;
    mtx.unlock();
    return returnValue;
}

/*inventory accessors*/
/**Returns 0 if not exist**/
Item* Player::getItem(unsigned int position)
{
    if (!(position > Inventory.size()))
        return Inventory[position];

    Loggers::nL.e("Error getting item at " + Loggers::its(position) + ".");
    return 0;
}

Item* Player::addItem(Item* item)
{
    Inventory.push_back(item); //pushes back the item
    guiUpdate = true; //tells the game to update the gui
    return item;
}

/**Returns 0 if not exist/size too huge**/
Item* Player::setItem(unsigned int position, Item* item)
{
    if (!(position > Inventory.size()))
    {
        Inventory[position] = item;
        return item;
    }
    Loggers::nL.e(Loggers::its(position) + " is above the Inventory size of " + Loggers::its(Inventory.size()) + ".");
    guiUpdate = true; //tells the game to update the gui
    return 0;
}

/**Returns 0 if no item found in position**/
int Player::removeItem(unsigned int position)
{
    if (position > Inventory.size())
        return 0;

    Inventory.erase(Inventory.begin() + position); //erases the item
    guiUpdate = true; //tells the game to update the gui
    return 1;
}

/**Returns 0 if not found**/
Item* Player::getItem(string s)
{
    for (int iii = 0; iii < Inventory.size(); iii++)
    {
        if (Inventory[iii]->getItemName() == s)
            return Inventory[iii];
    }
    return 0;
}

/**
@arg fromPos - the position you want to search from
@arg s - itemname
@return 0 if not found
**/
Item* Player::getItem(unsigned int fromPos, string s)
{
    for (int iii = fromPos; iii < Inventory.size(); iii++)
    {
        if (Inventory[iii]->getItemName() == s)
            return Inventory[iii];
    }
    return 0;
}

Player::~Player()
{
    //dtor
}
