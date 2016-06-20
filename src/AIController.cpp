#include "AIController.h"
#include "log.h"

using namespace std;

AIController::AIController()
{
    //ctor
    Loggers.nL.n("AI initiated");
}

void AIController::addEntityPair(Entity entity, EntityAI *entityAI)
{
    AIControllerMutex.lock(); //locks the mutex

}

AIController::~AIController()
{
    //dtor
}
