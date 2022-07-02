#include "Maincap.h"


wxBEGIN_EVENT_TABLE(Maincap, wxFrame)

wxEND_EVENT_TABLE()
Maincap::Maincap() : wxFrame(nullptr, wxID_ANY, "MineSweeperLab - wxWidget", wxPoint(30, 30), wxSize(800, 600))
{
	/*button1 = new wxButton(this, 10001, "Ok", wxPoint(10, 10), wxSize(150, 50));
	m_txt1 = new wxTextCtrl(this, wxID_ANY, "", wxPoint(10, 70), wxSize(300, 30));
	m_list1 = new wxListBox(this, wxID_ANY, wxPoint(10, 110), wxSize(300, 300));*/
	btn = new wxButton * [nFieldWidth * nFieldHeight];
	wxGridSizer* grid = new wxGridSizer(nFieldWidth, nFieldHeight, 0, 0);
	nField = new int[nFieldWidth * nFieldHeight];
	for (int x = 0; x < nFieldWidth; x++)
	{
		for (int y = 0; y < nFieldHeight; y++)
		{
			btn[y * nFieldWidth + x] = new wxButton(this, 10000 + (y * nFieldWidth + x));


			grid->Add(btn[y * nFieldWidth + x], 1, wxEXPAND || wxALL);

			btn[y * nFieldWidth + x]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &Maincap::OnButtonClicked, this);

			nField[y * nFieldWidth + x] = 0;

		}
	}
	this->SetSizer(grid);
	grid->Layout();
}
Maincap::~Maincap()
{
	delete[] btn;
}

void Maincap::OnButtonClicked(wxCommandEvent& evt)
{
	int x = (evt.GetId() - 10000) % nFieldWidth;
	int y = (evt.GetId() - 10000) / nFieldWidth;
	if (BFstart)
	{
		int Fmines = 40;
		while (Fmines)
		{
			int rx = rand() % nFieldWidth;
			int ry = rand() % nFieldHeight;

			if (nField[ry * nFieldWidth + rx] == 0 && rx != x && ry != y)
			{

				nField[ry * nFieldWidth + rx] = -1;
				Fmines--;
			}
		}
		BFstart = false;
	}

	btn[y * nFieldWidth + x]->Enable(false);

	if (nField[y * nFieldWidth + x] == -1)
	{
		wxMessageBox("WOW!!! You Lost Imma need you to sign of - GAME OVER");
		BFstart = true;
		for (int x = 0; x < nFieldWidth; x++)
			for (int y = 0; y < nFieldHeight; y++)
			{
				nField[y * nFieldWidth + x] = 0;
				btn[y * nFieldWidth + x]->SetLabel("");
				btn[y * nFieldWidth + x]->Enable(true);
			}
	}
	else
	{
		//COUNT Neighbor mines
		int mCounter = 0;
		for (int i = -1; i < 2; i++)
			for (int c = -1; c < 2; c++)
			{

				if (x + i >= 0 && x + i < nFieldWidth && y + c >= 0 && y + c < nFieldHeight)
				{
					if (nField[(y + c) * nFieldWidth + (x + i)] == -1)
					{
						mCounter++;
					}
				}

			}

		if (mCounter > 0)
		{
			btn[y * nFieldWidth + x]->SetLabel(std::to_string(mCounter));
		}
	}
	evt.Skip();
}
