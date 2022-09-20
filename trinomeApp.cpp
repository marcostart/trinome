/***************************************************************
 * Name:      trinomeApp.cpp
 * Purpose:   Code for Application Class
 * Author:     ()
 * Created:   2021-12-23
 * Copyright:  ()
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "trinomeApp.h"
#include "trinomeMain.h"

IMPLEMENT_APP(trinomeApp);

bool trinomeApp::OnInit()
{
    trinomeFrame* frame = new trinomeFrame(0L, _("wxWidgets Application Template"));
    
    frame->Show();
    
    return true;
}
