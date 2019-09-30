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
