#ifndef AICONTROLLER_H
#define AICONTROLLER_H

//Own includes
#include "ProjAI.h"
#include "EntityAI.h"

//System includes
#include <string>
#include <vector>
#include <map>

//Boost includes
#include <boost/thread/mutex.hpp>

//wxWidget includes
#include "wx/animate.h"
#include "wx/statbmp.h"
#include "wx/image.h"
#include "wx/bitmap.h"

/**
Thread-safe class to control all AI
*/

class AIController
{
    public:
        AIController();

        /*Object access functions*/
        void addEntityPair(Entity entity, EntityAI *entityAI); //Use this to insert both the entity and the entity AI, then pair them together as default AI

        void pairEntity(Entity entity, EntityAI *entityAI); //Use this to pair them together as default AI (make sure to insert both the entity AND the AI beforehand, if not errors will occur)
        void pairEntity(std::string s_entity, std::string s_entityAI); //Safest way to the above, it has checks and everything

        void addEntityAI(EntityAI *entityAI); //Use this to add an entityAI to the available AIs
        void removeEntityAI(unsigned int n); //Use this to remove an entityAI based on index
        void removeEntityAI(std::string s_entityAI); //Use this to remove an entityAI based on name
        void addProjAI(ProjAI *projAI); //Use this to add an projAI to the available AIs
        void removeProjAI(unsigned int n); //Use this to remove a ProjAI based on index
        void removeProjAI(std::string s_projAI); //Use this to remove projAI based on name

        void addEntity(Entity entity); //copies the entity and adds it to the available entities
        void addProj(Projectile proj); //copies the projectile and adds it to the available projectiles
        void removeEntity(std::string s); //safest way to remove entities
        void removeProj(std::string s); //safest way to remove projectiles
        void removeEntity(unsigned int n); //removes an entity using it's index
        void removeProj(unsigned int n); //removes a projectile using it's index

        unsigned int getProjAIIndexBasedOnName(std::string s); //does what it is supposed to do
        unsigned int getEntityAIIndexBasedOnName(std::string s); //does what it is supposed to do

        unsigned int getProjIndexBasedOnName(std::string s); //does what it is supposed to do
        unsigned int getEntityIndexBasedOnName(std::string s); //does what it is supposed to do

        void stopLoop(){killLoop = true;} //stops the AIController Loop

        /*AI Controlling Powers*/
        void doTheLoop(int frequencyOfLoop);

        /*Deployed*/
        void createDeployedEntity(std::string s);
        void createDeployedEntity(unsigned int n);
        void createDeployedProjectile(std::string s);
        void createDeployedProjectile(unsigned int n);
        void destroyDeployedEntity(std::string s);
        void destroyDeployedEntity(unsigned int n);
        void destroyDeployedProjectile(std::string s);
        void destroyDeployedProjectile(unsigned int n);


        virtual ~AIController();

    protected:

    private:
        static std::vector<EntityAI*> v_entityAI = {}; //the entity AIs available (there should only be one of each kind of AI)
        static std::vector<ProjAI*> v_projAI = {}; //the projectile AIs available (there should only be one of each kind of AI)

        static std::vector<Entity> v_entity = {}; //the entities available
        static std::vector<Projectile> v_projectile = {}; //the projectiles available

        static std::map<Entity*, EntityAI*> m_defaultEntityAIs = {}; //the default AI for each entity (if the function doesn't find anything here, then the most basic AI is used)
        static std::map<Projectile*, ProjAI*> m_defaultProjAIs = {}; //the default AI for each projectile

        std::vector<EntityAI*> deployedEntityAI = {}; //the deployed entity AIs
        std::vector<ProjAI*> deployedProjAI = {}; //the deployed projectile AIs

        bool killLoop = false; //kill the loop?

        boost::mutex AIControllerMutex; //The mutex to lock AIController
};

#endif // AICONTROLLER_H
