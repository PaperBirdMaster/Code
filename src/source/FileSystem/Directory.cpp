// Inclusiones Propias.
#include "Directory.hpp"

namespace PaperBird
{
namespace FileSystem
{

Directory::Directory() :
	mPath(L""),
	mName(L""),
	mAttributes(0)
{
	wchar_t Path[MAX_PATH] = {L'\0'};
	GetCurrentDirectoryW(MAX_PATH, Path);

	mAttributes = GetFileAttributesW(Path);

	mPath = Path;
	mName = Path;
};

Directory::Directory(const std::string &aPath) :
	mPath(L""),
	mName(L""),
	mAttributes(GetFileAttributesA(aPath.c_str()))
{
	//INVALID_FILE_ATTRIBUTES 
};

Directory::Directory(const std::wstring &aPath) :
	mPath(L""),
	mName(L""),
	mAttributes(GetFileAttributesW(aPath.c_str()))
{
};

}
}
