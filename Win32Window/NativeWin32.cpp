#include"NativeWin32.h"

_static Input::_mouse Input::Mouse;
_static Input::_keyboard Input::Keyboard;
_static HINSTANCE Application::Instance = 0;
_static std::stack<ErrorMessage> ErrorMessage::Errors;
_static Window * Application::FocusedWindow;

std::ostream& operator <<(std::ostream& os, ErrorMessage& _msg)
{
	os << "Error: " << _msg.ErrorNumber << "\n At: " << _msg.Time << "\n ";
	return os;
}

///==================================================================================================================
///====================== WINDOW SYSTEM  ============================================================================
///==================================================================================================================

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	Print("Callback:" << uMsg);
	switch (uMsg)
	{

	case WM_ACTIVATE:                       // Watch For Window Activate Message
	{
		if (!HIWORD(wParam))                    // Check Minimization State
		{
			Print("Active");                    // Program Is Active
		}
		else
		{
			Print("Inactive");                    // Program Is No Longer Active
		}

		return 0;                       // Return To The Message Loop
	}

	case WM_SYSCOMMAND:                     // Intercept System Commands
	{
		switch (wParam)                     // Check System Calls
		{
		case SC_SCREENSAVE:             // Screensaver Trying To Start?
		case SC_MONITORPOWER:               // Monitor Trying To Enter Powersave?
			return 0;                   // Prevent From Happening
		}
		break;                          // Exit
	}

	case WM_CLOSE:                          // Did We Receive A Close Message?
	{
		PostQuitMessage(0);                 // Send A Quit Message
		return 0;                       // Jump Back
	}

	case WM_KEYDOWN:                        // Is A Key Being Held Down?
	{
		Input::Keyboard.Keys[wParam] = TRUE;                    // If So, Mark It As TRUE
		return 0;                       // Jump Back
	}

	case WM_KEYUP:                        // Is A Key Being Held Down?
	{
		Input::Keyboard.Keys[wParam] = TRUE;                    // If So, Mark It As TRUE
		return 0;                       // Jump Back
	}


	case WM_SIZE:                           // Resize The OpenGL Window
	{
		Print("Resize the window here");
		//ReSizeGLScene(LOWORD(lParam), HIWORD(lParam));       // LoWord=Width, HiWord=Height
		return 0;                       // Jump Back
	}
	}

	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

Window::Window(uint32_t _width, uint32_t _height, std::string _name, DWORD _flags)
	:
	Parent(nullptr),
	Size({ (float)_width, (float)_height }),
	Title(_name)
{
	trace_IN("");
 
	const char* title = { "Test Window" };

 	if (!Application::Instance)
	{// TODO: Just do this  in the Application class as that should be responsible for registering its various Class styles
		Application::Instance = GetModuleHandle(NULL);
		WindowProperties.style = CS_HREDRAW| CS_VREDRAW |CS_OWNDC;
		WindowProperties.lpfnWndProc = (WNDPROC)WindowProc;
		WindowProperties.cbClsExtra = 0;
		WindowProperties.cbWndExtra = 0;
		WindowProperties.hInstance = Application::Instance;
		WindowProperties.hIcon = LoadIcon(NULL, IDI_WINLOGO);
		WindowProperties.hCursor = LoadCursor(NULL, IDC_ARROW);
		WindowProperties.hbrBackground = NULL;
		WindowProperties.lpszMenuName = NULL;
		WindowProperties.lpszClassName = "OpenGL";

		if (!RegisterClass(&WindowProperties))
		{
			MessageBox(NULL, "RegisterClass() failed:  "
				"Cannot register window class.", "Error", MB_OK);
			__debugbreak();
		}
	}

	if(!(Handle = CreateWindow
	(
		"OpenGL", 
		title, 
		WS_OVERLAPPEDWINDOW | WS_CLIPSIBLINGS | WS_CLIPCHILDREN,
		(int)Position.x,(int) Position.y, (int)Size.x, (int)Size.y,
		NULL,
		NULL, 
		Application::Instance,
		NULL
	)))
	{
		MessageBox(NULL, "CreateWindow() failed:  Cannot create a window. Error",
			"Error", MB_OK);
		__debugbreak();
	}

	DeviceContext = GetDC(Handle);

	/* there is no guarantee that the contents of the stack that become
	   the pfd are zeroed, therefore _make sure_ to clear these bits. */
	memset(&PixelFormatDescriptor, 0, sizeof(PixelFormatDescriptor));
	PixelFormatDescriptor.nSize = sizeof(PixelFormatDescriptor);
	PixelFormatDescriptor.nVersion = 1;
	PixelFormatDescriptor.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | _flags;
	PixelFormatDescriptor.iPixelType = PFD_TYPE_RGBA;
	PixelFormatDescriptor.cColorBits = 32;

	PixelFormat = 
		ChoosePixelFormat
		(
			DeviceContext, 
			&PixelFormatDescriptor
		);

	if (PixelFormat _EQUALS_ NULL)
	{
		MessageBox
		(
			NULL, 
			"ChoosePixelFormat() failed:  "
			"Cannot find a suitable pixel format.",
			"Error",
			MB_OK
		);
		__debugbreak();
	}

	if (SetPixelFormat(DeviceContext, PixelFormat, &PixelFormatDescriptor) _EQUALS_ FALSE)
	{
		MessageBox
		(
			NULL,
			"SetPixelFormat() failed:  "
			"Cannot set format specified.", 
			"Error",
			MB_OK
		);
		__debugbreak();
	}

	DescribePixelFormat
	(
		DeviceContext,
		PixelFormat, 
		sizeof(PIXELFORMATDESCRIPTOR),
		&PixelFormatDescriptor
	);

	ReleaseDC(Handle, DeviceContext);
	ShowWindow(Handle, SW_SHOW);

	glShadeModel(GL_SMOOTH);
	glClearColor(0.0f, 0.0f, 1.0f, 0.0f);                   // Black Background
	glClearDepth(1.0f);                         // Depth Buffer Setup
	glEnable(GL_DEPTH_TEST);                        // Enables Depth Testing
	glDepthFunc(GL_LEQUAL);                         // The Type Of Depth Test To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);          // Really Nice Perspective Calculations
	/// DEPRECATED I THINK 

	SetForegroundWindow(Handle);                      // Slightly Higher Priority
	SetFocus(Handle);
													  
													  
													  /*
	FULL SCREEN MODE 

	DEVMODE dmScreenSettings;                   // Device Mode
memset(&dmScreenSettings,0,sizeof(dmScreenSettings));       // Makes Sure Memory's Cleared
dmScreenSettings.dmSize=sizeof(dmScreenSettings);       // Size Of The Devmode Structure
dmScreenSettings.dmPelsWidth    = width;            // Selected Screen Width
dmScreenSettings.dmPelsHeight   = height;           // Selected Screen Height
dmScreenSettings.dmBitsPerPel   = bits;             // Selected Bits Per Pixel
dmScreenSettings.dmFields=DM_BITSPERPEL|DM_PELSWIDTH|DM_PELSHEIGHT;
	*/
trace_OUT("");
}
Window::Window(Window *_parent, uint32_t _width, uint32_t _height, std::string _name, DWORD _flags)
	: 
	Window(_width, _height, _name, _flags)
{
	Parent = _parent;
}

void Window::ResizeWindow(uint32_t width, uint32_t height)             // Resize And Initialize The GL Window
{
	if (height == 0)                              // Prevent A Divide By Zero By
	{
		height = 1;                           // Making Height Equal One
	}

	glViewport(0, 0, width, height);                    // Reset The Current Viewport
	glMatrixMode(GL_PROJECTION);
	glMatrixMode(GL_PROJECTION);                        // Select The Projection Matrix
	glLoadIdentity();                           // Reset The Projection Matrix

	// Calculate The Aspect Ratio Of The Window
	gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 100.0f);

	glMatrixMode(GL_MODELVIEW);                     // Select The Modelview Matrix
	glLoadIdentity();                           // Reset The Modelview Matrix
}


///==================================================================================================================
///====================== EVENT SYSTEM ==============================================================================
///==================================================================================================================


EventSystem::EventSystem()
{
}
EventSystem & EventSystem::Instance()
{
	static EventSystem instance;
	return instance;
}

void EventSystem::PostMSG(Event msg)
{
	Messages.push(msg);
}
void EventSystem::RegisterListener(MsgType msg, Listener & handler)
{
	ListenerMap[msg].push_back(&handler);
}
void EventSystem::RemoveListener(MsgType msg, Listener &handler)
{
	ListenerMap[msg].erase(std::find(ListenerMap[msg].begin(), ListenerMap[msg].end(), &handler));
}

void EventSystem::Dispatch(Event msg)
{
	for (auto& Callback : ListenerMap[msg.message])
	{
		Callback->Handler(msg);
	}
}
bool EventSystem::PeekMSG(Event & msg, unsigned int _rangemin, unsigned int _rangemax, int handlingflags)
{
	handlingflags = 0;/// TEMP TO JUST TEST IT
	if (Messages.size())
	{
		msg = Event(Messages.front());
		if (msg.message > _rangemin && msg.message < _rangemax)
		{
			switch (handlingflags)
			{
			case 0:
			{// ONLY USE THIS FOR NOW
				Messages.pop();
				return true;
			}break;
			case 1://KEEP_MESSAGE:
			{
				__debugbreak();
			}break;
			case 2:///REPOST_MESSAGE:
			{/// THIS WILL CURRENTLY BE A PROBLEM DO NOT USE IT
				Messages.pop();
				PostMSG(msg);
				__debugbreak();
			}break;

			}
		}
	}
	
	return false;//Messages.size() > 0;
}
void EventSystem::PollEvents()
{
	LPMSG Msg{ 0 };
	while ( PeekMessageA( Msg, Application::ActiveWindow().g_Handle(), 0, 0xFFFFFFFF	,PM_REMOVE))// TODO _handleFlags
	{
		Messages.push(*Msg);
	}
}


///==================================================================================================================
///========================= APPLICATION  CLASS =====================================================================
///==================================================================================================================


Application::Application()
{
	trace_IN("Application Created:");
}
Application::~Application()
{
	trace_IN("Application Deleted:");
}

//=============================================================================================

//_______________________________ STATE and FLOW HANDLING _____________________________________

void Application::Start()
{
	CreateApplicationWindow();
	OnCreate();
}

void Application::Pause() {}
void Application::End()
{
	OnEnd();
}
void Application::Run()
{
	Event msg;
	while (Running) //ApplicationWindow->isAlive())
	{

		EventSystem::Instance().PollEvents();
		while (EventSystem::Instance().PeekMSG(msg, 0, 0xFFFFFFFF, REMOVE_MESSAGE))
		{
			if (msg.message _EQUALS_ WM_QUIT)               // Have We Received A Quit Message?
			{// TODO: This is just for now. To Avoid a branch here remove this, have the Window fire the Killing of the Application if message is recieved. 
				Running = false;                  // If So done=TRUE
			}
			TranslateMessage(&msg); 
			DispatchMessage(&msg);
			EventSystem::Instance().Dispatch(msg); // Line 37 Eventsystem.cpp
		}
		Update();
		Render();

	}
	End();
}

void Application::Update()
{ // Calls User defined Application Update function
	OnUpdate();
}
void Application::Render()
{ // Calls User define Application Render function
	OnRender();
	ApplicationWindow->Sync();
	//ApplicationWindow->CLS(100, 150, 255); // Do not like the duel Dereference every single frame Feels unneeded at best
}

void Application::OnStart()
{
	trace_IN(" Default Start() ");
	CreateApplicationWindow();
}
/// IDK ABOUT ANY OF THESE
void Application::OnCreate() { trace_IN(" Default "); }
void Application::OnPause()  { trace_IN(" Default "); }
void Application::OnSleep()  { trace_IN(" Default "); }
void Application::OnEnd()    { trace_IN(" Default "); }
void Application::OnRun()    { trace_IN(" Default "); }
void Application::OnUpdate() { trace_IN(" Default "); }
void Application::OnRender() { trace_IN(" Default "); }

//=============================================================================================

//________________________________ WINDOW CREATION PROPERTIES _________________________________

void Application::SetWindowProperties()
{
	trace_IN("DEFAULT: THIS SHOULD GO LIKELY");
}
void Application::CreateApplicationWindow()
{
	trace_IN("DEFAULT: ");
	SetWindowProperties();
	if (false)// TODO: Reinstante this check for Window Creation before creating a default window ApplicationWindow->Width() _EQUALS_ 0 _OR_ ApplicationWindow->Height() _EQUALS_ 0)
	{
		Print(" ERROR: Window Settings have not been set or have been set to NULL.");
		Print(" Define the virtual function with the specifications for your applications Window before calling CreateWindow() ");
		__debugbreak();
	}
	ApplicationWindow = new Window(640,480, std::string("THIS IS DEFAULT WINDOW: DONT FORGET TO FIX THIS SHIT"), 0);
	s_WindowFocus(*ApplicationWindow);
}
void Application::SetHints()
{}