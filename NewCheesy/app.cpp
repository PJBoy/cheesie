
#include "main.h"

//////////////////////////////////////////////////////
//  This IMPLEMENT_APP macro tells wx to use this App class as the entry point
//    so that it knows to call your OnInit function at the start of the program.

IMPLEMENT_APP(App);

//////////////////////////////////////////////////////
//  OnInit is like the WinMain.  return true to run the message pump
//   or return false if the program is to exit immediately

bool App::OnInit()
{
	// You generally don't want a dialog for a top level window in wx.  Instead, make
	//  a normal Frame, and put a Panel inside it.  This will make it look like a dialog,
	//  but it will have an entry in the task-bar, will be resizable, etc, etc.
	//
	// Note that even though we create windows with 'new', we do not 'delete' them, because wx
	//  does that automatically when the window is closed/destroyed.
	//
	// String literals are put in wxT() to make them Unicode friendly

	wxFrame* frame = new wxFrame(   NULL,       // no parent
	wxID_ANY,   // don't care about it's ID number
	wxT("Cheesy")    // title-bar caption
	);

	// now make the panel, and have its parent be that frame

	wxBoxSizer* siz = new wxBoxSizer(wxHORIZONTAL);
	clsMenu* ourmenu = new clsMenu(frame);
	MainPanel* panel = new MainPanel( frame );
	siz->Add(panel);
	frame->SetSizerAndFit(siz);

	// Set the frame as the top window -- so that the program will exit when the
	//  frame is closed
	SetTopWindow(frame);

	// lastly, make the window visible
	frame->Show();

	// then everything's good -- return true to run the program
	return true;
}