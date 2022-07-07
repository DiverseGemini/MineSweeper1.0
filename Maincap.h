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

	int MFieldWidth = 10;
	int MFieldHeight = 10;
	wxButton** button;
	int* MineField = nullptr;
	bool BFstart = true;

 void OnButtonClicked(wxCommandEvent& evt);
	wxDECLARE_EVENT_TABLE();
};

