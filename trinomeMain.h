/***************************************************************
 * Name:      trinomeMain.h
 * Purpose:   Defines Application Frame
 * Author:     ()
 * Created:   2021-12-23
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef TRINOMEMAIN_H
#define TRINOMEMAIN_H

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "trinomeApp.h"

class trinomeFrame: public wxFrame
{
    public:
        trinomeFrame(wxFrame *frame, const wxString& title);
        ~trinomeFrame();
    private:
        enum
        {
            idMenuQuit = 1000,
            idMenuAbout
        };
        void OnClose(wxCloseEvent& event);
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        DECLARE_EVENT_TABLE()
};


#endif // TRINOMEMAIN_H
