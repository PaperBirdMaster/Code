#include "Win32/Window.hpp"



#include <d3d9.h>
#pragma comment (lib, "d3d9.lib")

LPDIRECT3D9 d3d;			// the pointer to our Direct3D interface
LPDIRECT3DDEVICE9 d3ddev;	// the pointer to the device class

	// sets up and initializes Direct3D
void initD3D(const HWND hWnd)
{
	d3d = Direct3DCreate9(D3D_SDK_VERSION);		// create the Direct3D interface

	D3DPRESENT_PARAMETERS d3dpp;				// create a struct to hold various device information

	ZeroMemory(&d3dpp, sizeof(d3dpp));			// clear out the struct for use
	d3dpp.Windowed = TRUE;						// program windowed, not fullscreen
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;	// discard old frames
	d3dpp.hDeviceWindow = hWnd;					// set the window to be used by Direct3D

	// create a device class using this information and information from the d3dpp stuct
	d3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &d3ddev);
};

// renders a single frame
void render_frame(void)
{
	// clear the window to a deep blue
	d3ddev->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 40, 100), 1.0f, 0);

	// begins the 3D scene
	d3ddev->BeginScene();

	// do 3D rendering on the back buffer here
	d3ddev->EndScene();	// ends the 3D scene

	// displays the created frame
	d3ddev->Present(NULL, NULL, NULL, NULL);
}

// closes Direct3D and releases memory
void cleanD3D(void)
{
	d3ddev->Release();		// close and release the 3D device
	d3d->Release();			// close and release Direct3D
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// Preparamos la Ventana de la aplicacion.
	PaperBird::Win32::Window Window(L"WindowClass1", hInstance, L"Our First Windowed Program");

	// Mostramos la Ventana de la aplicacion.
	Window.SetVisible(true);

	// Valor de retorno del proceso de la ventana; cuando sea diferente a 0 debemos finalizar.
	int ReturnValue = 0;

	initD3D(Window.GetHandlerWindow());

	while ((ReturnValue = Window.IsActive()))
	{
		render_frame();
	};

	cleanD3D();

	return ReturnValue;
}
