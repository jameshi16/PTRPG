#ifndef BATTLEFRAME_H
#define BATTLEFRAME_H

//(*Headers(BattleFrame)
#include <wx/statbmp.h>
#include <wx/frame.h>
//*)

class BattleFrame: public wxFrame
{
	public:

		BattleFrame(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~BattleFrame();

		//(*Declarations(BattleFrame)
		wxStaticBitmap* Enemy;
		wxStaticBitmap* Player;
		//*)

	protected:

		//(*Identifiers(BattleFrame)
		static const long ID_STATICBITMAP1;
		static const long ID_STATICBITMAP2;
		//*)

	private:

		//(*Handlers(BattleFrame)
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
