#ifndef PAPERBIRD_WIN32_CLASS_H
#define PAPERBIRD_WIN32_CLASS_H

// Inclusiones STL.
#include <string>

// Inclusiones de la plataforma.
#include <windows.h>
#include <windowsx.h>

// Inclusiones propias.
#include "WindowClassStyle.hpp"
#include "WindowsColors.hpp"
#include "DefaultCursors.hpp"

namespace PaperBird
{
namespace Win32
{

//! 
typedef LRESULT (CALLBACK *WindowsMessageReceptor)(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

class Class
{
public:

	/**
	*
	*/
	Class(HINSTANCE aInstance);

	/**
	*
	*/
	void SetClassStyle(const WindowClassStyle &aClassStyle);

	/**
	*
	*/
	const WindowClassStyle Class::GetClassStyle() const;

	/**
	*
	*/
	void SetBackgroundColor(WindowsColors aColor);

	/**
	*
	*/
	void SetDefaultCursor(DefaultCursors aCursor);

	/**
	*
	*/
	void Register(const std::wstring &aName, WindowsMessageReceptor aCallback);

private:

	//! 
	WNDCLASSEX mWindowsClass;
};

}
}

#endif
