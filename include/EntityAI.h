#ifndef ENTITYAI_H
#define ENTITYAI_H

#include "Entity.h"
#include "Battle.h"

#include "string"

class EntityAI
{
    public:
        EntityAI(); //Constructor

        /*Methods*/
        virtual void doAI(Battle *battle) = 0; //must implement on inherited class
        void setEntity(Entity *m_entity){entity = m_entity;}

        //Identifiers (because it's too difficult to cast the thingy here and there)
        void setEntityAIName(std::string s){EntityAIName = s;}
        std::string getEntityAIName(){return EntityAIName;}

        virtual ~EntityAI(); //Destructor

    protected:

    private:
        Entity *entity;
        std::string EntityAIName;
};

#endif // ENTITYAI_H
