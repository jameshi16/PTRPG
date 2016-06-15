#ifndef ENTITY_H
#define ENTITY_H

#include "Projectile.h" //This has all the other includes I need, too.

#include "string"

enum imageTypeEntity
{
    ENTITY_TYPE_ANIMATION,
    ENTITY_TYPE_IMAGE
};

class Entity
{
    public:
        Entity();

        /**
        @param pathToImage - The path to the image file
        @param Type - The type of the file
        */
        static Entity *Create(wxWindow *callingWindow, std::string pathToImage, imageTypeEntity entityType)
        {
            Entity *entity = new Entity;
            if (entityType == ENTITY_TYPE_ANIMATION)
            {
                wxAnimation *theAnimation = new wxAnimation(pathToImage); //Creates a new animation
                wxAnimationCtrl *theAnimationCtrl = new wxAnimationCtrl(callingWindow, wxWindow::NewControlId(), *theAnimation); //creates a new animation control
                entity->m_animation = theAnimation; //sets the entity animation
                entity->m_animationctrl = theAnimationCtrl; //set the entity animation control
                entity->currentType = entityType; //sets the current type to the entity type passed from the caller
                return entity;
            }
            if (entityType == ENTITY_TYPE_IMAGE)
            {
                wxImage *theImage = new wxImage(pathToImage); //Creates a new image
                wxStaticBitmap *theBitmapCtrl = new wxStaticBitmap(callingWindow, wxWindow::NewControlId(), wxBitmap(*theImage)); //creates a new bitmap control (with ID 0)
                entity->m_image = theImage; //sets entity image
                entity->m_staticbitmap = theBitmapCtrl; //sets entity control
                entity->currentType = entityType; //sets the current type to the entity type passed from the caller
                return entity;
            }
            return entity;
        }

        /**
        @return The radius of the entity from the center of the entity
        */
        int getEntityRadius();
        /**
        @arg x - the x-coordinate of the entity
        @arg y - the y-coordinate of the entity
        @return The center of the entity
        */
        wxPoint getEntityCenter(int x, int y);
        /**
        @arg theProjectile -  the projectile to check the collision against
        @return - true or false
        */
        bool Collision(Projectile* theProjectile);
        /**
        @arg theEntity - the entity to check collision
        @arg theProjectile - the projectile to check collision against
        @return - true or false
        */
        static bool Collision(Entity* theEntity, Projectile* theProjectile);

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

        ///Removes some health from projectiles
        void healthDamage(Projectile* theProjectile);
        ///Removes some health from projectiles
        static void healthDamage(Entity* theEntity, Projectile* theProjectile);

        void operator=(const Entity& p)
        {
            this->m_animation = p.m_animation;
            this->m_image = p.m_image;
            this->m_animationctrl = p.m_animationctrl;
            this->m_staticbitmap = p.m_staticbitmap;
            this->currentType = p.currentType;
            this->health = p.health;
        }

        virtual ~Entity();

    protected:

    private:
        //Storing animation/image
        wxAnimation *m_animation = 0;
        wxImage *m_image = 0;

        //Storing the control
        wxAnimationCtrl *m_animationctrl = 0;
        wxStaticBitmap *m_staticbitmap = 0;

        imageTypeEntity currentType;
        double health = 0.0;

    friend class Projectile;
};

#endif // ENTITY_H
