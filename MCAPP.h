#pragma once

#include"wx/wx.h"
#include"Maincap.h"

class MCAPP : public wxApp
{

public:
	MCAPP();
	~MCAPP();

private:
	Maincap* m_frame1 = nullptr;
public:
	virtual bool OnInit();

};

