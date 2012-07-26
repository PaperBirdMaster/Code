#ifndef PAPERBIRD_WIN32_DEFAULTCURSORS_H
#define PAPERBIRD_WIN32_DEFAULTCURSORS_H

#include <windows.h>

namespace PaperBird
{
namespace Win32
{

enum DefaultCursors
{
	Cursor_ARROW		= 32512,
	Cursor_IBEAM		= 32513,
	Cursor_WAIT			= 32514,
	Cursor_CROSS		= 32515,
	Cursor_UPARROW		= 32516,
	Cursor_SIZE			= 32640,
	Cursor_ICON			= 32641,
	Cursor_SIZENWSE		= 32642,
	Cursor_SIZENESW		= 32643,
	Cursor_SIZEWE		= 32644,
	Cursor_SIZENS		= 32645,
	Cursor_SIZEALL		= 32646,
	Cursor_NO			= 32648,
#if(WINVER >= 0x0500)
	Cursor_HAND			= 32649,
#endif /* WINVER >= 0x0500 */
	Cursor_APPSTARTING	= 32650,
#if(WINVER >= 0x0400)
	Cursor_HELP			= 32651,
#endif /* WINVER >= 0x0400 */
};

}
}

#endif
