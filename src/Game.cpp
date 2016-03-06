#include "Game.h"
#include "boost\chrono.hpp"
#include "boost\thread.hpp"

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
        for (int iii = 0; iii < EventList; iii++)
        {

        }

        /*Logic processed time limit (this to prevent the CPU from working too hard)*/
        this_thread::sleep(posix_time::milliseconds(frequencyofLoop));
    }
}

Game::~Game()
{
    //dtor
}
