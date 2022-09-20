#include "trinome.h"
#include <wx/textdlg.h>
#include <wx/numdlg.h>
#include <wx/choicdlg.h>
#include <ctype.h>
#include <cmath>
#include <wx/wxprec.h>
#include <wx/radiobox.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>

#endif
#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__
wxIMPLEMENT_APP(MyApp);
bool MyApp::OnInit()
{
    EcranRacine *ecran=new EcranRacine();
    //ecran->SetSize(wxSize (500,450));
	ecran->Show(true);
	return true;
}
EcranRacine::EcranRacine() 
: wxFrame(NULL, -1,_("Calcul des racines d'un trinome"), wxDefaultPosition, wxSize(500,450), wxSYSTEM_MENU | wxCAPTION | wxCLOSE_BOX | wxCLIP_CHILDREN)
{
    
    wxBoxSizer *sizer1=new wxBoxSizer(wxVERTICAL);
    wxPanel *zone1 = new wxPanel(this);
    wxButton *exitButton= new wxButton(zone1,ID_Exit,_("&Quitter.."),wxDefaultPosition,wxDefaultSize,0);
    wxButton *validateButton= new wxButton(zone1,ID_Validate,_("&Calculer les racines"),wxDefaultPosition,wxDefaultSize,0);
    wxBoxSizer *sizerInter =new wxBoxSizer(wxVERTICAL);
    wxStaticBoxSizer *sizer2=new wxStaticBoxSizer(wxVERTICAL,zone1,_("&Definition d'un trinome ax2+bx+c"));
    
    coef1= new wxStaticText(this,wxID_ANY,_("&coefficient a :"));
    coef2= new wxStaticText(this,wxID_ANY,_("&coefficient b :"));
    text1=new wxTextCtrl(this,ID_Text1,"0");
    text2=new wxTextCtrl(this,ID_Text2,"0");
    text3=new wxTextCtrl(this,ID_Text3,"0");
    wxBoxSizer *sizer3=new wxBoxSizer(wxHORIZONTAL);
    sizer3->Add(coef1,1,wxLEFT | wxEXPAND ,50);
    sizer3->Add(text1,1,wxRIGHT | wxEXPAND ,50);
    sizer2->Add(sizer3,1,wxALL | wxEXPAND ,5);
    
    wxBoxSizer *sizer4=new wxBoxSizer(wxHORIZONTAL);
    sizer4->Add(coef2,1,wxLEFT | wxEXPAND ,50);
    sizer4->Add(text2,1,wxRIGHT | wxEXPAND ,50);
    sizer2->Add(sizer4,1,wxALL | wxEXPAND ,5);
    
    wxBoxSizer *sizer5=new wxBoxSizer(wxHORIZONTAL);
    sizer5->Add(new wxStaticText(this,wxID_ANY,_("&coefficient c :")),1,wxLEFT | wxEXPAND ,50);
    sizer5->Add(text3,1,wxRIGHT | wxEXPAND ,50);
    sizer2->Add(sizer5,1,wxALL | wxEXPAND ,5);
    
    wxStaticBoxSizer *sizer6=new wxStaticBoxSizer(wxVERTICAL,zone1,_("&Racines obtenues apres calcul "));
    wxBoxSizer *sizer7=new wxBoxSizer(wxHORIZONTAL);
    text4=new wxTextCtrl(this,ID_Text4,"");
    sizer7->Add(new wxStaticText(this,wxID_ANY,_("&Racine 1 :")),1,wxLEFT | wxEXPAND ,50);
    sizer7->Add(text4,1,wxRIGHT | wxEXPAND ,50);
    sizer6->Add(sizer7,1,wxALL | wxEXPAND ,5);
    
    wxBoxSizer *sizer8=new wxBoxSizer(wxHORIZONTAL);
    text5=new wxTextCtrl(this,ID_Text5,"");
    sizer8->Add(new wxStaticText(this,wxID_ANY,_("&Racine 2 :")),1,wxLEFT | wxEXPAND ,50);
    sizer8->Add(text5,1,wxRIGHT | wxEXPAND ,50);
    sizer6->Add(sizer8,1,wxALL | wxEXPAND ,5);
    
    wxBoxSizer *lastButton=new wxBoxSizer(wxHORIZONTAL);
    lastButton->Add(exitButton,1,wxALL|wxALIGN_CENTER_VERTICAL,10);
    wxArrayString choix;
    
    choix.Add(_T("&Dans R"));
    choix.Add(_T("&Dans C"));
    radio= new wxRadioBox(this,-1,_(""),wxDefaultPosition,wxDefaultSize,choix,1);
    lastButton->Add(radio,1,wxALL | wxALIGN_CENTER_VERTICAL,10);
    lastButton->Add(validateButton,1,wxALL|wxALIGN_CENTER_VERTICAL,10);
    sizerInter->Add(sizer2, 1, wxALL|wxEXPAND, 10);
    sizerInter->Add(sizer6, 1, wxALL|wxEXPAND, 10);
    sizerInter->Add(lastButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL, 10);
    zone1->SetSizer(sizerInter);
    sizer1->Add(zone1,1, wxALL | wxEXPAND, 0);
    SetSizer(sizer1);
    exitButton->Bind(wxEVT_BUTTON, &EcranRacine::OnExit,this,ID_Exit);
    validateButton->Bind(wxEVT_BUTTON, &EcranRacine::OnClickCalcul,this,ID_Validate);
    text1->SetValidator(wxTextValidator(wxFILTER_NUMERIC)) ;
}
void EcranRacine::OnExit(wxCommandEvent& event)
{
    Destroy();
}
bool EcranRacine::Validate(double coefficient[])
{
    bool ret;
    ret= wxFrame::Validate();
    if (ret)
    {
        wxString tmp1,tmp2,tmp3;
        tmp1=text1->GetValue();
        tmp2=text2->GetValue();
        tmp3=text3->GetValue();
        if (tmp1.IsEmpty() || tmp2.IsEmpty() || tmp3.IsEmpty())
        {
            wxMessageBox(wxString::Format("Veuiller remplir tous les champs !"),"ERREURE",wxOK | wxICON_ERROR,this);
            ret=false;
        }
        unsigned long int m=0,t1=0,t2=0,t3=0;
        
        for (m=0;m<tmp1.size();m++)
        {
            if (!isdigit(tmp1[m]))
                t1++;   
        }
        for (m=0;m<tmp2.size();m++)
        {
            if (!isdigit(tmp2[m]))
                t2++;
        }
        for (m=0;m<tmp3.size();m++)
        {
            if (!isdigit(tmp3[m]))
                t3++;
        }

        if (t1!=0 || t2!=0 || t3!=0)
        {
            wxMessageBox(wxString::Format("Veuiller saisir des entiers dans tous les champs !"),"ERREURE",wxOK | wxICON_ERROR,this);
            ret=false;
        }
        else
        {
            coefficient[0]=wxAtof(tmp1);
            coefficient[1]=wxAtof(tmp2);
            coefficient[2]=wxAtof(tmp3);
        }
    }
    return ret;
}
void EcranRacine::OnClickCalcul(wxCommandEvent& event)
{
    double coefficient[3]={0,0,0};
    bool verify=this->Validate(coefficient);
    double resultat=0.0;
    wxString texte;
    wxString choix1=_T("Dans R");
    wxString choix2=_T("Dans C");
    if (verify)
    {
        if (coefficient[0]==0)
        {
            if (coefficient[1]==0)
            {
                if (coefficient[2]==0)
                {
                    wxMessageBox(wxString::Format("Erreur\n""\n""Tout les coefficients sont nuls\n""Entrer des coefficients non nuls"),
                "L'ensemble des solutions est l'ensemble de depart",wxOK | wxICON_ERROR);
                    text4->SetValue("");
                    text5->SetValue("");
                }  
                else
                {
                    wxMessageBox(wxString::Format("Modifier vos coefficients !."),
                "ERREURE EQUATION IMPOSSIBLE",wxOK | wxICON_ERROR);
                     text4->SetValue("");
                    text5->SetValue("");
                }  
            }
            else
            {
                wxMessageBox(wxString::Format("SOLUTION UNIQUE."),
                "A votre attention",wxOK | wxICON_INFORMATION);
                resultat=-(coefficient[2]/coefficient[1]);
                texte.Printf("%f",resultat);
                text4->SetValue(texte);
                text5->SetValue(texte);
            }
        }
        else
        {
            double det=coefficient[1]*coefficient[1]-4*coefficient[0]*coefficient[2];
            if (det==0)
            {
                resultat=-(coefficient[1]/(2*coefficient[0]));
                wxMessageBox(wxString::Format("SOLUTION DOUBLE."),
                "A votre attention",wxOK | wxICON_INFORMATION);
                texte.Printf("%f",-(coefficient[1]/(2*coefficient[0])));
                text4->SetValue(texte);
                text5->SetValue(texte);
            }
            else if (det>0)
            {
                double tab[2]={0,0};
                tab[0]=(-coefficient[1]-sqrt(det))/(2*coefficient[0]);
                tab[1]=(-coefficient[1]+sqrt(det))/(2*coefficient[0]);
                texte.Printf("%f",tab[0]);
                text4->SetValue(texte);
                texte.Printf("%f",tab[1]);
                text5->SetValue(texte);
            }
            else if (det<0 && radio->GetStringSelection()==choix1)
            {
                wxMessageBox(wxString::Format("Cette equation n'admet aucune solution dans R."),
                "EQUATION SANS SOLUTION",wxOK | wxICON_INFORMATION);
                text4->SetValue("");
                text5->SetValue("");
            }
            else
            {
                texte.Printf("-%f - %fi",coefficient[1]/(2*coefficient[0]),sqrt(-1*det)/(2*coefficient[0]));
                text4->SetValue(texte);
                texte.Printf("-%f + %fi",coefficient[1]/(2*coefficient[0]),sqrt(-1*det)/(2*coefficient[0]));
                text5->SetValue(texte);
            }
        }
    }
}