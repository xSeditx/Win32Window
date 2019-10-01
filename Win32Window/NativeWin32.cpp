#include"NativeWin32.h"
#include"Application.h"
_static Input::_mouse Input::Mouse;
_static Input::_keyboard Input::Keyboard;

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

		break;                       // Return To The Message Loop
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
		break;    // Jump Back
	}

	case WM_KEYDOWN:                        // Is A Key Being Held Down?
	{
		Input::Keyboard.Keys[wParam] = TRUE;                    // If So, Mark It As TRUE
		break;                      // Jump Back
	}

	case WM_KEYUP:                        // Is A Key Being Held Down?
	{
		Input::Keyboard.Keys[wParam] = TRUE;                    // If So, Mark It As TRUE
		break;                      // Jump Back
	}

	case WM_SIZE:                           // Resize The OpenGL Window
	{
		Print("Resize the window here");
		//ReSizeGLScene(LOWORD(lParam), HIWORD(lParam));       // LoWord=Width, HiWord=Height
		break;                       // Jump Back
	}

	case WM_NCMOUSEMOVE:
	{
		Print("MouseMove");
	}

	case WM_NCLBUTTONDOWN:
	{
		Print("MouseDown");
		break;
	}

	case WM_LBUTTONUP:
	{
		Print("Left Button Up");
		break;
	}

	case WM_LBUTTONDBLCLK:
	{
		Print("L DClick ");
		break;
	}

	case WM_RBUTTONDOWN:
	{	
		Print(" RButtonDown");
		break;
	}

	case WM_RBUTTONUP:
	{
		Print(" RButUP");
		break;
	}

	case WM_RBUTTONDBLCLK:
	{
		Print(" R Button DClick");
		break;
	}

	case WM_MBUTTONDOWN:
	{
		Print(" MButtonDown");
		break;
	}

	case WM_MBUTTONUP:
	{
		Print("M BUtton UP ");
		break;
	}

	case WM_MBUTTONDBLCLK:
	{
		Print(" MButton DClick");
		break;
	}

	case WM_XBUTTONDOWN:
	{
		Print(" XButtonDown");
		break;
	}

	case WM_XBUTTONUP:
	{
		Print(" X Up");
		break;
	}

	case WM_XBUTTONDBLCLK:
	{
		Print(" X DClick");
		break;
	}

	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
}

Window::Window(uint32_t _width, uint32_t _height, std::string _name, DWORD _flags)
	:
	Parent(nullptr),
	Size({ (float)_width, (float)_height }),
	Title(_name)
{
	trace_IN("");
 //http://www.rastertek.com/gl40tut03.html
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
	   the pfd are zeroed, therefore _make sure_ to clear these bits. 
	NOTE:  A good pixel format to choose for the dummy context is a simple 32-bit RGBA color buffer, with a 24-bit depth buffer and 8-bit stencil, as we did in the above sample PFD. This will usually get a hardware accelerated pixel format.   
	   */
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
	SetForegroundWindow(Handle);                      // Slightly Higher Priority
	SetFocus(Handle);
	//ReleaseDC(Handle, DeviceContext);
	ShowWindow(Handle, SW_SHOW);
	int  letWindowsChooseThisPixelFormat;
	letWindowsChooseThisPixelFormat = ChoosePixelFormat(DeviceContext, &PixelFormatDescriptor);
	SetPixelFormat(DeviceContext, letWindowsChooseThisPixelFormat, &PixelFormatDescriptor);

	HGLRC ourOpenGLRenderingContext = wglCreateContext(DeviceContext);
	wglMakeCurrent(DeviceContext, ourOpenGLRenderingContext);
	
	//MessageBoxA(0, (char*)glGetString(GL_VERSION), "OPENGL VERSION", 0);




	//load_GL_VERSION_4_6(wglGetProcAddress);
	gladLoadGLLoader((GLADloadproc)wglGetProcAddress);
	//if (!gladLoadGL())
	//{
	////	int error_code = glad_glGetError();
	////	std::cout << "Failed to initialize GLAD" << error_code << std::endl;
	////	__debugbreak();
	//	//return -1;
	//}
	//glShadeModel(GL_SMOOTH);
	//glClearColor(0.0f, 0.0f, 1.0f, 0.0f);                   // Black Background
	//glClearDepth(1.0f);                         // Depth Buffer Setup
	//glEnable(GL_DEPTH_TEST);                        // Enables Depth Testing
	//glDepthFunc(GL_LEQUAL);                         // The Type Of Depth Test To Do
	//glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);          // Really Nice Perspective Calculations
	/// DEPRECATED I THINK 
													  
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
