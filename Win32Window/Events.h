#pragma once

#include"NativeWin32.h"

///================================================================================================================
///=========================== LISTENER CALLBACK BASE =============================================================
///================================================================================================================


typedef uint32_t MsgType;
typedef uint32_t WindowID;// This will likely change to a pointer, or some other form later on.
//============================================================

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

///================================================================================================================
///========================= PUBLISHER SUBSCRIBER SYSTEM ==========================================================
///================================================================================================================

#define NULL_COPY_AND_ASSIGNMENT(_ClassName)  _ClassName(_ClassName const&) = delete; void operator = (_ClassName const&) = delete;  // and prevents Copies from being made


class EventSystem
{// Singleton design pattern
	EventSystem();	
	NULL_COPY_AND_ASSIGNMENT(EventSystem);

public: 
	/*  Initializes EventSystem and returns Reference to Only EventSystem instance */
	static EventSystem &get();     
  
public:
	void PostMSG(Event msg);
	bool PeekMSG(Event&msg, unsigned int rangemin, unsigned int rangemax, int handlingflags);
	void Dispatch(Event msg);

	void RegisterListener(MsgType msg, Listener &handler);
	void RemoveListener(MsgType msg, Listener &handler);
private:
	std::queue<Event> Messages;
	std::unordered_map<MsgType, std::vector<Listener*>> ListenerMap;
};
