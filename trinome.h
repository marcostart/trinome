#ifndef PTOTOTY_H_INCLUDED
#define PTOTOTY_H_INCLUDED
#ifndef PROTOTYPAGE_H_INCLUDED
#define PROTOTYPAGE_H_INCLUDED

#include <wx/textdlg.h>
#include <wx/numdlg.h>
#include <wx/choicdlg.h>
#include <ctype.h>
#include <cmath>
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#ifndef TRINOME_H
#define TRINOME_H
#include <wx/app.h>
#include <wx/radiobox.h>

class MyApp : public wxApp
{
    public:
	    virtual bool OnInit();
};
DECLARE_APP(MyApp) ;
#endif
class Trinome
{
    public:
        bool calcRacine(double& a,double& b,double& c);
        void accesCoef(double& ,double& ,double& );
        void accesRac(double tab[2]);
    private:
        double a,b,c,racine1,racine2;
};
class EcranRacine : public wxFrame
{
    public:
        EcranRacine();
        virtual bool Validate(double coefficient[]);
    private:
        wxStaticText *coef1;
        wxStaticText *coef2;
        wxTextCtrl *text1;
        wxTextCtrl *text2;
        wxTextCtrl *text3;
        wxTextCtrl *text4;
        wxTextCtrl *text5;
        wxRadioBox *radio;
        void OnExit(wxCommandEvent& event);
        void OnClickCalcul(wxCommandEvent& event);
        //wxDECLARE_EVENT_TABLE()

};
enum
{
    ID_Exit=1,
    ID_Validate,
    ID_Text1,
    ID_Text2,
    ID_Text3,
    ID_Text4,
    ID_Text5
};

#endif

#endif