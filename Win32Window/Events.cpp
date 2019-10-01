
#include"Events.h"
#include"Application.h"
///==================================================================================================================
///====================== EVENT SYSTEM ==============================================================================
///==================================================================================================================
_static std::stack<ErrorMessage> ErrorMessage::Errors;


EventSystem::EventSystem()
{
}
EventSystem & EventSystem::get()
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
	return PeekMessage(&msg, Application::ActiveWindow().g_Handle(), 0, 0xFFFFFFFF, PM_REMOVE);
}








//handlingflags = 0;/// TEMP TO JUST TEST IT
//if (Messages.size())
//{
//	msg = Event(Messages.front());
//	if (msg.message > _rangemin && msg.message < _rangemax)
//	{
//		switch (handlingflags)
//		{
//		case 0:
//		{// ONLY USE THIS FOR NOW
//			Messages.pop();
//			return true;
//		};
//		case 1://KEEP_MESSAGE:
//		{
//			__debugbreak();
//		}break;
//		case 2:///REPOST_MESSAGE:
//		{/// THIS WILL CURRENTLY BE A PROBLEM DO NOT USE IT
//			Messages.pop();
//			PostMSG(msg);
//			__debugbreak();
//		};
//
//		}
//	}
//}
//return false;//Messages.size() > 0;
//void EventSystem::PollEvents()
//{
//	//LPMSG *Msg = new LPMSG();
//	//PeekMessage(*Msg, Application::ActiveWindow().g_Handle(), 0, 0xFFFFFFFF, PM_REMOVE);
////	//Msg->
//	////assert(Msg->hwnd == Application::ActiveWindow().g_Handle());
//	////while (0)// TODO _handleFlags
//	////{
//	//	Messages.push(**Msg);
//	////}
//}
//	void PollEvents();
/*

Message structure

typedef struct tagMSG 
{
	HWND        hwnd;
	UINT        message;
	WPARAM      wParam;
	LPARAM      lParam;
	DWORD       time;
	POINT       pt;
#ifdef _MAC
	DWORD       lPrivate;
#endif
} MSG, *PMSG, NEAR *NPMSG, FAR *LPMSG;



*/