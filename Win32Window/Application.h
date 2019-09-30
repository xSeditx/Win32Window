#pragma once
///================================================================================================================
///===================== APPLICATION CLASS ========================================================================
///================================================================================================================

/*=====================================================================================================
_________________________________ APPLICATION CLASS ___________________________________________________
=======================================================================================================
  Application class Abstracts away functionality of the application itself. It handles some important
  Messages such as Keyboard or Mouse Events. The User can define a handler for all Keyboard or Mouse
  Events however if they chose not to they can instead define specific Key or Mouse events such as
  a Handler for only the Left Mouse click or one for Only the Key Repeat.
  If the User does not define a specific Generic handler one has been supplied which calls the
  appropritate sub functionality for the input device
=========================================================================================================
USAGE:
=========================================================================================================
*/

#include"NativeWin32.h"
class EventSystem;
class Application
{
public:
	Application();
	~Application();

	void Start();
	void Run();
	void Pause();
	void End();

	void Update();
	void Render();

	//InputManager *Input;
	EventSystem &MessageHandler; 

	Window *ApplicationWindow;
	bool Running = true;

	static HINSTANCE Instance;

//ApplicationWindow.g_Handle();
static Window& ActiveWindow() { return *FocusedWindow; }
static Window *FocusedWindow;
static void s_WindowFocus(Window& _win) { FocusedWindow = &_win; }

protected:

	virtual void OnCreate();
	virtual void OnStart();
	virtual void OnRun();  
	virtual void OnPause();
	virtual void OnSleep();
	virtual void OnEnd();

	virtual void OnUpdate();
	virtual void OnRender();

	void CreateApplicationWindow();
	virtual void SetWindowProperties();

	//Timer ApplicationTimer;


	void SetHints();
	void SetStereo(bool);
	void sRGBCapable(bool);
	void ForwardCompatible(bool);
	void DebugContext(bool);
	void ResizableWindow(bool);
	void VisibleWindow(bool);
	void DecoratedWindow(bool);
	void SetRedBits(unsigned int);
	void SetGreenBits(unsigned int);
	void SetBlueBits(unsigned int);
	void SetAlphaBits(unsigned int);
	void SetDepthBits(unsigned int);
	void SetStencilBits(unsigned int);
	void SetAccumulatorRedBits(unsigned int);
	void SetAccumulatorGreenBits(unsigned int);
	void SetAccumulatorBlueBits(unsigned int);
	void SetAccumulatorAlphaBits(unsigned int);
	void SetAuxiliaryBits(unsigned int);
	void SetNumberOfSamples(unsigned int);
	void SetRefreshRate(unsigned int);
	void UseOpenGLClient(unsigned int);
	void UseOpenGLESClient(unsigned int);
	void SetMajorVersion(unsigned int);
	void SetMinorVersion(unsigned int);
	void UseOpenGLProfile(unsigned int);


private: // Window Information. Default Properties will be set however user can Override these settings

	//void SetHints(HintsStruct hint);
	//HintsStruct Hints;
};
