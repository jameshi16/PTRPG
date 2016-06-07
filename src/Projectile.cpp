#include "Projectile.h"

#include "math.h"

Projectile::Projectile()
{
    //ctor
}

/**
@return The radius of the projectile from the center of the projectile
*/
int Projectile::getProjectileRadius()
{
    if (currentType > 1 || currentType < 0) //checks that the current type is not invalid
        return 0;

    if (m_animation == 0 || m_image == 0 || m_animationctrl == 0 || m_staticbitmap == 0) //checks that there is at least 2 variables set
        return 0;

    if (currentType == PROJECTILE_TYPE_ANIMATION) //if projectile is a animation
    {
        int x = m_animationctrl->GetPosition().x; //gets the x value
        int y = m_animationctrl->GetPosition().y; //gets the y value

        //I am aware that x and y are integers, so they cannot hold decimal values. Doesn't matter, the position can't be in decimal places either
        int centerX = getProjectileCenter(x,y).x;
        int centerY = getProjectileCenter(x,y).y;

        if ((centerX - x) > (centerY - y)) //if the center of x minus the actual x is more than the center of y minus the actual y (getting radius by larger side)
            return (centerX - x); //return that as the radius

        if ((centerY - y) > (centerX - x)) //if the center of x minus the actual x is less than the center of y minus the actual y
            return (centerY - y); //return that as the radius

        if ((centerY - y) == (centerX - x)) //if they are exactly equal
            return (centerX - x); //returning any one of these are fine
    }

    if (currentType == PROJECTILE_TYPE_IMAGE) //if projectile is an image
    {
        int x = m_staticbitmap->GetPosition().x; //gets the x value
        int y = m_staticbitmap->GetPosition().y; //gets the y value

        //I am aware that x and y are integers, so they cannot hold decimal values. Doesn't matter, the position can't be in decimal places either
        int centerX = getProjectileCenter(x,y).x;
        int centerY = getProjectileCenter(x,y).y;

        if ((centerX - x) > (centerY - y)) //if the center of x minus the actual x is more than the center of y minus the actual y (getting radius by smaller side)
            return (centerY - y); //return that as the radius

        if ((centerY - y) > (centerX - x)) //if the center of x minus the actual x is less than the center of y minus the actual y
            return (centerX - x); //return that as the radius

        if ((centerY - y) == (centerX - x)) //if they are exactly equal
            return (centerX - x); //returning any one of these are fine
    }
    return 0;
}

/**deals damage to power*/
void Projectile::powerDamage(Projectile* theFirst, Projectile* theOther)
{
    if (theFirst->power == theOther->power)
    {
        delete theFirst;
        delete theOther;
        return;
    }

    if (theOther->power < theFirst->power)
    {
        theFirst->power -= theOther->power;
        delete theOther;
        return;
    }

    if (theFirst->power < theOther->power)
    {
        theOther->power -= theFirst->power;
        delete theFirst;
        return;
    }

    return;
}

/**deals damage to power**/
void Projectile::powerDamage(Projectile* theOther)
{
    powerDamage(this, theOther); //lazy lazy programming
}

/**
@return Center of the projectile
*/
wxPoint Projectile::getProjectileCenter(int x, int y)
{
    if (currentType == PROJECTILE_TYPE_ANIMATION)
    {
        return wxPoint(x + (m_animationctrl->GetSize().GetWidth()/2), y + (m_animationctrl->GetSize().GetHeight()/2))
    }
    if (currentType == PROJECTILE_TYPE_IMAGE)
    {
        return wxPoint(x + (m_staticbitmap->GetSize().GetWidth()/2), y + (m_staticbitmap->GetSize().GetHeight()/2));
    }
    return wxPoint(0, 0);
}

/**
@return true or false
*/
bool Projectile::projectileCollides(Projectile* theFirstOne, Projectile* theOtherOne)
{
    //Who knew co-ordinate geometry would be useful here? (I'm amazed lol)
    double distance = sqrt(((theFirstOne->posY() - theOtherOne->posY())^2) + ((theFirstOne->posX() - theOtherOne->posX())^2)); //a piece of art right here
    if (distance <= (theFirstOne->getProjectileRadius() + theOtherOne->getProjectileRadius())) //If the distance matching and less
    {
        return true;
    }
    return false;
}

/**
@return true or false
*/
bool Projectile::projectileCollides(Projectile* theOtherOne)
{
    return projectileCollides(this, theOtherOne); //lazy programming for the win
}

/**
@return x co-ordinate
*/
int Projectile::posX()
{
    if (m_animation != 0 && m_animationctrl != 0)
        return m_animationctrl->GetPosition().x;

    if (m_image != 0 && m_staticbitmap != 0)
        return m_staticbitmap->GetPosition().x;

    return 0;
}

/**
Sets the position
*/
void Projectile::posX(int x)
{
    if (m_animation != 0 && m_animationctrl != 0)
        m_animationctrl->SetPosition(wxPoint(x, m_animationctrl->GetPosition().y));

    if (m_image != 0 && m_staticbitmap != 0)
        m_staticbitmap->SetPosition(wxPoint(x, m_animationctrl->GetPosition().y));
}

/**
@return the y co-ordinate
*/
int Projectile::posY()
{
    if (m_animation != 0 && m_animationctrl != 0)
        return m_animationctrl->GetPosition().y;

    if (m_image != 0 && m_staticbitmap != 0)
        return m_staticbitmap->GetPosition().y;

    return 0;
}

/**
Sets the position
*/
void Projectile::posY(int y)
{
    if (m_animation != 0 && m_animationctrl != 0)
        m_animationctrl->SetPosition(wxPoint(m_animationctrl->GetPosition().x, y));

    if (m_image != 0 && m_staticbitmap != 0)
        m_staticbitmap->SetPosition(wxPoint(m_animationctrl->GetPosition().x, y));
}

/**
Gets the position
*/
wxPoint Projectile::pos()
{
    if (m_animation != 0 && m_animationctrl != 0)
        return m_animationctrl->GetPosition();

    if (m_image != 0 && m_staticbitmap != 0)
        return m_staticbitmap->GetPosition();

    return wxPoint(0,0); //not possible lmao
}

/**
sets the position
*/
void Projectile::pos(int x, int y)
{
    if (m_animation != 0 && m_animationctrl != 0)
        m_animationctrl->SetPosition(wxPoint(x, y));

    if (m_image != 0 && m_staticbitmap != 0)
        m_animationctrl->SetPosition(wxPoint(x,y));
}

void Projectile::pos(wxPoint thePoint)
{
    pos(thePoint.x, thePoint.y); //I'm lazy ok
}

int Projectile::centerPosX()
{
    if (m_animation != 0 && m_animationctrl != 0)
        return getProjectileCenter(m_animationctrl.GetPosition().x, m_animationctrl.GetPosition().y).x;

    if (m_image != 0 && m_staticbitmap != 0)
        return getProjectileCenter(m_staticbitmap.GetPosition().x, m_staticbitmap.GetPosition().y).x;

    return 0;
}

void Projectile::centerPosX(int x)
{
    if (m_animation != 0 && m_animationctrl != 0)
    {
        posX(x - (m_animationctrl.GetSize().GetWidth()/2));
    }
    if (m_image != 0 && m_staticbitmap != 0)
    {
        posX(x - (m_staticbitmap.GetSize().GetWidth()/2));
    }
}

int Projectile::centerPosY()
{
    if (m_animation != 0 && m_animationctrl !=0)
    {
        return getProjectileCenter(m_animationctrl->GetPosition().x, m_animationctrl->GetPosition().y).y;
    }
    if (m_image != 0 && m_staticbitmap != 0)
    {
        return getProjectileCenter(m_staticbitmap->GetPosition().x, m_staticbitmap->GetPosition().y).y;
    }
    return 0;
}

void Projectile::centerPosY(int y)
{
    if (m_animation != 0 && m_animationctrl != 0)
    {
        posY(y - (m_animationctrl.GetSize().GetHeight()/2));
    }
    if (m_image != 0 && m_animationctrl != 0)
    {
        posY(y- (m_staticbitmap.GetSize().GetHeight()/2));
    }
}

void Projectile::centerPos(int x, int y)
{
    if (m_animation != 0 && m_animationctrl != 0)
    {
        posX(x - (m_animationctrl.GetSize().GetWidth()/2));
        posY(y - (m_animationctrl.GetSize().GetHeight()/2));
    }
    if (m_image != 0 && m_staticbitmap != 0)
    {
        posX(x - (m_staticbitmap.GetSize().GetWidth()/2));
        posY(y - (m_staticbitmap.GetSize().GetHeight()/2));
    }
}

void Projectile::centerPos(wxPoint thePoint)
{
    centerPos(thePoint.x, thePoint.y);
}

Projectile::~Projectile()
{
    //I needs to destroy some objects correctly
    delete m_animation;
    delete m_image;
    delete m_animationctrl;
    delete m_staticbitmap;
}
