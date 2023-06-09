#include "gameImage.h"
#include <wx/dcmemory.h>
#ifndef __TRAINERPIC_H__       // include protection -- prevents the same file
#define __TRAINERPIC_H__       //    from being included multiple times

class  PicWindow: public  wxWindow
{
	enum{
		HORIZSB,
		VERTSB
	};
public:
	// constructor
	//wxBitmap bmpTrainer;
	wxScrollBar* HSB;
	wxScrollBar* VSB;
	wxMemoryDC dcPic;
	gameImages*  gI;
	wxRect* recSel;
	wxRect* rect;
	int Height;
	int Width;
	int rButton;
	int lButton;
	wxScrolledWindow *sw;
	PicWindow(wxWindow* parent, int iWidth, int iHeight)   // just have it call the wxWindow ctor
	: wxWindow(parent,wxID_ANY,wxDefaultPosition,wxSize(iWidth,iHeight ))
	{
		recSel=new wxRect(0,0,16,16);

		gI=new gameImages(&dcPic);
		Height=iHeight;
		Width=iWidth;
		dcPic.SelectObjectAsSource( wxBitmap(512,512,32));
	}
	void onLeftDown(wxMouseEvent &event);
	void onLeftUp(wxMouseEvent &event);
	void onLeftClick(wxMouseEvent &event);
	void onLeftDClick(wxMouseEvent &event);
    
	void onMove(wxMouseEvent &event);

	void onRightDown(wxMouseEvent &event);
	void onRightUp(wxMouseEvent &event);
	void onRightClick(wxMouseEvent &event);
	void onRightDClick(wxMouseEvent &event);
	void Erase(wxEraseEvent& evt);
	void MakeHSB();
	void MakeVSB();
	void ScrollStuff(wxScrollEvent& event);
private:
	DECLARE_EVENT_TABLE();
protected:
	void Paint(wxPaintEvent& evt);


};

#endif // __MAINPANEL_H__