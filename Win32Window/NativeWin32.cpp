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
// Register the window class.
	const wchar_t CLASS_NAME[] = L"Main Window class";
	HINSTANCE AppInstance =GetModuleHandle(NULL);
	WNDCLASS wc = { };
	
	wc.lpfnWndProc = WindowProc;
	wc.hInstance = AppInstance;// TODO: This should be in an Application class This will not work if executed in a DLL
	wc.lpszClassName = (LPCSTR)CLASS_NAME;

	RegisterClass(&wc);

	// Create the window.

	HWND hwnd = CreateWindowEx(
		0,                              // Optional window styles.
		(LPCSTR)CLASS_NAME,                     // Window class
		(LPCSTR)L"Learn to Program Windows",    // Window text
		WS_OVERLAPPEDWINDOW,            // Window style

		// Size and position
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

		NULL,       // Parent window    
		NULL,       // Menu
		AppInstance,  // Instance handle
		NULL        // Additional application data
	);

	if (hwnd == NULL)
	{
		__debugbreak();
	}

	ShowWindow(hwnd, SW_SHOW);
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