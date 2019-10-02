#include"Application.h"
#include"Events.h"
///==================================================================================================================
///========================= APPLICATION  CLASS =====================================================================
///==================================================================================================================
_static HINSTANCE Application::Instance = 0;
_static Window * Application::FocusedWindow;


Application::Application()
	:
	MessageHandler(EventSystem::get())
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
	while (Running)
	{
		while (EventSystem::get().PeekMSG(msg, 0, 0xFFFFFFFF, REMOVE_MESSAGE))
		{
			if (msg.message _EQUALS_ WM_QUIT)               // Have We Received A Quit Message?
			{// TODO: This is just for now. To Avoid a branch here remove this, have the Window fire the Killing of the Application if message is recieved. 
				Running = false;                  // If So done=TRUE
			}
			TranslateMessage(&msg);
			DispatchMessage(&msg);
			EventSystem::get().Dispatch(msg); // Line 37 Eventsystem.cpp
		}

		//SwapBuffers(ApplicationWindow->g_DeviceContext());
		//glFlush();		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			Update();
	//	UpdateWindow(ApplicationWindow->g_Handle());
		Render();
		glFlush();

		if (glGetError())
		{
			Print("Error");
		}
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
void Application::OnPause() { trace_IN(" Default "); }
void Application::OnSleep() { trace_IN(" Default "); }
void Application::OnEnd() { trace_IN(" Default "); }
void Application::OnRun() { trace_IN(" Default "); }
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
	ApplicationWindow = new Window(640, 480, std::string("THIS IS DEFAULT WINDOW: DONT FORGET TO FIX THIS SHIT"), 0);
	s_WindowFocus(*ApplicationWindow);
}
void Application::SetHints()
{}