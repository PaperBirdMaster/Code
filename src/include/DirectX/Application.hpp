#ifndef PAPERBIRD_DIRECTX_APPLICATION_H
#define PAPERBIRD_DIRECTX_APPLICATION_H

// Inclusiones de plataforma.
#include <d3d9.h>
#pragma comment (lib, "d3d9.lib")

// Inclusiones propias.
#include "Win32/Window.hpp"

namespace PaperBird
{
namespace DirectX
{

class Application : public Win32::Window
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
	Application(const std::wstring &aName, HINSTANCE aInstance,
		const std::wstring &aCaption = L"", const RECT &aRect = Win32::DefaultWindowRect,
		Win32::WindowExtendedStyle aXStyle = Win32::WindowXS_NOEXTENDEDSTYLE, Win32::WindowStyle aStyle = Win32::Window_OVERLAPPEDWINDOW);

	/**
	*
	*/
	~Application();

	/**
	*
	*/
	void Render();

private:
	//! Puntero a la interfaz de Direct3D 9
	LPDIRECT3D9 mpDirect3DInterface;
	//! Puntero al dispositivo Direct3D 9
	LPDIRECT3DDEVICE9 mpDirect3DDevice;
};

}
}

#endif
