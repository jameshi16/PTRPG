#include "AIController.h"
#include "log.h"

using namespace Loggers;

/*Static variables (a.k.a blank initialization for later)*/
std::vector<EntityAI*> AIController::v_entityAI = {};
std::vector<ProjAI*> AIController::v_projAI = {};

std::vector<Entity> AIController::v_entity = {};
std::vector<Projectile> AIController::v_projectile = {};

std::map <Entity*, EntityAI*> AIController::m_defaultEntityAIs = {};
std::map<Projectile*, ProjAI*> AIController::m_defaultProjAIs = {};

/*Functions*/
AIController::AIController()
{
    //ctor
    nL.n("AI initiated");
}

void AIController::addEntityPair(Entity entity, EntityAI *entityAI)
{
    AIControllerMutex.lock(); //locks the mutex

}

AIController::~AIController()
{
    //dtor
}
