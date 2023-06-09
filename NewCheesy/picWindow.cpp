
#include "main.h"
#include "ScrollBar.h"
///////////////////////////////////////////////////////
//  event table to tie events to our handling functions
BEGIN_EVENT_TABLE(PicWindow,wxWindow)
EVT_ERASE_BACKGROUND(PicWindow::Erase)
//EVT_LEFT_DOWN(PicWindow::LeftClick) 
EVT_PAINT    (PicWindow::Paint)
EVT_SCROLL(PicWindow::ScrollStuff)
EVT_LEFT_DOWN(PicWindow::onLeftDown) 
EVT_LEFT_UP(PicWindow::onLeftUp) 

EVT_MOTION(PicWindow::onMove)

EVT_LEFT_DCLICK(PicWindow::onLeftDClick) 

EVT_RIGHT_DOWN(PicWindow::onRightDown) 
EVT_RIGHT_UP(PicWindow::onRightUp) 

EVT_RIGHT_DCLICK(PicWindow::onRightDClick) 
END_EVENT_TABLE()



///////////////////////////////////////////////////////
//  the constructor -- called when the window is created (with 'new')
//    you must call the base class's (in this case, wxPanel) construtor to tell
//    it who the parent window is.  After that, just fill it with the controls and stuff
//    that you want

void PicWindow::MakeVSB(){
	wxPoint tmp;
	tmp.x=512;
	tmp.y=0;
	wxSize sz=wxDefaultSize;
	sz.SetHeight(Height);
	VSB=new wxScrollBar(this, VERTSB,tmp,sz,wxVERTICAL);

}
void PicWindow::MakeHSB(){
	wxPoint tmp;
	tmp.x=0;
	tmp.y=256;
	wxSize sz=wxDefaultSize;
	sz.SetWidth(Width);
	HSB=new wxScrollBar(this, HORIZSB,tmp,sz,wxHORIZONTAL);

}
void PicWindow::Erase(wxEraseEvent& evt){

}
void PicWindow::Paint(wxPaintEvent& evt)
{
	int x=0;
	int y=0;
	
	
	wxPaintDC dc(this);
	if(VSB) y=VSB->GetThumbPosition()*32;
	dc.Blit(0,0,Width-16,Height,&dcPic,x,y);//
	//I like red brushes/
	wxColor thingie(255,0,0);
	//thingie.SetRGBA(0xFFFFFFFF);
	
	dc.SetBrush(*wxTRANSPARENT_BRUSH); 
	dc.SetPen( wxPen( thingie, 3 ) );
	dc.DrawRectangle(recSel->GetLeft(),recSel->GetTop(),recSel->GetRight(), recSel->GetBottom());

}
void PicWindow::ScrollStuff(wxScrollEvent& event){
	event.Skip();
	this->Refresh();
}
//	void PicWindow::LeftClick(wxMouseEvent &event){

//}
void PicWindow::onLeftDown(wxMouseEvent &event){
	int X=event.GetX()/16;
	int Y=event.GetY()/16;
	X=X;
}
void PicWindow::onMove(wxMouseEvent &event){
//Modify rect
	//refresh window
	recSel->SetLeft(event.GetX());
	recSel->SetTop(event.GetY());
	recSel->SetRight(16);
	recSel->SetBottom(16);
	//if shit for dragging
	Refresh();
}
void PicWindow::onLeftUp(wxMouseEvent &event){}
void PicWindow::onLeftClick(wxMouseEvent &event){}
void PicWindow::onLeftDClick(wxMouseEvent &event){}

void PicWindow::onRightDown(wxMouseEvent &event){}
void PicWindow::onRightUp(wxMouseEvent &event){}
void PicWindow::onRightClick(wxMouseEvent &event){}
void PicWindow::onRightDClick(wxMouseEvent &event){}