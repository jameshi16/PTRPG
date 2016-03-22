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
#include <wx/notebook.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/panel.h>
#include <wx/richtext/richtextctrl.h>
#include <wx/statbmp.h>
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
        void OnClose(wxCloseEvent& event);
        //*)

        //(*Identifiers(Productivity_RPGDialog)
        static const long ID_STATICBITMAP1;
        static const long ID_STATICTEXT2;
        static const long ID_STATICTEXT4;
        static const long ID_STATICTEXT3;
        static const long ID_STATICTEXT6;
        static const long ID_STATICTEXT5;
        static const long ID_STATICTEXT7;
        static const long ID_PANEL2;
        static const long ID_STATICTEXT8;
        static const long ID_PANEL1;
        static const long ID_NOTEBOOK1;
        static const long ID_STATICTEXT1;
        static const long ID_RICHTEXTCTRL1;
        //*)

        //(*Declarations(Productivity_RPGDialog)
        wxNotebook* Notebook1;
        wxStaticText* StaticText2;
        wxRichTextCtrl* RichTextCtrl1;
        wxStaticText* StaticText6;
        wxPanel* Panel1;
        wxStaticText* StaticText1;
        wxStaticBitmap* playerImage;
        wxStaticText* StaticText5;
        wxStaticText* playerNameLabel;
        wxStaticText* hpLabel;
        wxPanel* Panel2;
        wxStaticText* StaticText4;
        wxStaticText* ConstText1;
        //*)

        Game game;

        DECLARE_EVENT_TABLE()
};

#endif // PRODUCTIVITY_RPGMAIN_H
