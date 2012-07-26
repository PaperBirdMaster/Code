#ifndef PAPERBIRD_WIN32_WINDOWCLASSSTYLE_H
#define PAPERBIRD_WIN32_WINDOWCLASSSTYLE_H

#include <windows.h>

namespace PaperBird
{
namespace Win32
{

union WindowClassStyle
{
	explicit WindowClassStyle(UINT aClassStyle = 0) :
		mClassStyle(aClassStyle) {};

	struct ClassStyle
	{
		bool VREDRAW			: 1;
		bool HREDRAW			: 1;
		bool DBLCLKS			: 1;
		bool OWNDC				: 1;
		bool CLASSDC			: 1;
		bool PARENTDC			: 1;
		bool NOCLOSE			: 1;
		bool SAVEBITS			: 1;
		bool BYTEALIGNCLIENT	: 1;
		bool BYTEALIGNWINDOW	: 1;
		bool GLOBALCLASS		: 1;
	} mFlags;

	UINT mClassStyle;
};

}
}

#endif
