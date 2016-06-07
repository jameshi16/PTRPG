#ifndef PROJECTILE_H
#define PROJECTILE_H

//Animation
#include "wx/animate.h"
//Just a static image
#include "wx/statbmp.h"
#include "wx/image.h"
//wxPoint
#include "wx/gdicmn.h"

#include "string"

enum imageType
{
    PROJECTILE_TYPE_ANIMATION,
    PROJECTILE_TYPE_IMAGE
};

class Projectile
{
    public:
        Projectile();

        /**
        @param pathToImage - The path to the image file
        @param Type - The type of the file
        */
        static Projectile Create(std::string pathToImage, imageType projectileType)
        {
            Projectile projectile();
            if (projectileType == PROJECTILE_TYPE_ANIMATION)
            {
            }
        }

        /**
        @return The radius of the projectile from the center of the projectile
        */
        int getProjectileRadius();
        /**
        @arg x - the x-coordinate of the projectile
        @arg y - the y-coordinate of the projectile
        @return The center of the projectile
        */
        wxPoint getProjectileCenter(int x, int y);
        /**
        @arg theOtherOne - the other projectile to check collision
        @return - true or false
        */
        bool projectileCollides(Projectile* theOtherOne);
        /**
        @arg theFirstOne - the first projectile to check collision
        @arg theOtherOne - the other projectile to check collision
        @return - true or false
        */
        static bool projectileCollides(Projectile* theFirstOne, Projectile* theOtherOne);

        ///@return the x co-ordinate
        int posX();
        ///@arg x - the x co-ordinate to set
        void posX(int x);
        ///@return the y co-ordinate
        int posY();
        ///@arg y - the y co-ordinate to set
        void posY(int y);

        ///@return the position
        wxPoint pos();
        ///@arg the positions to set
        void pos(int x, int y);
        ///@arg the wxPoint object
        void pos(wxPoint thePoint);

        ///@return the center x co-ordinate
        int centerPosX();
        ///@arg x - the x co-ordinate to set
        void centerPosX(int x);
        ///@return the center y co-ordinate
        int centerPosY();
        ///@arg y the y co-ordinate to set
        void centerPosY(int y);

        ///@arg the positions to set
        void centerPos(int x, int y);
        ///@arg the wxPoint object
        void centerPos(wxPoint thePoint);

        ///Removes some power from each other
        void powerDamage(Projectile* theOther);
        ///Removes some power from each other
        static void powerDamage(Projectile* theFirst, Projectile* theOther);

        Projectile operator=(const Projectile& p)
        {
        }

        virtual ~Projectile();

    protected:

    private:
        //Storing animation/image
        wxAnimation *m_animation = 0;
        wxImage *m_image = 0;

        //Storing the control
        wxAnimationCtrl *m_animationctrl = 0;
        wxStaticBitmap *m_staticbitmap = 0;

        imageType currentType;
        int power = 0;
};

#endif // PROJECTILE_H
