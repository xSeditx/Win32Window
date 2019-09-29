#include"NativeWin32.h"

_static Input::_mouse Input::Mouse;
_static Input::_keyboard Input::Keyboard;




LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	return (LRESULT)0;
}


Window::Window(uint32_t _width, uint32_t _height, std::string _name, WindowFlags _flags)
	:
	Parent(nullptr),
	Size({ (float)_width, (float)_height }),
	Title(_name)
{
	trace_IN("");

// Register the window class.
	const wchar_t CLASS_NAME[] = L"Main Window class"; /// TODO This Needs to become a base Window Class type
	HINSTANCE AppInstance = GetModuleHandle(NULL);
	WNDCLASS wc = { };
	
	wc.lpfnWndProc = WindowProc;
	wc.hInstance = AppInstance;// TODO: This should be in an Application class This will not work if executed in a DLL
	wc.style = CS_DBLCLKS | CS_PARENTDC;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hIcon = NULL;
	wc.hCursor = LoadCursor(NULL, (LPTSTR)IDC_IBEAM);
	wc.hbrBackground = NULL;
	wc.lpszMenuName = NULL;
	wc.lpszClassName = (LPCSTR)CLASS_NAME;

	RegisterClass(&wc);

	// Create the window.

	Handle = CreateWindowEx
	(
		0,                                    // Optional window styles.
		(LPCSTR)CLASS_NAME,                   // Window class
		(LPCSTR)L"Learn to Program Windows",  // Window text
		WS_OVERLAPPEDWINDOW,                  // Window style

		// Size and position
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

		NULL, //Parent->Handle,       // Parent window    
		NULL,       // Menu
		AppInstance,  // Instance handle
		NULL        // Additional application data
	);

	if (Handle == NULL)
	{
		__debugbreak();
	}

	ShowWindow(Handle, SW_SHOW);
	trace_OUT("");
}

Window::Window(Window *_parent, uint32_t _width, uint32_t _height, std::string _name, WindowFlags _flags)
	: 
	Window(_width,_height,_name,_flags)
{
	Parent = _parent;
}





 
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
bool EventSystem::PeekMSG(Event & msg, unsigned int rangemin, unsigned int rangemax, int handlingflags)
{
	handlingflags = 0;/// TEMP TO JUST TEST IT

	if (Messages.size())
	{
		msg = Event(Messages.front());
		if (msg.message > rangemin && msg.message < rangemax)
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
	///InputManager::PollNativeEvents();
}





















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


#include<string>
Application::Application()
{
	trace_IN("Application Created:");
}
Application::~Application()
{
	trace_IN("Application Deleted:");
}

//=======================================================================================================
//_______________________________ STATE and FLOW HANDLING _______________________________________________
//=======================================================================================================

void Application::Start()
{
	///CreateMysticWindow();
	//TODO: Setup a Window Creation function

	//--------Gathering information about OpenGL state and Display it -----------------------------------------------
	//  int NumberOfExtensions = 0;
	//  _GL(glGetIntegerv(GL_NUM_EXTENSIONS, &NumberOfExtensions));
	//  
	//  for (int i = 0; i < NumberOfExtensions; i++) {
	//  	const GLubyte *ccc = glGetStringi(GL_EXTENSIONS, i);
	//  	Print(ccc);
	//  }

	//const GLubyte *extensions = glGetString(GL_EXTENSIONS);
	//Print(extensions);
	//Print("");
	//Print("OpenGL Version: " << glGetString(GL_VERSION));
	//Print("Renderer: " << glGetString(GL_RENDERER));
	//Print("Current Context: "; Print(glGetCurrentContext()));

	//-------------------------------------------------------------------------------------------------------------
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
	while (ApplicationWindow->isAlive())
	{

		EventSystem::Instance().PollEvents();
		while (EventSystem::Instance().PeekMSG(msg, 0, 0xFFFFFFFF, REMOVE_MESSAGE))
		{
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



//=================================================================================================
//________________________________ WINDOW CREATION PROPERTIES _____________________________________
//=================================================================================================
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
	ApplicationWindow = new Window(640,480, std::string("THIS IS DEFAULT WINDOW: DONT FORGET TO FIX THIS SHIT"), (WindowFlags)0);
}
void Application::SetHints()

{// Sets the Properties defined in the Hint Structure for the Application
}
	/*
	DEBUG_TRACE("I Do not Like this, Not one single bit, I want this Hint structure to be in the Window Class however I want to be able to assign properties using the SetWindowProperties. There is a problem because I have to Initialize GLFW before and that is in the Window Struct. I will likely Initialize GLFW in the System Manager or something.")
		glfwWindowHint(GLFW_RESIZABLE, Hints.WindowStyle.RESIZABLE);
	glfwWindowHint(GLFW_VISIBLE, Hints.WindowStyle.VISIBLE);
	glfwWindowHint(GLFW_DECORATED, Hints.WindowStyle.DECORATED);
	// For VR type stuff
	glfwWindowHint(GLFW_STEREO, Hints.Random.STEREO);
	glfwWindowHint(GLFW_SRGB_CAPABLE, Hints.Random.SRGB_CAPABLE);
	// --------- Following Create the Default Framebuffer for the Window being created --------
	// Color Bits
	glfwWindowHint(GLFW_RED_BITS, Hints.FrameBuffer.RED_BITS);
	glfwWindowHint(GLFW_GREEN_BITS, Hints.FrameBuffer.GREEN_BITS);
	glfwWindowHint(GLFW_BLUE_BITS, Hints.FrameBuffer.BLUE_BITS);
	glfwWindowHint(GLFW_ALPHA_BITS, Hints.FrameBuffer.ALPHA_BITS);
	// Depth and Stencil Buffer bits
	glfwWindowHint(GLFW_DEPTH_BITS, Hints.FrameBuffer.DEPTH_BITS);
	glfwWindowHint(GLFW_STENCIL_BITS, Hints.FrameBuffer.STENCIL_BITS);
	// Accumulation Bits
	glfwWindowHint(GLFW_ACCUM_RED_BITS, Hints.FrameBuffer.ACCUM_RED_BITS);
	glfwWindowHint(GLFW_ACCUM_GREEN_BITS, Hints.FrameBuffer.ACCUM_GREEN_BITS);
	glfwWindowHint(GLFW_ACCUM_BLUE_BITS, Hints.FrameBuffer.ACCUM_BLUE_BITS);
	glfwWindowHint(GLFW_ACCUM_ALPHA_BITS, Hints.FrameBuffer.ACCUM_ALPHA_BITS);
	//-------------------------------------------------------------------------------------------
	glfwWindowHint(GLFW_AUX_BUFFERS, Hints.FrameBuffer.AUX_BUFFERS);
	// Anti Aliasing Sampling rates
	glfwWindowHint(GLFW_SAMPLES, Hints.FrameBuffer.SAMPLES);
	glfwWindowHint(GLFW_REFRESH_RATE, Hints.FrameBuffer.REFRESH_RATE);
	// OpenGL Context Creation
	glfwWindowHint(GLFW_CLIENT_API, Hints.Context.CLIENT_API);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, Hints.Context.CONTEXT_VERSION_MAJOR);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, Hints.Context.CONTEXT_VERSION_MINOR);
	glfwWindowHint(GLFW_CONTEXT_ROBUSTNESS, Hints.Context.CONTEXT_ROBUSTNESS);
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, Hints.Context.FORWARD_COMPAT);
	//glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, Hints.Context.OPENGL_DEBUG_CONTEXT);
	glfwWindowHint(GLFW_OPENGL_PROFILE, Hints.Context.OPENGL_PROFILE);
}
void Application::SetStereo(bool param)
{
	Hints.Random.STEREO = param;
}
void Application::sRGBCapable(bool param)
{
	Hints.Random.SRGB_CAPABLE = param;
}
void Application::ForwardCompatible(bool param)
{
	Hints.Random.OPENGL_FORWARD_COMPAT = param;
}
void Application::DebugContext(bool param)
{
	Hints.Random.OPENGL_DEBUG_CONTEXT = param;
}
void Application::ResizableWindow(bool param)
{
	Hints.WindowStyle.RESIZABLE = param;
}
void Application::VisibleWindow(bool param)
{
	Hints.WindowStyle.VISIBLE = param;
}
void Application::DecoratedWindow(bool param)
{
	Hints.WindowStyle.DECORATED = param;
}
void Application::SetRedBits(unsigned int param)
{
	Hints.FrameBuffer.RED_BITS = param;
}
void Application::SetGreenBits(unsigned int param)
{
	Hints.FrameBuffer.GREEN_BITS = param;
}
void Application::SetBlueBits(unsigned int param)
{
	Hints.FrameBuffer.BLUE_BITS = param;
}
void Application::SetAlphaBits(unsigned int param)
{
	Hints.FrameBuffer.ALPHA_BITS = param;
}
void Application::SetDepthBits(unsigned int param)
{
	Hints.FrameBuffer.DEPTH_BITS = param;
}
void Application::SetStencilBits(unsigned int param)
{
	Hints.FrameBuffer.STENCIL_BITS = param;
}
void Application::SetAccumulatorRedBits(unsigned int param)
{
	Hints.FrameBuffer.ACCUM_RED_BITS = param;
}
void Application::SetAccumulatorGreenBits(unsigned int param)
{
	Hints.FrameBuffer.ACCUM_GREEN_BITS = param;
}
void Application::SetAccumulatorBlueBits(unsigned int param)
{
	Hints.FrameBuffer.ACCUM_BLUE_BITS = param;
}
void Application::SetAccumulatorAlphaBits(unsigned int param)
{
	Hints.FrameBuffer.ACCUM_ALPHA_BITS = param;
}
void Application::SetAuxiliaryBits(unsigned int param)
{
	Hints.FrameBuffer.AUX_BUFFERS = param;
}
void Application::SetNumberOfSamples(unsigned int param)
{
	Hints.FrameBuffer.SAMPLES = param;
}
void Application::SetRefreshRate(unsigned int param)
{
	Hints.FrameBuffer.REFRESH_RATE = param;
}
void Application::UseOpenGLClient(unsigned int param)
{
	Hints.Context.CLIENT_API = param;
}
void Application::UseOpenGLESClient(unsigned int param)
{
	Hints.Context.CONTEXT_VERSION_MAJOR = param;
}
void Application::SetMajorVersion(unsigned int param)
{
	Hints.Context.CONTEXT_VERSION_MINOR = param;
}
void Application::SetMinorVersion(unsigned int param)
{
	Hints.Context.CONTEXT_ROBUSTNESS = param;
}
void Application::UseOpenGLProfile(unsigned int param)
{
	Hints.Context.OPENGL_PROFILE = param;
}



*/