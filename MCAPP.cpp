#include "MCAPP.h"
wxIMPLEMENT_APP(MCAPP);
MCAPP::MCAPP()
{

}

MCAPP::~MCAPP()
{
	 
}

bool MCAPP::OnInit()
{
	m_frame1 = new Maincap();
	m_frame1->Show();
	return true;

}