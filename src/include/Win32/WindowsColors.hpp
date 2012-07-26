#ifndef PAPERBIRD_WIN32_WINDOWSCOLORS_H
#define PAPERBIRD_WIN32_WINDOWSCOLORS_H

#include <windows.h>

namespace PaperBird
{
namespace Win32
{

enum WindowsColors
{
	Control_Color_MSGBOX			= 0,
	Control_Color_EDIT				= 1,
	Control_Color_LISTBOX			= 2,
	Control_Color_BTN				= 3,
	Control_Color_DLG				= 4,
	Control_Color_SCROLLBAR			= 5,
	Control_Color_STATIC			= 6,

	Color_SCROLLBAR					= 0,
	Color_BACKGROUND				= 1,
	Color_ACTIVECAPTION				= 2,
	Color_INACTIVECAPTION			= 3,
	Color_MENU						= 4,
	Color_WINDOW					= 5,
	Color_WINDOWFRAME				= 6,
	Color_MENUTEXT					= 7,
	Color_WINDOWTEXT				= 8,
	Color_CAPTIONTEXT				= 9,
	Color_ACTIVEBORDER				= 10,
	Color_INACTIVEBORDER			= 11,
	Color_APPWORKSPACE				= 12,
	Color_HIGHLIGHT					= 13,
	Color_HIGHLIGHTTEXT				= 14,
	Color_BTNFACE					= 15,
	Color_BTNSHADOW					= 16,
	Color_GRAYTEXT					= 17,
	Color_BTNTEXT					= 18,
	Color_INACTIVECAPTIONTEXT		= 19,
	Color_BTNHIGHLIGHT				= 20,

#if(WINVER >= 0x0400)
	Color_3DDKSHADOW				= 21,
	Color_3DLIGHT					= 22,
	Color_INFOTEXT					= 23,
	Color_INFOBK					= 24,
#endif /* WINVER >= 0x0400 */

#if(WINVER >= 0x0500)
	Color_HOTLIGHT					= 26,
	Color_GRADIENTACTIVECAPTION		= 27,
	Color_GRADIENTINACTIVECAPTION	= 28,
#if(WINVER >= 0x0501)
	Color_MENUHILIGHT				= 29,
	Color_MENUBAR					= 30,
#endif /* WINVER >= 0x0501 */
#endif /* WINVER >= 0x0500 */

#if(WINVER >= 0x0400)
	Color_DESKTOP					= Color_BACKGROUND,
	Color_3DFACE					= Color_BTNFACE,
	Color_3DSHADOW					= Color_BTNSHADOW,
	Color_3DHIGHLIGHT				= Color_BTNHIGHLIGHT,
	Color_3DHILIGHT					= Color_BTNHIGHLIGHT,
	Color_BTNHILIGHT				= Color_BTNHIGHLIGHT,
#endif /* WINVER >= 0x0400 */
};

}
}

#endif
