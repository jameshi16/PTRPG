#ifndef GAME_H
#define GAME_H

#include <vector>

#include "Event.h"
#include "Item.h"
#include "Player.h"

using namespace std;

class Game
{
    public:
        Game();

        int GameLoop(int frequencyofLoop = 10); //This will loop forever and ever, until an event that breaks it occurs (frequency of loop is in milliseconds!)

        vector<Event> EventList = {}; //This creates a vector that is able to store events

        vector<Item> ItemList = {}; //This creates a vector that is able to store items

        Player *player; //This is the player

        ~Game();

    protected:

    private:
};

#endif // GAME_H
