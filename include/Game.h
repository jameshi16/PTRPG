#ifndef GAME_H
#define GAME_H

#include <vector>

#include "Event.h"
#include "Item.h"
#include "Player.h"

#include "boost\chrono.hpp"
#include "boost\thread.hpp"

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
        Event* addEvent (Event*); //pushes back an event to the top of the EventList

        ///Kinda don't use this, use only when you need to completely replace an item
        Item* setItem(unsigned int, Item*); //replaces an item at the position
        Item* addItem (Item*); //pushes back an item to the top of the EventList

        vector<Event*> getAllEvents(); //returns a copy of the whole array of events
        vector<Item*> getAllItems(); //returns a copy of the whole array of items

        unsigned int sizeOfEvents(); //returns the size of the event array
        unsigned int sizeOfItems(); //returns the size of the item array

        Player *player = new Player(); //This is the player

        static Game *currentGameInstance; //Temporary solution for EventASScript and ItemASScript to work
        boost::mutex gameLogicMutex; //apparently I declared a mutex that could not be accessed

        ~Game();

    protected:

    private:
        vector<Event*> EventList = {}; //This creates a vector that is able to store events
        vector<Item*> ItemList = {}; //This creates a vector that is able to store items

        bool continueGameLoop = true; //This is used to stop a gameloop if needed

};
#endif // GAME_H
