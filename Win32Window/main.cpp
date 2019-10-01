
#include"NativeWin32.h"
#include"Application.h"



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