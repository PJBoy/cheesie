#include "main.h"
#include <vector>
#include "SMClass.h"
#include "gbatypes.h"
using namespace std;
long RomClass::FindFreeSpace(long bNo, u8 bConst)
{ // bNo is how many bytes, bConst is what
	// value to look for 

	// returns offset of "free space" block
	// or -1 if no such block found


	if (!ROM)
	return -1;

	bNo += 0x100; // Look for an extra free 256 bytes. -- still not sure what
	// this does,
	// but whatever

	int             ch;
	long            runstart = -1;
	long            runcount = 0;

	fseek(ROM, 0, SEEK_SET);
checkagain:
	while (1)
	{
		ch = fgetc(ROM); // get character (byte)

		if (ch == EOF) // if end of ROM

		{
			runstart = -1; // eof reached before we found block

			break;

		}
		if ((u8) ch == bConst)
		{
			if (!runcount) // start of run

			runstart = (long) ftell(ROM) - 1;

			++runcount;
			if (runcount >= bNo) // block found

			break;
		} else
		{
			runstart = -1;
			runcount = 0;
		}

	}
	if (runstart == -1)
	{
		fseek(ROM, 0, SEEK_SET);

		goto checkagain;
	}
	if (runstart != 1)
	while (runstart % 4)
	runstart++;
	return runstart;
}

void RomClass::DecodePal(short *palGBA, COLOR* palPC, int numpals, char palpos)
{

	int             i, ii, s = 0;
	long            index = 0;

	for (ii = 0; ii < numpals; ii++)
	{
		index = 0x10 * ii;

		for (i = 0; i < 16; i++)
		{

			palPC[index + i].r = ((palGBA[index + i] & 0x1F) << 3);
			palPC[index + i].g = ((palGBA[index + i] >> 5) & 0x1F) << 3;
			palPC[index + i].b = (((palGBA[index + i] >> 10) & 0x1f) << 3);
			palPC[index + i].a=255;
		}
	}
	return;
}



int RomClass::DrawPic(wxMemoryDC* wxDC, u32 GFX, u32 PAL){
	GBAImage  img;
	GBATiles	tiles;

	int i=0;
	/*
u32 offset=0;
u8 tilebuffer[0x20000]={0};
u8 buffer[0x20000]={0};
short funkehpal[512]={0};
short gbapal[512]={0};
COLOR pcpal[512]={0};

//GET GFX
fseek(ROM,GFX,SEEK_SET);
fread(&offset,1,4,ROM);
if(offset-0x8000000 <0) return 0;
fseek(ROM,offset-0x8000000,SEEK_SET);
fread(buffer,1,0x20000,ROM);
curtrainergfxsz= LZ77UnComp(buffer, tilebuffer);
//GET PALETTE
fseek(ROM,PAL,SEEK_SET);
fread(&offset,1,4,ROM);
if(offset-0x8000000 <0) return 0;
fseek(ROM,offset-0x8000000,SEEK_SET);
fread(buffer,1,512,ROM);
curtrainerpalsz= LZ77UnComp((u8*)buffer, (u8*)gbapal);
//psize = LZ77UnComp(inbuffer, palbuff)



DecodePal(gbapal, pcpal, 16, 0);


tiles.Load(tilebuffer,64);
img.Create(64,64);
for( i= 0; i<64;i++)
	{
img.DrawTile(tiles[i],(i%8)*8,(i/8)*8,0,0);
}
img.SetPalette(pcpal,0,16); 
	img.BlitToDC(wxDC,0,0,64,64,0,0);
	*/
	return 0;
}
RomClass::RomClass(){

}
RomClass::~RomClass(){
}


//==================================================================================
// Palette
// ==================================================================================


/*
FILE* fp; //= fopen(this->FileName,"r+b");
if(fp){
	//fseek(fp,offset,SEEK_SET);
	// fread(buffer,1024,1,fp);
	size =  this->Decompress(offset, buffer);
	*/
/*
void* RomClass::DecodeSNESPal(long offset, long* dstPal, int numPals, char palpos, int size, vector<u8>* buffer){

int             R, g, b, i, ii, s = 0;
long            index = 0;
u16              palGBA[512];


u32 red = 0x1F;
u32 green = 0x1F << 5;
u32 blue = 0x1F << 10;

numPals=size/32;
	numPals-=palpos;
	memcpy(&palGBA[palpos*0x10], buffer, size);


	for (ii = palpos; ii < numPals; ii++)
	{
		index = 0x10 * ii;

		for (i = 0; i < 16; i++)
		{

			R = ( ( ( palGBA[index + i] ) >>  0 ) << 3 ) & 0xF8;
	g = ( ( ( palGBA[index + i] ) >>  5 ) << 3 ) & 0xF8;
	b = ( ( ( palGBA[index + i] ) >> 10 ) << 3 ) & 0xF8;


	dstPal[index + i] = RGB(R, g, b);
			
		}
	}

return 0;
}*/
void* RomClass::DecodeSNESPal(long offset, COLOR* dstPal, int numPals, char palpos, int size, vector<u8>* buffer){

	int             R, g, b, i, ii, s = 0;
	long            index = 0;
	u16             palGBA[512];

	//populate above array very shittly
	u32 red = 0x1F;
	u32 green = 0x1F << 5;
	u32 blue = 0x1F << 10;


	numPals=size/32;
	numPals-=palpos;
	//memcpy(&palGBA[palpos*0x10], buffer, size);
	int count;
	for(i=0;i<buffer->size()/2;i++){
		memcpy(&palGBA[i], &buffer->front()+(i*2),2);
	}


	for (ii = palpos; ii < numPals; ii++)
	{
		index = 0x10 * ii;

		for (i = 0; i < 16; i++)
		{
			
			dstPal[index + i].r =  ( ( ( palGBA[index + i] ) >>  0 ) << 3 ) & 0xF8;
			dstPal[index + i].g =  ( ( ( palGBA[index + i] ) >>  5 ) << 3 ) & 0xF8;
			dstPal[index + i].b =  ( ( ( palGBA[index + i] ) >> 10 ) << 3 ) & 0xF8;
			
			dstPal[index + i].a=255;

			
			
		}
	}

	return 0;
}

/*
* long RomClass::ZMUncompRle(u8* cmp, u8* uncmp, long size, int LoopSeq ){
* char nm=0;
* char buf[100];
* long src , tgt, sze, i,j;
* 
* u8 rlebyte, data,Mode;
* 
* src = 0;
* 
* tgt = 0;
* 
* 
* for( j = 0; j <  2;j++){
* // sprintf(buf,"compressed offset is: %x",src);
* // sMessage(buf);
* Mode = cmp[src++];
* 
* if (Mode == 1){
* rlebyte = cmp[src++];
* 
* while (rlebyte > 0){
* if(tgt == size) return  src - 1;
* sze = rlebyte & 0x7F;
* if (rlebyte & 0x80){
* data = cmp[src++];
* 
* for(i = -1;i<sze;i++){
* //if(tgt == size*2) return  src - 1;
* uncmp[tgt] = data;
* tgt = tgt + (LoopSeq == 1? 2:1);
* }
* }else{
* for(i = 0;i<sze;i++){
* //if(tgt == size*2) return  src - 1;
* data = cmp[src++];
* uncmp[tgt] = data;
* tgt = tgt + (LoopSeq == 1? 2:1);
* }
* }
* rlebyte = cmp[src++];
* 
* }
* }
* 
* 
* if (LoopSeq == 1) 
* if (j == 0)  tgt =1;
* 
* }
* 
* 
* 
* return src - 1;
* }
*/





