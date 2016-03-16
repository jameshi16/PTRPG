#include "Game.h"
#include "boost\chrono.hpp"
#include "boost\thread.hpp"

#include "GuiLogicBridge.h"

using namespace boost;

mutex gameLogicMutex; //declares a mutex

Game::Game()
{
    //ctor
}

int Game::GameLoop(int frequencyofLoop)
{
    //Begin a loop somewhere here or something
    while (true)
    {
        /*Event processing block*/
        for (int iii = 0; iii < EventList.size(); iii++)
        {
            gameLogicMutex.lock(); //stops all threads from accessing data
            if (EventList[iii]->canExecute(this) == true) //Pass "this", a pointer to the game class
            {
                EventList[iii]->ExecuteEvent(this); //for now, no handler for the return value
                delete EventList[iii]; //deletes the pointer
                EventList.erase(EventList.begin() + iii); //remove the pointer from the event list
            }
            gameLogicMutex.unlock(); //unlocks all the mutex
        }

        /*Update GUI*/
        GuiLogicBridge().update(this); //updates the GUI

        /*Logic processed time limit (this to prevent the CPU from working too hard)*/
        this_thread::sleep(posix_time::milliseconds(frequencyofLoop));
    }
    delete player; //Prevent memory over leak and stuff
}

/**
@arg position - The position of the item in the array
@return Returns the pointer to the event (the pointer is 0 if event does not exist)
*/
Event* Game::getEvent(unsigned int position)
{
    Event* returnValue = 0;
    gameLogicMutex.lock(); //locks the mutex
    if (!(position > EventList.size()))
        returnValue = EventList[position]; //sets a returnValue to the pointer
    gameLogicMutex.unlock(); //unlocks the mutex
    return returnValue;
}

/**
@arg position - The position of the item in the array
@return Returns the pointer to the event (the pointer is 0 if event does not exist)
*/
Item* Game::getItem(unsigned int position)
{
    Item* returnValue = 0;
    gameLogicMutex.lock(); //locks the mutex
    if (!(position > ItemList.size()))
        return returnValue = ItemList[position]; //sets a returnValue to the pointer
    gameLogicMutex.unlock(); //unlocks the mutex
    return returnValue;
}

/**
@arg position - The position to insert the item into the array
@arg Event* - The pointer to the event to insert into the array (does not need to be deleted)
@return Returns the pointer to the event
*/
Event* Game::setEvent(unsigned int position, Event* theEvent)
{
    gameLogicMutex.lock(); //locks the mutex
    EventList[position] = theEvent; //screw checking and all, just do it
    gameLogicMutex.unlock(); //unlocks the mutex
    return theEvent;
}

/**
@arg Event* The pointer to the event to insert the array (do not delete)
@return Returns the pointer to the event
*/
Event* Game::addEvent(Event* theEvent)
{
    gameLogicMutex.lock(); //locks the mutex
    EventList.push_back(theEvent);
    gameLogicMutex.unlock(); //unlock the mutex
    return theEvent;
}
Game::~Game()
{
    //dtor
    //delete player; //woah, so apparently you can't destruct this pointer in a virtual destructor
}
