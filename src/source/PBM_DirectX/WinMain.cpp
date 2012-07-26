#include "Win32/Window.hpp"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// Preparamos la Ventana de la aplicacion.
	PaperBird::Win32::Window Window(L"WindowClass1", hInstance, L"Our First Windowed Program");

	// Mostramos la Ventana de la aplicacion.
	Window.SetVisible(true);

	// Valor de retorno del proceso de la ventana; cuando sea diferente a 0 debemos finalizar.
	int ReturnValue = 0;

	while ((ReturnValue = Window.IsActive()))
	{
	};

	return ReturnValue;
}
