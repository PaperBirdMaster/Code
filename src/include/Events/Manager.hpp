#ifndef PAPERBIRD_EVENTS_MANAGER_H
#define PAPERBIRD_EVENTS_MANAGER_H

// Inclusiones STL.
#include <map>
#include <list>
#include <sstream>

namespace PaperBird
{
namespace Events
{

/**
* Clase gestora de Eventos.
* @author Paw Miquel Montequi (PaperBirdMaster).
*/
template <class EventListener, typename EventValueType, typename EventDataType> class Manager
{
public:

	//! Definicion de puntero a la funcion CallBack del Listener.
	typedef void (EventListener::*CallBack)(EventDataType aData);

	//! Publicamos el tipo de Eventos asociado a este Manager.
	typedef typename EventValueType EventType;

	//! Publicamos el tipo de Datos de Evento asociado a este Manager.
	typedef typename EventDataType EventData;

private:

	//! Par de Oyente de Evento y Funcion de CallBack.
	typedef std::pair<EventListener &, CallBack> ListenerCallback;

	//! Definicion de lista de Oyentes de Eventos.
	typedef std::list<typename ListenerCallback> ListListeners;

	//! Definicion de Eventos con Oyentes de Eventos.
	typedef std::map<const EventType, ListListeners> MapEvents;

	//! Coleccion de Oyentes de Eventos.
	MapEvents mEvents;

public:
	/**
	* Envia el Evento facilitado y sus Datos a los Listener que estan a la escucha de dicho evento.
	* @param aEvent Evento a enviar.
	* @param aData Datos asociados al evento.
	*/
	bool SendEvent(EventType aEvent, EventData aData) const
	{
		// Indica si el evento ha sido capturado por algun Listener.
		bool Result = false;
		// Primero, averiguamos si hay alguien a la escucha del evento recibido.
		MapEvents::const_iterator EventFound = mEvents.find(aEvent);

		if ((Result = (EventFound != mEvents.end())))
		{
			// Ahora que ya tenemos a los que estan a la escucha del evento, se lo enviamos.
			const ListListeners &Listeners = EventFound->second;

			for (ListListeners::const_iterator ListenerIterator = Listeners.begin(); ListenerIterator != Listeners.end(); ++ListenerIterator)
			{
				EventListener &Owner = ListenerIterator->first;
				CallBack Function = ListenerIterator->second;

				(Owner.*Function)(aData);
			}
		}

		return Result;
	};

	/**
	* Anyade un Listener para que sea informado cada vez que se lanze el Evento indicado.
	* @param aEvent Evento que se quiere escuchar.
	* @param aEventListener 
	* @param aCallBack 
	*/
	void AddListener(EventType aEvent, EventListener &aEventListener, const CallBack &aCallBack)
	{
		// Creamos el par de Oyente y Funcion...
		ListenerCallback NewListener(aEventListener, aCallBack);
		// Averiguamos si ya existe lista de Oyentes de este evento.
		MapEvents::iterator EventFound = mEvents.find(aEvent);

		if (EventFound == mEvents.end())
		{
			// Si no hay nadie escuchando este Evento, damos de alta este primer Oyente.
			mEvents.insert(MapEvents::value_type(aEvent, ListListeners(1, NewListener)));
		}
		else
		{
			// Ahora que ya tenemos la lista de Oyentes, anyadimos el recibido.
			EventFound->second.push_back(NewListener);
		}
	};

	/**
	* Hace que el Listener facilitado deje de ser notificado de la recepcion de Eventos.
	* @param aListener Listener que dejara de recibir notificaciones de Eventos.
	*/
	void RemoveListener(EventListener &aListener)
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

	/**
	* Hace que el Listener facilitado deje de ser notificado del Evento indicado.
	* @param aEvent Evento que dejara de enviarse al Listener facilitado.
	* @param aListener Listener que dejara de recibir notificaciones del Evento indicado.
	*/
	void RemoveListener(EventType aEvent, EventListener &aListener)
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
};

}
}

#endif