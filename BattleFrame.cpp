#include "BattleFrame.h"

//(*InternalHeaders(BattleFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(BattleFrame)
const long BattleFrame::ID_STATICBITMAP1 = wxNewId();
const long BattleFrame::ID_STATICBITMAP2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(BattleFrame,wxFrame)
	//(*EventTable(BattleFrame)
	//*)
END_EVENT_TABLE()

BattleFrame::BattleFrame(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(BattleFrame)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
	SetClientSize(wxSize(1075,653));
	Move(wxDefaultPosition);
	Player = new wxStaticBitmap(this, ID_STATICBITMAP1, wxNullBitmap, wxPoint(464,504), wxSize(112,112), wxSIMPLE_BORDER, _T("ID_STATICBITMAP1"));
	Enemy = new wxStaticBitmap(this, ID_STATICBITMAP2, wxNullBitmap, wxPoint(464,16), wxSize(112,112), wxSIMPLE_BORDER, _T("ID_STATICBITMAP2"));
	//*)
}

BattleFrame::~BattleFrame()
{
	//(*Destroy(BattleFrame)
	//*)
}

