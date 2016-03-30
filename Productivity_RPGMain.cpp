/***************************************************************
 * Name:      Productivity_RPGMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    James ()
 * Created:   2016-03-05
 * Copyright: James (nightsagaguild.ddns.net)
 * License:
 **************************************************************/

#include "Productivity_RPGMain.h"
#include <wx/msgdlg.h>
#include <boost/thread.hpp>
#include "GuiLogicBridge.h"
#include "Event.h"
#include "Item.h"

#include "log.h"

#include "ScriptManager.h"

/*Events to add*/
#include "EventChangePlayerName.h"

//(*InternalHeaders(Productivity_RPGDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(Productivity_RPGDialog)
const long Productivity_RPGDialog::ID_STATICTEXT1 = wxNewId();
const long Productivity_RPGDialog::ID_BUTTON1 = wxNewId();
const long Productivity_RPGDialog::ID_STATICTEXT2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(Productivity_RPGDialog,wxDialog)
    //(*EventTable(Productivity_RPGDialog)
    //*)
END_EVENT_TABLE()

Productivity_RPGDialog::Productivity_RPGDialog(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(Productivity_RPGDialog)
    Create(parent, id, _("wxWidgets app"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer2 = new wxBoxSizer(wxVERTICAL);
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("HP"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    BoxSizer2->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button1 = new wxButton(this, ID_BUTTON1, _("Change Displayname"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    BoxSizer2->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Displayname"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    BoxSizer2->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer2, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 4);
    SetSizer(BoxSizer1);
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Productivity_RPGDialog::OnButton1Click);
    Connect(wxID_ANY,wxEVT_INIT_DIALOG,(wxObjectEventFunction)&Productivity_RPGDialog::OnInit);
    //*)
}

Productivity_RPGDialog::~Productivity_RPGDialog()
{
    //(*Destroy(Productivity_RPGDialog)
    //*)
}

void Productivity_RPGDialog::OnQuit(wxCommandEvent& event)
{
    Close();
}

void Productivity_RPGDialog::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void Productivity_RPGDialog::OnInit(wxInitDialogEvent& event)
{
    using namespace boost;
    GuiLogicBridge::HpLabel = StaticText1;
    GuiLogicBridge::NameLabel = StaticText2;

    //!!DEBUG ONLY!!//
    {
        ScriptManager sm;
        sm.doScriptMagic();
    }


    thread t_1(bind(&Game::GameLoop, &game, 10)); //starts the game loop
}

void Productivity_RPGDialog::OnButton1Click(wxCommandEvent& event)
{
    EventChangePlayerName *e_changeName = new EventChangePlayerName(); //lol
    game.addEvent(e_changeName); //lets do it
    //do not need to destroy pointer
}
