#include "Game.h"
#include "boost\chrono.hpp"
#include "boost\thread.hpp"

#include "GuiLogicBridge.h"

using namespace boost;

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
            if (EventList[iii].canExecute(this) == true) //Pass "this", a pointer to the game class
            {
                EventList[iii].ExecuteEvent(this); //for now, no handler for the return value
            }
        }

        /*Update GUI*/
        GuiLogicBridge().update(this); //updates the GUI

        /*Logic processed time limit (this to prevent the CPU from working too hard)*/
        this_thread::sleep(posix_time::milliseconds(frequencyofLoop));
    }
}

Game::~Game()
{
    //dtor
}
