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

//(*Headers(Productivity_RPGDialog)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/statline.h>
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
        //*)

        //(*Identifiers(Productivity_RPGDialog)
        static const long ID_STATICTEXT1;
        static const long ID_BUTTON1;
        static const long ID_STATICLINE1;
        static const long ID_BUTTON2;
        //*)

        //(*Declarations(Productivity_RPGDialog)
        wxButton* Button1;
        wxStaticText* StaticText1;
        wxBoxSizer* BoxSizer2;
        wxButton* Button2;
        wxStaticLine* StaticLine1;
        wxBoxSizer* BoxSizer1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // PRODUCTIVITY_RPGMAIN_H
