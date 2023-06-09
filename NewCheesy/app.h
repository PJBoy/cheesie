
#ifndef __APP_H__       // include protection -- prevents the same file
#define __APP_H__       //    from being included multiple times

/*
*	The class which represents your application instance
*/

class App : public wxApp
{
public:

	// need to have this OnInit() function.  This is like the WinMain except
	//  for wx
	bool        OnInit();
	
};

// putting DECLARE_APP here allows use of the wxGetApp() function which allows
//   any area of the program to get the global App object.  You can use this to have
//   "global" variables in your App that you can access with 'wxGetApp().var'.

DECLARE_APP(App);


#endif // __APP_H__