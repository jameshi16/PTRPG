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
const long Productivity_RPGDialog::ID_NOTEBOOK1 = wxNewId();
const long Productivity_RPGDialog::ID_RICHTEXTCTRL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(Productivity_RPGDialog,wxDialog)
    //(*EventTable(Productivity_RPGDialog)
    //*)
END_EVENT_TABLE()

Productivity_RPGDialog::Productivity_RPGDialog(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(Productivity_RPGDialog)
    wxFlexGridSizer* FlexGridSizer1;

    Create(parent, id, _("wxWidgets app"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
    FlexGridSizer1 = new wxFlexGridSizer(2, 1, 0, 0);
    Notebook1 = new wxNotebook(this, ID_NOTEBOOK1, wxDefaultPosition, wxSize(681,328), 0, _T("ID_NOTEBOOK1"));
    FlexGridSizer1->Add(Notebook1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    RichTextCtrl1 = new wxRichTextCtrl(this, ID_RICHTEXTCTRL1, _("Text"), wxDefaultPosition, wxSize(555,284), wxRE_MULTILINE, wxDefaultValidator, _T("ID_RICHTEXTCTRL1"));
    wxRichTextAttr rchtxtAttr_1;
    rchtxtAttr_1.SetBulletStyle(wxTEXT_ATTR_BULLET_STYLE_ALIGN_LEFT);
    FlexGridSizer1->Add(RichTextCtrl1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(FlexGridSizer1);
    FlexGridSizer1->Fit(this);
    FlexGridSizer1->SetSizeHints(this);

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
    //GuiLogicBridge::HpLabel = StaticText1;
    //GuiLogicBridge::NameLabel = StaticText2;
    thread t_1(bind(&Game::GameLoop, &game, 10)); //starts the game loop
}

void Productivity_RPGDialog::OnButton1Click(wxCommandEvent& event)
{
    EventChangePlayerName *e_changeName = new EventChangePlayerName(); //lol
    game.addEvent(e_changeName); //lets do it
    //do not need to destroy pointer
}
