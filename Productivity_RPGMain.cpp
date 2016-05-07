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
const long Productivity_RPGDialog::ID_STATICBITMAP1 = wxNewId();
const long Productivity_RPGDialog::ID_STATICTEXT2 = wxNewId();
const long Productivity_RPGDialog::ID_STATICTEXT4 = wxNewId();
const long Productivity_RPGDialog::ID_STATICTEXT3 = wxNewId();
const long Productivity_RPGDialog::ID_STATICTEXT6 = wxNewId();
const long Productivity_RPGDialog::ID_STATICTEXT5 = wxNewId();
const long Productivity_RPGDialog::ID_STATICTEXT7 = wxNewId();
const long Productivity_RPGDialog::ID_PANEL2 = wxNewId();
const long Productivity_RPGDialog::ID_STATICTEXT8 = wxNewId();
const long Productivity_RPGDialog::ID_PANEL1 = wxNewId();
const long Productivity_RPGDialog::ID_NOTEBOOK1 = wxNewId();
const long Productivity_RPGDialog::ID_STATICTEXT1 = wxNewId();
const long Productivity_RPGDialog::ID_RICHTEXTCTRL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(Productivity_RPGDialog,wxDialog)
    //(*EventTable(Productivity_RPGDialog)
    //*)
END_EVENT_TABLE()

Productivity_RPGDialog::Productivity_RPGDialog(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(Productivity_RPGDialog)
    wxFlexGridSizer* FlexGridSizer3;
    wxFlexGridSizer* FlexGridSizer2;
    wxFlexGridSizer* FlexGridSizer1;

    Create(parent, wxID_ANY, _("wxWidgets app"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
    FlexGridSizer1 = new wxFlexGridSizer(3, 1, 0, 0);
    Notebook1 = new wxNotebook(this, ID_NOTEBOOK1, wxDefaultPosition, wxSize(681,328), 0, _T("ID_NOTEBOOK1"));
    Panel1 = new wxPanel(Notebook1, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    FlexGridSizer2 = new wxFlexGridSizer(2, 2, 0, 0);
    playerImage = new wxStaticBitmap(Panel1, ID_STATICBITMAP1, wxNullBitmap, wxDefaultPosition, wxSize(268,254), wxSIMPLE_BORDER, _T("ID_STATICBITMAP1"));
    FlexGridSizer2->Add(playerImage, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel2 = new wxPanel(Panel1, ID_PANEL2, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    FlexGridSizer3 = new wxFlexGridSizer(3, 2, 0, 0);
    StaticText1 = new wxStaticText(Panel2, ID_STATICTEXT2, _("Health Points:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    FlexGridSizer3->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    hpLabel = new wxStaticText(Panel2, ID_STATICTEXT4, _("<hp>"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    FlexGridSizer3->Add(hpLabel, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText2 = new wxStaticText(Panel2, ID_STATICTEXT3, _("nothing"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    FlexGridSizer3->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText5 = new wxStaticText(Panel2, ID_STATICTEXT6, _("nothing"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
    FlexGridSizer3->Add(StaticText5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText4 = new wxStaticText(Panel2, ID_STATICTEXT5, _("nothing"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    FlexGridSizer3->Add(StaticText4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText6 = new wxStaticText(Panel2, ID_STATICTEXT7, _("nothing"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
    FlexGridSizer3->Add(StaticText6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel2->SetSizer(FlexGridSizer3);
    FlexGridSizer3->Fit(Panel2);
    FlexGridSizer3->SetSizeHints(Panel2);
    FlexGridSizer2->Add(Panel2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    playerNameLabel = new wxStaticText(Panel1, ID_STATICTEXT8, _("<player>"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT8"));
    FlexGridSizer2->Add(playerNameLabel, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel1->SetSizer(FlexGridSizer2);
    FlexGridSizer2->Fit(Panel1);
    FlexGridSizer2->SetSizeHints(Panel1);
    Notebook1->AddPage(Panel1, _("Player Profile"), false);
    FlexGridSizer1->Add(Notebook1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    ConstText1 = new wxStaticText(this, ID_STATICTEXT1, _("Log"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    FlexGridSizer1->Add(ConstText1, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    RichTextCtrl1 = new wxRichTextCtrl(this, ID_RICHTEXTCTRL1, wxEmptyString, wxDefaultPosition, wxSize(677,231), wxRE_MULTILINE, wxDefaultValidator, _T("ID_RICHTEXTCTRL1"));
    wxRichTextAttr rchtxtAttr_1;
    rchtxtAttr_1.SetBulletStyle(wxTEXT_ATTR_BULLET_STYLE_ALIGN_LEFT);
    FlexGridSizer1->Add(RichTextCtrl1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(FlexGridSizer1);
    FlexGridSizer1->Fit(this);
    FlexGridSizer1->SetSizeHints(this);

    Connect(wxID_ANY,wxEVT_INIT_DIALOG,(wxObjectEventFunction)&Productivity_RPGDialog::OnInit);
    Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&Productivity_RPGDialog::OnClose);
    //*)
}

Productivity_RPGDialog::~Productivity_RPGDialog()
{
    //(*Destroy(Productivity_RPGDialog)
    //*)
}
void Productivity_RPGDialog::OnInit(wxInitDialogEvent& event)
{
    using namespace boost;
    GuiLogicBridge::HpLabel = hpLabel;
    GuiLogicBridge::NameLabel = playerNameLabel;

    //Need a proper loader for this//
    ScriptManager sm;
    sm.loadScripts(sm.aquireAllFiles());

    thread *t_1 = new thread(bind(&Game::GameLoop, &game, 10)); //starts the game loop
    theGameThread = t_1; //sets the thread
}

void Productivity_RPGDialog::OnClose(wxCloseEvent& event)
{
    game.StopGameLoop();
    if (theGameThread->joinable())
        theGameThread->join();

    delete theGameThread;

    Close();
}
