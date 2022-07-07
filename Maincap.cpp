#include "Maincap.h"


wxBEGIN_EVENT_TABLE(Maincap, wxFrame)

wxEND_EVENT_TABLE()
Maincap::Maincap() : wxFrame(nullptr, wxID_ANY, "MineSweeperLab - wxWidget", wxPoint(30, 30), wxSize(800, 600))
{
	/*button1 = new wxButton(this, 10001, "Ok", wxPoint(10, 10), wxSize(150, 50));
	m_txt1 = new wxTextCtrl(this, wxID_ANY, "", wxPoint(10, 70), wxSize(300, 30));
	m_list1 = new wxListBox(this, wxID_ANY, wxPoint(10, 110), wxSize(300, 300));*/
	button = new wxButton * [MFieldWidth * MFieldHeight];
	wxGridSizer* grid = new wxGridSizer(MFieldWidth, MFieldHeight, 0, 0);
	MineField = new int[MFieldWidth * MFieldHeight];
	for (int x = 0; x < MFieldWidth; x++)
	{
		for (int y = 0; y < MFieldHeight; y++)
		{
			button[y * MFieldWidth + x] = new wxButton(this, 10000 + (y * MFieldWidth + x));


			grid->Add(button[y * MFieldWidth + x], 1, wxEXPAND | wxALL);

			button[y * MFieldWidth + x]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &Maincap::OnButtonClicked, this);

			MineField[y * MFieldWidth + x] = 0;

		}
	}
	this->SetSizer(grid);
	grid->Layout();
}
Maincap::~Maincap()
{
	delete[] button;
}

//field mine
void Maincap::OnButtonClicked(wxCommandEvent& evt)
{
	int x = (evt.GetId() - 10000) % MFieldWidth;
	int y = (evt.GetId() - 10000) / MFieldWidth;
	if (BFstart)
	{
		int Fmines = 40;
		while (Fmines)
		{
			int rx = rand() % MFieldWidth;
			int ry = rand() % MFieldHeight;

			if (MineField[ry * MFieldWidth + rx] == 0 && rx != x && ry != y)
			{

				MineField[ry * MFieldWidth + rx] = -1;
				Fmines--;
			}
		}
		BFstart = false;
	}

	button[y * MFieldWidth + x]->Enable(false);

	if (MineField[y * MFieldWidth + x] == -1)
	{
		wxMessageBox("WOW!!! You lost imma need you to sign off - GAME OVER");
		BFstart = true;
		for (int x = 0; x < MFieldWidth; x++)
			for (int y = 0; y < MFieldHeight; y++)
			{
				MineField[y * MFieldWidth + x] = 0;
				button[y * MFieldWidth + x]->SetLabel("");
				button[y * MFieldWidth + x]->Enable(true);
			}
	}
	else
	{
		//COUNT Neighbor mines
		int mCounter = 0;
		for (int i = -1; i < 2; i++)
			for (int c = -1; c < 2; c++)
			{

				if (x + i >= 0 && x + i < MFieldWidth && y + c >= 0 && y + c < MFieldHeight)
				{
 					if (MineField[(y + c) * MFieldWidth + (x + i)] == -1)
					{
						mCounter++;
					}
				}

			}

		if (mCounter > 0)
		{
			button[y * MFieldWidth + x]->SetLabel(std::to_string(mCounter));
		}
	}
	evt.Skip();
}
