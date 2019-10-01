#pragma once

#include<unordered_map>
#include<Windows.h>
#include<iostream>
#include<cstdint>    /* Type defines */
#include<string>
#include<stack>
#include<queue>

#include"Glad.h"

/*

   NATIVE WIN32 Window MODULE
   ==========================

   Location Handling
----------------------------------------------------------
	Vec2   g_Position()          
	float  g_PositionX()         
	float  g_PositionY()         
	Vec2   s_Position(Vec2 _pos) 
	Vec2   s_PositionX(float _x) 
	Vec2   s_PositionY(float _y) 
_________________________________________________________


    Dimensions
---------------------------------------------------------
    Vec2 g_Size() { return Size; }
	int Width()   { return Size.x; }
	int Height()  { return Size.y; }
_________________________________________________________

    HWND g_Handle()    const        Returns the Native Windows Handle (HWND) of the Window  
    Window& g_Parent() const        Return the Parent Window if this is a Child 
    Window& s_Parent() const        Sets the Parent Window if this is a Child 

 Changes with Window size and OpenGL Viewport settings 
    void ResizeWindow(uint32_t _x, uint32_t _y);  


*/

/// Awesome conversion of a basic Win32 Hello Window to every language imaginable 
/// http://nehe.gamedev.net/tutorial/creating_an_opengl_window_(win32)/13001/

#include<GL/gl.h>
#include<GL/glu.h>

#pragma comment(lib, "shell32.lib")
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "gdi32.lib")

#pragma comment(lib, "vcruntime.lib")
#pragma comment(lib, "msvcrt.lib")
#pragma comment(lib, "Ws2_32.lib")

#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")
#pragma comment(lib, "gdiplus.lib")



///================================================================================================================
///====================== VARIOUS HELPERS =========================================================================
///================================================================================================================

//#define _STACK_TRACE_

/* Convinence for readability*/
#define REMOVE_MESSAGE 0
#define _EQUALS_       ==
#define _OR_           ||
#define _AND_          &&
#define _static 
#define pure_virtual   0

/* Trace calls in and our of specified functions */
#ifdef _STACK_TRACE_
#    define trace_IN(x)   std::cout << "IN: "<< x << typeid(this).name() << "\n"
#    define trace_OUT(x)  std::cout <<"OUT: "<< x << typeid(this).name() << "\n"
#else
#    define trace_IN(x)   
#    define trace_OUT(x)  
#endif

/* Just basic Logger */
#define Print(x) std::cout << x << '\n'

typedef  MSG  Event;

#ifndef Vec2

///====================================================================================================================================
///================ INCASE A VECTOR HAS NOT BEEN DEFINED ===============================================================================================
///====================================================================================================================================


template<typename _Ty>
struct vec2_point
{
	vec2_point(_Ty _x, _Ty _y)
		:
		x(_x), y(_y)
	{}

	_Ty x;
	_Ty y;

	vec2_point<_Ty> operator +(vec2_point<_Ty> _other) { return vec2_point<_Ty>(this->x + _other.x ,this->y + _other.y); }
	vec2_point<_Ty> operator -(vec2_point<_Ty> _other) { return vec2_point<_Ty>(this->x - _other.x, this->y - _other.y); }
	vec2_point<_Ty> operator *(vec2_point<_Ty> _other) { return vec2_point<_Ty>(this->x * _other.x, this->y * _other.y); }
	vec2_point<_Ty> operator /(vec2_point<_Ty> _other) { return vec2_point<_Ty>(this->x / _other.x, this->y / _other.y); }
};
typedef vec2_point<float>  Vec2;
typedef vec2_point<int>   iVec2;
#endif
#ifdef _REFLECTION /// Soon to be basic Reflection system. 
template<typename _Ty, bool HasMyType>
struct _get_meta
{
	static const TypeInfo *Get() { return _Ty::MyType(); }
};
template<typename _Ty>
struct _get_meta<_Ty, false> 
{
	static const TypeInfo *Get() { return TypeHolder<_Ty>::GetAcceptExSockaddrs(); }
};

template<typename _Ty> const TypeInfo *get_meta()
{
	return _get_meta<Type, has_mytype<_Ty>::value_compare>::GetAcceptExSockaddrs();
}

struct Any
{
	void *Ptr;
	const TypeInfo *Type;
public:
	template<typename _Ty>
		Any(_Ty *_obj) 
			:
			Ptr(_obj), 
			Type(get_meta<Type>::get())
		{}


		template<typename _Ty>
		_Ty *g_Ptr()
		{
			return Type->AdjustToBase(Ptr, Type);
		}

		template<typename _ClassTy, typename _Arg_Ty>
		struct MemberInfo0 : public MemberInfo 
		{
			virtual void Call(void * obj, Any* _argv)
			{
				(static_cast<_ClassTy>(_obj)->Method) (*_argv[0]->g_Ptr<typename std::remove_reference<ArgTy>::type>());
			}
		};
};
#endif

///================================================================================================================
///================= SIMPLE ERROR HANDLING ========================================================================
///================================================================================================================


struct ErrorMessage
{
	ErrorMessage(uint32_t _error, uint32_t _level)
		:
	 Level(_level),
	 ErrorNumber(_error)
	{
		GetSystemTime(Time);
	}
	uint32_t Level;
	uint32_t ErrorNumber;
	LPSYSTEMTIME Time;

	static bool isError() { return !Errors.empty(); }
	static void RaiseException(uint32_t _error, uint32_t _level)
	{
		Errors.push({ _error, _level });
	}
	static bool GetError(ErrorMessage& _msg)
	{
		if (isError())
		{
			_msg = Errors.top();
			Errors.pop();
		}
		return Errors.empty();
	}
	static std::stack<ErrorMessage> Errors;
	friend std::ostream& operator <<(std::ostream& os, ErrorMessage& _msg);
};
std::ostream& operator <<(std::ostream& os, ErrorMessage& _msg);


///================================================================================================================
///============================ INPUT DEVICE STATE ================================================================
///================================================================================================================


struct Input
{
	struct _mouse
	{
		struct
		{
			bool Left, Right, Center, X1, X2;
		}Buttons;
	}static Mouse;

	struct _keyboard
	{
		bool Keys[256];
	}static Keyboard;
};

///================================================================================================================
///====================== WINDOW SYSTEM  ==========================================================================
///================================================================================================================


class Window
{
public:
	Window(uint32_t _width, uint32_t _height, std::string _name, DWORD _flags);// = RESIZABLE);
	Window(Window *_parent, uint32_t _width, uint32_t _height, std::string _name, DWORD _flags = 0);

	/* Returns Windows Position */
	Vec2   g_Position()           { return Position; }

	/* Returns X location of Window on Screen */
	float  g_PositionX()          { return Position.x; }

	/* Returns Y location of Window on Screen */
	float  g_PositionY()          { return Position.y; }

	/* Sets the location of a Window */
	Vec2   s_Position(Vec2 _pos)  { Position = _pos; }

	/* Sets the X location for a Window */
	Vec2   s_PositionX(float _x)  { Position.x = _x; }

	/* Sets the Y location for a Window */
	Vec2   s_PositionY(float _y)  { Position.y = _y; }

	/* return the Dimensions of a Window */
	Vec2 g_Size()                 { return Size; }

	/* Return the Width dimension of a Window */
	int Width()                   { return (int)Size.x; }

	/* Return the Height Dimension of a Window */
	int Height()                  { return (int)Size.y; }

	/* Return if the Window is Alive  
	Note: A Window can be invisible and still be Alive. When the final Window is no longer Alive our Application will terminate
	*/
	bool isAlive() const   { return Alive; }

	/* Let us know if the Window is currently Visible on Screen 
	Note: Intentions are to hide all child Windows if Parent becomes invisible*/
	bool isVisible() const { return Visible; }

	/* Allow us to see if the Window in Question is the Currently Active window on the screen */
	bool isActive() const  { return Active; }

	/* Display the contents of the back buffer to the Screen (*note:future at VSync if Specified) */
	void Sync() { SwapBuffers(DeviceContext); }

	/* Clear the Contents of the BackBuffer */
	void CLS()	{ glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  }       // Clear The Screen And The Depth Buffer

	/* Returns the Native Windows Handle (HWND) of the Window */
	const HWND g_Handle() const { return Handle; }

	/* Return the Parent Window if this is a Child */
	Window& g_Parent() const { return *Parent; }

	/* Sets the Parent Window if this is a Child */
   	Window& s_Parent() const { return *Parent; }

	/* Changes with Window size and OpenGL Viewport settings */
	void ResizeWindow(uint32_t _x, uint32_t _y);
private:

	bool Active  = true;
	bool Alive   = true;
	bool Visible = true;

	Window *Parent = nullptr;
	HWND Handle{ 0 };
	HDC DeviceContext{ 0 };
	Vec2 Size{ 0,0 };
	Vec2 Position{ 0,0 };

	WNDCLASS    WindowProperties = { 0 };
	PIXELFORMATDESCRIPTOR PixelFormatDescriptor{ 0 };
	int PixelFormat{ 0 };
	std::string Title{ "" };
};




///                                                                                                   |||
///       Universal scenes and universal objects are responsible for registering all their extensions |||
///   with the state manager so that the extensions will get notified of changes made by other        |||
///   extensions(ie systems). Example would be to receive notifications of position and orientation   |||
///   changes made by the physics extension.                                                          |||
///                                                                                                   |||





///====================================================================================================================================
///===================== TRASH  ======================================================================================
///====================================================================================================================================
// Sets the Properties defined in the Hint Structure for the Application

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









//int APIENTRY
//WinMain(HINSTANCE hCurrentInst, HINSTANCE hPreviousInst,
//	LPSTR lpszCmdLine, int nCmdShow)
//{
//	HDC hDC;				/* device context */
//	HGLRC hRC;				/* opengl context */
//	HWND  hWnd;				/* window */
//	MSG   msg;				/* message */
//
//	Window T =  Window(0,0,std::string("blah"),(WindowFlags) NULL);
//
////
////	hDC = GetDC(hWnd);
////	hRC = wglCreateContext(hDC);
////	wglMakeCurrent(hDC, hRC);
//
//	
//
//	while (GetMessage(&msg, T.hWnd, 0, 0)) {
//		TranslateMessage(&msg);
//		DispatchMessage(&msg);
//	}
////  
////  wglMakeCurrent(NULL, NULL);
////  ReleaseDC(hWnd, hDC);
////  wglDeleteContext(hRC);
////  DestroyWindow(hWnd);
////  
//	return msg.wParam;
//}

//
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
//{
//	MSG msg;
//	BOOL bRet;
//
//	while (1)
//	{
//		bRet = GetMessage(&msg, NULL, 0, 0);
//
//		if (bRet > 0)  // (bRet > 0 indicates a message that must be processed.)
//		{
//			TranslateMessage(&msg);
//			DispatchMessage(&msg);
//		}
//		else if (bRet < 0)  // (bRet == -1 indicates an error.)
//		{
//			// Handle or log the error; possibly exit.
//			// ...
//		}
//		else  // (bRet == 0 indicates "exit program".)
//		{
//			break;
//		}
//	}
//	return msg.wParam;
//}






// Register the window class.
///const wchar_t CLASS_NAME[] = L"Main Window class"; /// TODO This Needs to become a base Window Class type
///HINSTANCE AppInstance = 0;//. GetModuleHandle(NULL);
///WNDCLASS wc = { };
///
///wc.lpfnWndProc = WindowProc;
///wc.hInstance = AppInstance;// TODO: This should be in an Application class This will not work if executed in a DLL
///wc.style = CS_DBLCLKS | CS_PARENTDC;
///wc.cbClsExtra = 0;
///wc.cbWndExtra = 0;
///wc.hIcon = NULL;
///wc.hCursor = LoadCursor(NULL, (LPTSTR)IDC_IBEAM);
///wc.hbrBackground = NULL;
///wc.lpszMenuName = NULL;
///wc.lpszClassName = (LPCSTR)CLASS_NAME;
///
///RegisterClass(&wc);
///
///// Create the window.
///
///Handle = CreateWindowEx
///(
///	0,                                    // Optional window styles.
///	(LPCSTR)CLASS_NAME,                   // Window class
///	(LPCSTR)L"Learn to Program Windows",  // Window text
///	WS_OVERLAPPEDWINDOW,                  // Window style
///
///	// Size and position
///	CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
///
///	NULL, //Parent->Handle,       // Parent window    
///	NULL,       // Menu
///	AppInstance,  // Instance handle
///	NULL        // Additional application data
///);
///
///if (Handle == NULL)
///{
///	__debugbreak();
///}
///
///ShowWindow(Handle, SW_SHOW);



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







