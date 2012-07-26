// Inclusiones STL.
#include <algorithm>

// Inclusiones propias.
#include "Events/Manager.hpp"

namespace PaperBird
{
namespace Events
{

template <typename EventType, typename EventData>
void Manager<EventType, EventData>::SendEvent(const EventType &aEvent, const std::ostringstream &aData) const
{
	// Primero, averiguamos si hay alguien a la escucha del evento recibido.
	MapEvents::const_iterator EventFound = mEvents.find(aEvent);

	if (EventFound != mEvents.end())
	{
		// Ahora que ya tenemos a los que estan a la escucha del evento, se lo enviamos.
		const ListListeners &Listeners = EventFound->second;

		for (ListListeners::const_iterator ListenerIterator = Listeners.begin(); ListenerIterator != Listeners.end(); ++ListenerIterator)
		{
			Listener &Owner = ListenerIterator->first;
			Listener::CallBack Function = ListenerIterator->second;

			(Owner.*Function)(aData);
		}
	}
};

template <typename EventType, typename EventData>
void Manager<EventType, EventData>::AddListener(const EventType &aEvent, Listener::ListenerCallback &aListenerCallback)
{
	// Primero, averiguamos si ya existe lista de Oyentes de este evento.
	MapEvents::iterator EventFound = mEvents.find(aEvent);

	if (EventFound == mEvents.end())
	{
		// Si no hay nadie escuchando este Evento, damos de alta este primer Oyente.
		mEvents.insert(std::pair<const Event_Base, ListListeners>(aEvent, ListListeners(1, aListenerCallback)));
	}
	else
	{
		// Ahora que ya tenemos la lista de Oyentes, anyadimos el recibido.
		EventFound->second.push_back(aListenerCallback);
	}
};

template <typename EventType, typename EventData>
void Manager<EventType, EventData>::RemoveListener(const Listener &aListener)
{
	MapEvents::iterator Event = mEvents.begin();

	do
	{
		ListListeners &Listeners = Event->second;
		ListListeners::iterator ListenerIterator = Listeners.begin();

		do
		{
			if (ListenerIterator->first == aListener)
			{
				ListenerIterator = Listeners.erase(ListenerIterator);
			}
			else
			{
				++ListenerIterator;
			}
		}
		while (ListenerIterator != Listeners.end());

		if (Listeners.empty())
		{
			Event = mEvents.erase(Event);
		}
		else
		{
			++Event;
		}
	}
	while (Event != mEvents.end());
};

template <typename EventType, typename EventData>
void Manager<EventType, EventData>::RemoveListener(const EventType &aEvent, const Listener &aListener)
{
	// Primero, averiguamos si hay alguien a la escucha del evento indicado.
	MapEvents::iterator EventFound = mEvents.find(aEvent);

	if (EventFound != mEvents.end())
	{
		// Una vez encontrado el evento, buscamos el Oyente que quiere dejar de oir el Evento.
		ListListeners &Listeners = EventFound->second;
		ListListeners::iterator ListenerIterator = Listeners.begin();

		do
		{
			if (ListenerIterator->first == aListener)
			{
				ListenerIterator = Listeners.erase(ListenerIterator);
			}
			else
			{
				++ListenerIterator;
			}
		}
		while (ListenerIterator != Listeners.end());
	}
};

}
}
