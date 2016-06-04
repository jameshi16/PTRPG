#include "BattleFrame.h"

//(*InternalHeaders(BattleFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(BattleFrame)
//*)

BEGIN_EVENT_TABLE(BattleFrame,wxFrame)
	//(*EventTable(BattleFrame)
	//*)
END_EVENT_TABLE()

BattleFrame::BattleFrame(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(BattleFrame)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
	SetClientSize(wxSize(1075,617));
	Move(wxDefaultPosition);
	//*)
}

BattleFrame::~BattleFrame()
{
	//(*Destroy(BattleFrame)
	//*)
}

