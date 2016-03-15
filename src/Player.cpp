#include "Player.h"

#include "boost/thread.hpp" //Include for Mutex

using namespace boost;
mutex mtx; //Declares a mutex object

Player::Player()
{
    //ctor
}

string Player::setPlayerName(string s_PlayerName){mtx.lock();return playerName = s_PlayerName;mtx.unlock();}
unsigned int Player::setPlayerHP(unsigned int n_HP){mtx.lock();return Hp = n_HP;mtx.unlock();}

string Player::getPlayerName(){mtx.lock();return playerName;mtx.unlock();}
unsigned int Player::getPlayerHP() {mtx.lock();return Hp;mtx.unlock();}

Player::~Player()
{
    //dtor
}
