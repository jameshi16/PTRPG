#ifndef DEBUGITEM_H
#define DEBUGITEM_H

#include <Item.h>

class Game;

class DebugItem : public Item
{
    public:
        DebugItem();

        int useItem(Game*);

        virtual ~DebugItem();

    protected:

    private:
};

#endif // DEBUGITEM_H
