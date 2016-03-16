/***************************************************************
 * Name:      Productivity_RPGMain.h
 * Purpose:   Defines Application Frame
 * Author:    James ()
 * Created:   2016-03-05
 * Copyright: James (nightsagaguild.ddns.net)
 * License:
 **************************************************************/

#ifndef PRODUCTIVITY_RPGMAIN_H
#define PRODUCTIVITY_RPGMAIN_H

#include "Game.h"

//(*Headers(Productivity_RPGDialog)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class Productivity_RPGDialog: public wxDialog
{
    public:

        Productivity_RPGDialog(wxWindow* parent,wxWindowID id = -1);
        virtual ~Productivity_RPGDialog();

    private:

        //(*Handlers(Productivity_RPGDialog)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnInit(wxInitDialogEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        //*)

        //(*Identifiers(Productivity_RPGDialog)
        static const long ID_STATICTEXT1;
        static const long ID_BUTTON1;
        static const long ID_STATICTEXT2;
        //*)

        //(*Declarations(Productivity_RPGDialog)
        wxStaticText* StaticText2;
        wxButton* Button1;
        wxStaticText* StaticText1;
        wxBoxSizer* BoxSizer2;
        wxBoxSizer* BoxSizer1;
        //*)

        Game game;

        DECLARE_EVENT_TABLE()
};

#endif // PRODUCTIVITY_RPGMAIN_H
