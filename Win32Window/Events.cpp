
#include"Events.h"
#include"Application.h"
///==================================================================================================================
///====================== EVENT SYSTEM ==============================================================================
///==================================================================================================================
_static std::stack<ErrorMessage> ErrorMessage::Errors;


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
	while (PeekMessageA(Msg, Application::ActiveWindow().g_Handle(), 0, 0xFFFFFFFF, PM_REMOVE))// TODO _handleFlags
	{
		Messages.push(*Msg);
	}
}

