#pragma once


// Win32 data types, compatable with windows.h, but doesn't require windows.h


typedef long LONG;
typedef unsigned int UINT;
typedef unsigned long ULONG;
typedef __int64 LONGLONG;
typedef UINT WPARAM;
typedef LONG LPARAM;
typedef unsigned long DWORD;

typedef DWORD COLORREF;


#define MakeHandleType(name) typedef struct name##__* name

MakeHandleType(HINSTANCE);
MakeHandleType(HHOOK);
MakeHandleType(HACCEL);
MakeHandleType(HMENU);
MakeHandleType(HWND);
MakeHandleType(HDC);
MakeHandleType(HFONT);
MakeHandleType(HICON);
MakeHandleType(HBITMAP);
MakeHandleType(HPALETTE);

typedef HICON HCURSOR;
