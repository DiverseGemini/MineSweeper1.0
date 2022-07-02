#pragma once

#include"wx/wx.h"
class Maincap : public wxFrame
{
public:
	Maincap();
	~Maincap();
public:
	/*wxButton* button1 = nullptr;
	wxTextCtrl* m_txt1 = nullptr;
	wxListBox* m_list1 = nullptr;*/

	int nFieldWidth = 10;
	int nFieldHeight = 10;
	wxButton** btn;
	int* nField = nullptr;
	bool BFstart = true;

 void OnButtonClicked(wxCommandEvent& evt);
	wxDECLARE_EVENT_TABLE();
};

