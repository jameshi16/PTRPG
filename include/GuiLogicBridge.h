#ifndef GUILOGICBRIDGE_H
#define GUILOGICBRIDGE_H

#include <wx/stattext.h>
#include <wx/listctrl.h>
#include <wx/bmpbuttn.h>

class Game;

using namespace std;

class GuiLogicBridge
{
    public:
        GuiLogicBridge();

        //int updateLoop(int frequency); //frequency is in milliseconds
        int update(Game*);

        static wxStaticText *HpLabel;
        static wxStaticText *NameLabel;
        static wxListCtrl *InventoryDisplay;
        static wxBitmapButton *PlayerPic;

        virtual ~GuiLogicBridge();

    protected:

    private:
};

#endif // GUILOGICBRIDGE_H
