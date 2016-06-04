#ifndef BATTLEFRAME_H
#define BATTLEFRAME_H

//(*Headers(BattleFrame)
#include <wx/frame.h>
//*)

class BattleFrame: public wxFrame
{
	public:

		BattleFrame(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~BattleFrame();

		//(*Declarations(BattleFrame)
		//*)

	protected:

		//(*Identifiers(BattleFrame)
		//*)

	private:

		//(*Handlers(BattleFrame)
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
