#ifndef ITEM_H
#define ITEM_H

#include "string"

class Game; //Can't declare each other using #include, so I just do forward declaration

class Item
{
    public:
        Item();

        std::string getItemName() { return ItemName; }
        std::string setItemName(std::string s) { return ItemName = s; }

        virtual int useItem(Game*) = 0; //abstract function
        virtual ~Item();

    protected:

    private:
        std::string ItemName = ""; //all items need to have this
};

#endif // ITEM_H
