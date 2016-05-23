#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>

using namespace std;

class Item; //Forward declaration for Inventory
class Skill; //Forward declaration for Skill

class GuiLogicBridge; //Forward declaration for the bridge

class Player
{
    public:
        Player();
        /*sets*/
        string setPlayerName(string); //Sets the player name and returns the player name
        unsigned int setPlayerHP(unsigned int); //Sets the player health

        /*gets*/
        string getPlayerName(); //self explanatory
        unsigned int getPlayerHP(); //self explanatory

        /*inventory accessors*/
        //*using positions*//
        Item* getItem(unsigned int); //Gets an item at a position
        Item* addItem(Item*); //Gives the player an item
        Item* setItem(unsigned int, Item*); //Sets an item and given position
        int removeItem(unsigned int); //Removes an item at given position
        //*using the item names*//
        Item* getItem(string);
        Item* getItem(unsigned int, string); //Gets an item from position onwards

        /*cool variables*/
        bool guiUpdate = true; //this will cause the inventory and skill list to update


        virtual ~Player();
    protected:

    private:
        unsigned int Hp = 0; //Health
        string playerName = "Player"; //Playername

        vector<Item*> Inventory = {}; //Inventory for the player
        vector<Skill*> Skills = {}; //Skills for the player

        friend class GuiLogicBridge;

};

#endif // PLAYER_H
