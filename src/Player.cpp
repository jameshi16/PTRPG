#include "Player.h"

Player::Player()
{
    //ctor
}

string Player::setPlayerName(string s_PlayerName){return playerName = s_PlayerName;}
unsigned int Player::setPlayerHP(unsigned int n_HP){return Hp = n_HP;}

string Player::getPlayerName() {return playerName;}
unsigned int Player::getPlayerHP() {return Hp;}

Player::~Player()
{
    //dtor
}
