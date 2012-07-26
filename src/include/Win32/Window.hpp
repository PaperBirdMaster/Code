#ifndef PAPERBIRD_WIN32_WINDOW_H
#define PAPERBIRD_WIN32_WINDOW_H

// Inclusiones STL.
#include <string>

// Inclusiones de Plataforma.
#include <windows.h>

// Inclusiones propias.
#include "WindowExtendedStyle.hpp"
#include "WindowStyle.hpp"
#include "Events/Manager.hpp"

namespace PaperBird
{
namespace Win32
{

//! Tamanyo por defecto de las ventanas creadas.
const RECT DefaultWindowRect =
{
	300,
	300,
	500,
	400
};

/**
*
*/
class Window
{
public:

	/**
	* Crea una ventana de Windows con los valores facilitados.
	* @param aName Nombre de la clase que se asignara a la ventana.
	* @param aInstance Puntero a la instancia que contendra la clase (proveido desde el punto de entrada de la aplicacion).
	* @param aCaption Titulo que se mostrara en la barra de la Ventana.
	* @param aRect Tamanyo de la Ventana creada.
	* @param aXStyle Estilo extendido de ventana ( http://msdn.microsoft.com/en-us/library/windows/desktop/ff700543(v=vs.85).aspx ).
	* @param aStyle Estilo de ventana ( http://msdn.microsoft.com/en-us/library/windows/desktop/ms632600(v=vs.85).aspx ).
	*/
	Window(const std::wstring &aName, HINSTANCE aInstance,
		const std::wstring &aCaption = L"", const RECT &aRect = DefaultWindowRect,
		WindowExtendedStyle aXStyle = WindowXS_NOEXTENDEDSTYLE, WindowStyle aStyle = Window_OVERLAPPEDWINDOW);

	/**
	* Captura los mensajes de Windows e informa a la funcion de Procesado.
	*/
	int IsActive();

	/**
	* 
	*/
	void AddMenu(const std::wstring &aMenuName, UINT aMenuCode);

	/**
	* Muestra u oculta la ventana.
	*/
	void SetVisible(bool aVisible);

	/**
	*
	*/
	void OnDestroy(const std::pair<WPARAM, LPARAM> aData);

	/**
	*
	*/
	void OnQuit(const std::pair<WPARAM, LPARAM> aData);

	/**
	*
	*/
	HWND GetHandlerWindow() const;

private:

	//! Puntero a la ventana.
	HWND mWindow;

	//! Valor de retorno del proceso de la ventana.
	int mReturnValue;

	/**
	* Recibe los mensajes de Windows y genera un Evento para cada uno.
	*/
	static LRESULT CALLBACK ProcessMessages(HWND aReceptorWindow, UINT aMessageCode, WPARAM wParam, LPARAM lParam);
};

// Definimos el tipo del gestor de eventos.
typedef PaperBird::Events::Manager<Window, UINT, std::pair<WPARAM, LPARAM>> Win32Events;

}
}

#endif
