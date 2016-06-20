#ifndef PROJAI_H
#define PROJAI_H

#include "Battle.h"
#include "Projectile.h"

#include "string"

class ProjAI
{
    public:
        ProjAI(); //Constructor

        /*Methods*/
        virtual void doAI(Battle *battle) = 0; //must implement on inherited class
        void setProjectile(Projectile *m_projectile){projectile = m_projectile;}

        //Identifiers (because it's too difficult to cast the thingy here and there)
        void setProjAIName(std::string s){projAIName = s;}
        std::string getProjAIName(){return projAIName;}

        virtual ~ProjAI(); //Destructor

    protected:

    private:
        Projectile *projectile;
        std::string projAIName;
};

#endif // PROJAI_H
