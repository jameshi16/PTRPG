#ifndef PLAYER_H
#define PLAYER_H

#include <string>

using namespace std;

class Player
{
    public:
        Player();
        string setPlayerName(string); //Sets the player name and returns the player name
        unsigned int setPlayerHP(unsigned int); //Sets the player health
        virtual ~Player();
    protected:

    private:
        unsigned int Hp = 0; //Health
        string playerName = "Player"; //Playername
};

#endif // PLAYER_H
