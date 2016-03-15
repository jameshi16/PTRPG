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

        Event* getEvent(unsigned int); //get the event at a position
        Item* getItem(unsigned int); //get an item at a position

        ///Kinda don't use this, use only when you need to completely replace an event
        Event* setEvent(unsigned int, Event*); //replaces the event at the position
        Event* push_backEvent (Event*); //pushes back an event to the top of the EventList

        ///Kinda don't use this, use only when you need to completely replace an item
        Item* setItem(unsigned int, Item*); //replaces an item at the position
        Item* push_backItem (Item*); //pushes back an item to the top of the EventList

        Event* getAllEvents(); //returns a copy of the whole array of events
        Item* getAllItems(); //returns a copy of the whole array of items

        Player *player = new Player(); //This is the player

        ~Game();

    protected:

    private:
        vector<Event*> EventList = {}; //This creates a vector that is able to store events
        vector<Item*> ItemList = {}; //This creates a vector that is able to store items
};

#endif // GAME_H
