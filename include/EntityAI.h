#ifndef ENTITYAI_H
#define ENTITYAI_H

#include "Entity.h"
#include "Battle.h"

class EntityAI
{
    public:
        EntityAI(); //Constructor

        /*Methods*/
        virtual void doAI(Battle *battle) = 0; //must implement on inherited class
        void setEntity(Entity *m_entity)
        {
            entity = m_entity;
        }

        virtual ~EntityAI(); //Destructor

    protected:

    private:
        Entity *entity;
};

#endif // ENTITYAI_H
