#ifndef ITEM_H
#define ITEM_H

class Game; //Can't declare each other using #include, so I just do forward declaration

class Item
{
    public:
        Item();

        virtual int useItem(Game*) = 0; //abstract function
        virtual ~Item();

    protected:

    private:
};

#endif // ITEM_H
