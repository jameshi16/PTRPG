#ifndef PROJAI_H
#define PROJAI_H

#include "Battle.h"
#include "Projectile.h"


class ProjAI
{
    public:
        ProjAI(); //Constructor

        /*Methods*/
        virtual void doAI(Battle *battle) = 0; //must implement on inherited class
        void setProjectile(Projectile *m_projectile)
        {
            projectile = m_projectile;
        }

        virtual ~ProjAI(); //Destructor

    protected:

    private:
        Projectile *projectile;
};

#endif // PROJAI_H
