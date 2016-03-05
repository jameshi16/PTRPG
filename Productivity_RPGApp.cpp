/***************************************************************
 * Name:      Productivity_RPGApp.cpp
 * Purpose:   Code for Application Class
 * Author:    James ()
 * Created:   2016-03-05
 * Copyright: James (nightsagaguild.ddns.net)
 * License:
 **************************************************************/

#include "Productivity_RPGApp.h"

//(*AppHeaders
#include "Productivity_RPGMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(Productivity_RPGApp);

bool Productivity_RPGApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	Productivity_RPGDialog Dlg(0);
    	SetTopWindow(&Dlg);
    	Dlg.ShowModal();
    	wxsOK = false;
    }
    //*)
    return wxsOK;

}
