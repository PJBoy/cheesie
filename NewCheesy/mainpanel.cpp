
#include "main.h"
using namespace std;
///////////////////////////////////////////////////////
//  event table to tie events to our handling functions
BEGIN_EVENT_TABLE(MainPanel,wxPanel)
    EVT_SIZE(          MainPanel::OnSize)
	//EVT_MENU(idOpen,MainPanel::HandleMenu)
END_EVENT_TABLE()


///////////////////////////////////////////////////////
//  the constructor -- called when the window is created (with 'new')
//    you must call the base class's (in this case, wxPanel) construtor to tell
//    it who the parent window is.  After that, just fill it with the controls and stuff
//    that you want

MainPanel::MainPanel(wxWindow* parent)
: wxPanel(parent)                       // call base class's ctor
{
	int i;
	

	TheGame=new SMClass("C:\\Cheesy\\Cheesy\\1metroid - Copy.smc");
	wxBoxSizer* mainbox = new wxBoxSizer(wxHORIZONTAL);     // horizontal box (list on left, rest on right)
	wxBoxSizer* rightbox = new wxBoxSizer(wxVERTICAL);      // vertical box on right (trainer on top, poke on bottom)
	//clsMenu* themenu=new clsMenu(this);
	
	
	rightbox ->Add(BuildEditingOptions());
	//  top row:  prev+next buttons (grouped in a sizer so they have same width
	wxBoxSizer* row = new wxBoxSizer(wxHORIZONTAL);
	{   // left column
		// wxBoxSizer* col = new wxBoxSizer(wxHORIZONTAL);
		//col->AddStretchSpacer();
		row ->Add(BuildMap());

		
	}
	// {   // right column
	//wxBoxSizer* col = new wxBoxSizer(wxHORIZONTAL);
	///    
	//     row ->Add(BuildTileset());

	//row->Add(col,1,wxEXPAND | wxALIGN_CENTER_VERTICAL);
	//  }
	rightbox->Add(row);
	rightbox->Add(BuildTileset());

	

	mainbox->Add(rightbox);
	
	//mainbox->Add(BuildTileset());
	//rightbox->AddSpacer(8);             // put 8 pixels of padding between trainer/poke boxes

	wxBoxSizer* finalbox = new wxBoxSizer(wxHORIZONTAL);
	finalbox->Add(mainbox,1,wxEXPAND | wxALL,8);


	SetSizer(finalbox);
	
	//mainbox->Add(new wxListBox(this,1));
	AppPath=wxGetCwd();
	int Address_Renamed=0x79938;//0x791F8;
	TheGame=new SMClass("C:\\Cheesy\\Cheesy\\metroid.smc");
	TheGame->LoadHeader(Address_Renamed);
	
	TheGame->RoomStates.resize(TheGame->LoadMDB_StateSelect(Address_Renamed + 11));
	TheGame->iRoomState = 0;
	TheGame->LoadMDB_Roomstate(TheGame->RoomStatePointers[TheGame->iRoomState], &TheGame->RoomStates[TheGame->iRoomState]);
	TheGame->GrabRoom();
	
	TheGame->GrabTileset(TheGame->RoomStates[TheGame->iRoomState].GraphicsSet);
	TheTileset->gI->Set(&TheGame->Tiles);
	TheTileset->gI->Set(&TheGame->Pal);
	TheTileset->gI->Set(&TheGame->TSA.nTSA);
	TheTileset->gI->MakeImage(NULL,NULL,0,0,32,32);
	TheTileset->Refresh();
	
	TheGame->DrawRoom(&TheMapWindow->dcPic,&TheTileset->dcPic);
	TheMapWindow->Refresh();
}

// more building (box building -- wee)

void MainPanel::HandleMenu(wxCommandEvent& event){
int shit;
shit=0;

}
/////////////////////////////////////////////








void MainPanel::OnChooseRom(wxCommandEvent& evt)
{
	/*char hdr[5];
	wxString path = wxFileSelector(wxT("Select a file to open"),wxEmptyString,wxEmptyString,wxT(".gba"),wxT("GBA ROMs|*.gba|All Files|*"));
if(path.IsEmpty()) /* User pressed Cancel *//*
	{
			wxMessageBox(wxT("No ROM was selected"));

	}
	else
	{
ThisROM.ROM = fopen(path.char_str(),"r+b");
		//This will be moved.
		/*AttackList      =0x247070;
		TrainerGroup    =0x23E534;
		ItemList        =0x3DAE64;
		PokemonNameTable=0x245EBC;
		TrainerTable    =0x23EAA4;
	TrainerPic      =0x239558;
		TrainerPal      =0x2399F8;
		PokePic         =0x235088;
		PokePal         =0x2372E8;
fseek(ThisROM.ROM,0xAC,SEEK_SET);
	fread(hdr,4,1,ThisROM.ROM);
	CompileOffsetList(hdr);

	//End move
		TextRead.LoadTable(AppPath.char_str());
		//This will be moved
		Setup();
	//This will be moved.
		GetTrainers();
	}*/
}
void MainPanel::OnSize(wxSizeEvent& event){
event.Skip();
int lol;
lol=0;

}