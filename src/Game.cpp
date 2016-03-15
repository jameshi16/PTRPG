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
            mutex.lock(); //stops all threads from accessing data
            if (EventList[iii]->canExecute(this) == true) //Pass "this", a pointer to the game class
            {
                EventList[iii]->ExecuteEvent(this); //for now, no handler for the return value
                delete EventList[iii]; //deletes the pointer
                EventList->erase(iii); //remove the pointer from the event list
            }
            mutex.unlock(); //unlocks all the mutex
        }

        /*Update GUI*/
        GuiLogicBridge().update(this); //updates the GUI

        /*Logic processed time limit (this to prevent the CPU from working too hard)*/
        this_thread::sleep(posix_time::milliseconds(frequencyofLoop));
    }
    delete player; //Prevent memory over leak and stuff
}

Game::~Game()
{
    //dtor
    //delete player; //woah, so apparently you can't destruct this pointer in a virtual destructor
}
