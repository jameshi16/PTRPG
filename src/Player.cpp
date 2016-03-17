#include "Player.h"

#include "boost/thread.hpp" //Include for Mutex

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

unsigned int Player::getPlayerHP()
{
    unsigned int returnValue = 0;
    mtx.lock();
    returnValue = Hp;
    mtx.unlock();
    return returnValue;
}

Player::~Player()
{
    //dtor
}
