#include "Win32/Class.hpp"

namespace PaperBird
{
namespace Win32
{

//! TODO: Hasta que se permita la inicializacion homogenea de C++11, sera necesario esto.
const WNDCLASSEX EmptyWindowsClass = { sizeof(EmptyWindowsClass) };

Class::Class(HINSTANCE aInstance) :
	mWindowsClass(EmptyWindowsClass)
{
	SetClassStyle(WindowClassStyle(CS_HREDRAW | CS_VREDRAW));
	SetBackgroundColor(PaperBird::Win32::Color_WINDOW);
	SetDefaultCursor(Cursor_ARROW);

	mWindowsClass.hInstance = aInstance;
};

void Class::SetClassStyle(const WindowClassStyle &aClassStyle)
{
	mWindowsClass.style = aClassStyle.mClassStyle;
};

const WindowClassStyle Class::GetClassStyle() const
{
	return WindowClassStyle(mWindowsClass.style);
};

void Class::SetBackgroundColor(WindowsColors aColor)
{
	mWindowsClass.hbrBackground = reinterpret_cast<HBRUSH>(aColor);
};

void Class::SetDefaultCursor(DefaultCursors aCursor)
{
	mWindowsClass.hCursor = LoadCursor(NULL, MAKEINTRESOURCE(aCursor));
};

void Class::Register(const std::wstring &aName, WindowsMessageReceptor aCallback)
{
	mWindowsClass.lpszClassName = aName.c_str();
	mWindowsClass.lpfnWndProc = aCallback;
	RegisterClassEx(&mWindowsClass);
}

}
}

