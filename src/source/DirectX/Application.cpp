// Inclusiones propias.
#include "DirectX/Application.hpp"

namespace PaperBird
{
namespace DirectX
{

Application::Application(const std::wstring &aName, HINSTANCE aInstance,
		const std::wstring &aCaption, const RECT &aRect, Win32::WindowExtendedStyle aXStyle, Win32::WindowStyle aStyle) :
	Win32::Window(aName, aInstance, aCaption, aRect, aXStyle, aStyle)
{
	mpDirect3DInterface = Direct3DCreate9(D3D_SDK_VERSION);

	D3DPRESENT_PARAMETERS D3DPresentParameters = { sizeof(D3DPresentParameters) };

	D3DPresentParameters.Windowed = TRUE;
	D3DPresentParameters.SwapEffect = D3DSWAPEFFECT_DISCARD;
	D3DPresentParameters.hDeviceWindow = mWindow;

	// create a device class using this information and information from the d3dpp stuct
	mpDirect3DInterface->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, mWindow, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &D3DPresentParameters, &mpDirect3DDevice);
};

Application::~Application()
{
	mpDirect3DInterface->Release();
	mpDirect3DDevice->Release();
}

void Application::Render()
{
	// clear the window to a deep blue
	mpDirect3DDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 40, 100), 1.0f, 0);

	// begins the 3D scene
	mpDirect3DDevice->BeginScene();

	// do 3D rendering on the back buffer here
	mpDirect3DDevice->EndScene();	// ends the 3D scene

	// displays the created frame
	mpDirect3DDevice->Present(NULL, NULL, NULL, NULL);
}

}
}
