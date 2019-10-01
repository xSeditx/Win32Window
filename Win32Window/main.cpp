
#include"NativeWin32.h"
#include"Application.h"

/*
 WINDOW
========
~ INPUT
 =======
 ~ MOUSE  [ X ]
  =======
  ~ Position     [ x ]
  ~ Relative     [ x ]
  ~ Buttons      [   ]
 
 ~ KEYBOARD [ X ] 
  ==========
  ~ Keys[]       [ x ]
  ~ KeyDown      [ x ]
  ~ KeyUp        [ x ]

~ EVENTS
 ========
 ~ Window Close  [   ]
 ~ GUI Events    [   ]


 Create GUI Elements [  ]
 GUI Management      [  ]
*/

class TestApp
	:
	public Application
{

};

int main()
{
	TestApp mApp;
	mApp.Start();
	mApp.Run();
	return 0;
}