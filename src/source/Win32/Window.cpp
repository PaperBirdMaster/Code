// Inclusiones propias.
#include "Win32/Window.hpp"
#include "Win32/Class.hpp"

namespace PaperBird
{
namespace Win32
{

Win32Events EventManager;

Window::Window(const std::wstring &aName, HINSTANCE aInstance, const std::wstring &aCaption, const RECT &aRect, WindowExtendedStyle aXStyle, WindowStyle aStyle) :
	mWindow(nullptr),
	mReturnValue(1)
{
	// Creamos y Registramos el WindowClass ( http://msdn.microsoft.com/en-us/library/windows/desktop/ms633576(v=vs.85).aspx ).
	Class WindowClass(aInstance);
	WindowClass.Register(aName, Window::ProcessMessages);

	// Creamos la Ventana ( http://msdn.microsoft.com/en-us/library/windows/desktop/ms632680(v=vs.85).aspx ).
	mWindow = CreateWindowEx(aXStyle, aName.c_str(), aCaption.c_str(), aStyle, aRect.left, aRect.top, aRect.right, aRect.bottom, NULL, NULL, aInstance, NULL);

	// Nos apuntamos a los eventos importantes de Windows.
	EventManager.AddListener(WM_DESTROY, *this, &Window::OnDestroy);
	EventManager.AddListener(WM_QUIT, *this, &Window::OnQuit);
};

int Window::IsActive()
{
	// Estructura en que se almacenan mensajes de Windows.
	MSG WindowsMessage = {0};

	// Bucle de captura de mensajes de Windows.
	if (PeekMessage(&WindowsMessage, NULL, 0, 0, PM_REMOVE))
	{
		// Traduce (si procede) el mensaje y...
		TranslateMessage(&WindowsMessage);
		// ... lo envia a su destinatario.
		DispatchMessage(&WindowsMessage);
		EventManager.SendEvent(WindowsMessage.message, Win32Events::EventData(WindowsMessage.wParam, WindowsMessage.lParam));
	}

	return mReturnValue;
}

void Window::AddMenu(const std::wstring &aMenuName, UINT aMenuCode)
{
	HMENU hMenu, hSubMenu;

	hMenu = CreateMenu();

	hSubMenu = CreatePopupMenu();
	AppendMenu(hSubMenu, MF_STRING, 9001, L"E&xit");
	AppendMenu(hMenu, MF_STRING | MF_POPUP, (UINT)hSubMenu, L"&File");

	hSubMenu = CreatePopupMenu();
	AppendMenu(hSubMenu, MF_STRING, 9002, L"&Go");
	AppendMenu(hMenu, MF_STRING | MF_POPUP, (UINT)hSubMenu, L"&Stuff");

	SetMenu(mWindow, hMenu);
};

void Window::SetVisible(bool aVisible)
{
	ShowWindow(mWindow, aVisible? SW_SHOW: SW_HIDE);
};

void Window::OnDestroy(const std::pair<WPARAM, LPARAM> aData)
{
	PostQuitMessage(0);
};

void Window::OnQuit(const std::pair<WPARAM, LPARAM> aData)
{
	mReturnValue = aData.first;
};

LRESULT CALLBACK Window::ProcessMessages(HWND aReceptorWindow, UINT aMessageCode, WPARAM wParam, LPARAM lParam)
{
	LRESULT Result = 0;

	if (!EventManager.SendEvent(aMessageCode, Win32Events::EventData(wParam, lParam)))
	{
		Result = DefWindowProc(aReceptorWindow, aMessageCode, wParam, lParam);
	}

	return Result;
}

}
}
