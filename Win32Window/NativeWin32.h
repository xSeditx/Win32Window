#pragma once
#include"Windows.h"
#include<iostream>
#include<cstdint> /* Type defines */
#include<string>
#include<stack>
#include<queue>
#include<unordered_map>
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



*/
#define _STACK_TRACE_

#define _static /* Convinence for readability*/
#define pure_virtual   0

#ifdef _STACK_TRACE_
#    define trace_IN(x)   std::cout << "IN: "<< x << typeid(this).name() << "\n"
#    define trace_OUT(x)  std::cout <<"OUT: "<< x << typeid(this).name() << "\n"
#else
#    define trace_IN(x)   
#    define trace_OUT(x)  
#endif

typedef  MSG  Event;

#ifndef Vec2
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
		uint32_t *Keys;
	}static Keyboard;
};


enum WindowFlags
{
	RESIZABLE, BORDERLESS, CHILD_WINDOW, OPENGL
};

class Window
{
public:
	Window(uint32_t _width, uint32_t _height, std::string _name, WindowFlags _flags);// = RESIZABLE);
	Window(Window *_parent, uint32_t _width, uint32_t _height, std::string _name, WindowFlags _flags = RESIZABLE);

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
	int Width()                   { return Size.x; }

	/* Return the Height Dimension of a Window */
	int Height()                  { return Size.y; }

private:

	Window *Parent;
	HWND Handle{ 0 };

	Vec2 Size{ 0,0 };
	Vec2 Position{ 0,0 };
	std::string Title{ "" };
};
























//
//
//
//template<typename _func, typename...ARGS>
//struct Func
//{
//	Func(_func, ARGS... args)
//	{
//		f = std::bind(_func, args...);
//	}
//	operator()
//	{
//		f();
//	}
//	void(*f)();
//};


typedef uint32_t MsgType;
typedef uint32_t WindowID;// This will likely change to a pointer, or some other form later on.
//============================================================
class Window;

/*
struct MYSTIC Event
{// Event Union Defining an Event the Engine can produce
	Event();
	Event(MsgType msg);

	MsgType ID;
	WindowID WinID;
	unsigned long Time;

#pragma pack(push, 1)
	union msgUnion
	{// All messages are 128 bits
		msgUnion() = default;

		msgUnion &operator =(const msgUnion&other)
		{
			memcpy(this, &other, sizeof(other)); // Should be 16 bytes, check this if any changes get made
			return *this;
		}

		struct msgstruct
		{
			uint32_t wordParam;
			uint64_t longParam;
			uint32_t Padding;
		}MSG; // 128 bits
		struct kbstruct
		{
			uint32_t KeyCode;
			uint32_t ScanCode;
			uint32_t Action;
			uint32_t Mods;
		}Keyboard; // 128
		struct mousestruct
		{
			uint32_t Button;
			uint32_t x;
			uint32_t y;
			int16_t relX;
			int16_t relY;
		}Mouse; // 128
		struct buttonstruct
		{
			struct buttons
			{
				uint8_t
					Left,
					Right,
					Middle,
					Wheel;
			}Buttons; // 32
			uint32_t Action;
			uint32_t Modification;
			uint32_t Padding;
		}MouseButton; // 128
		struct textstruct {}TextInput;
	}data;
#pragma pack(pop)

	bool Handled() { return (ID == 0); }
};
*/


struct Listener
{
public:
	Listener(void(*func)(Event))
		:
		_handler(func)
	{}
	void SetHandler(void(*func)(Event))
	{
		_handler = func;
	}
	inline void Handler(Event msg)
	{
		_handler(msg);
	};
private:
	void(*_handler)(Event msg);
};

class EventSystem
{// Singleton design pattern
	EventSystem();
public:
	static EventSystem &Instance();           // Initializes EventSystem when called first time
	EventSystem(EventSystem const&) = delete; // and prevents Copies from being made
	void operator = (EventSystem const&) = delete;

public:
	void PollEvents();
	void PostMSG(Event msg);
	bool PeekMSG(Event&msg, unsigned int rangemin, unsigned int rangemax, int handlingflags);
	void Dispatch(Event msg);

	void RegisterListener(MsgType msg, Listener &handler);
	void RemoveListener(MsgType msg, Listener &handler);
private:
	std::queue<Event> Messages;
	std::unordered_map<MsgType, std::vector<Listener*>> ListenerMap;
};
