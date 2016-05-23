#ifndef EVENTUSEITEM_H
#define EVENTUSEITEM_H

#include "Item.h"
#include "Event.h"

/***********************************************
Add an item to be used using this amazing class :O
(Wanted to make Event an important class of the game)
************************************************/
class EventUseItem : public Event
{
    public:
        EventUseItem(Item* item)
        {
            m_theItem = item; //:O WHAT COULD THIS LINE OF CODE POSSIBLY MEAN
        }

        int ExecuteEvent(Game* game)
        {
            return m_theItem->useItem(game); //JUST DO IT (dont let your dreams be dreams)
        }

        bool canExecute(Game*){return true;}

        virtual ~EventUseItem()
        {

        }

    protected:

    private:
        Item *m_theItem;
};

#endif // EVENTUSEITEM_H
