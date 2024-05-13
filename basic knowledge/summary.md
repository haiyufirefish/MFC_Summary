1. Basic concepts
SDK: Software Development Kit
JDK: java development kit
IDE: integrated development environment, VS qt

API: application programming interface
WINAPI: System call under the windows platform, windows.h, calls the special interface provided by the system to obtain the resources provided by the system

Window: parent window and child window, client area and non-client area
Handle: structure variable, control logo, window handle HWND, icon handle: HICO

message queue
information
window procedure function



main()
WinMain() //WINAPI entry address

2. winAPI window program (#include <windows.h>)
1. Define the entry function WinMain()
2. Create a window
a) Design window class WNDCLASS (assign values to member variables)
b) Register window class
c)Create window
c) Display and update windows
3. Message loop
4. Window procedure function

MSDN: winAPI, MFC
MFC reference documentation

1.The first MFC program (pure code) (#include <afxwin.h>)

2.Application class CWinApp

3.Frame class CFrameWnd



~~~
class MyApp: public CWinApp
{
public:
	//MFC program entry point
	virtual BOOL InitInstance();
};

class MyFrame: public CFrameWnd
{
public:
	MyFrame();

private:
};
~~~



1) There is and is only one global application class object
2) Implement the function InitInstance() in the program entry function
A) Dynamically allocate space to the frame class MyFrame object (automatically call its constructor)
a) Create a window in the constructor function of the frame class MyFrame object CWnd::Create
B) Frame class object display window CWnd::ShowWindow
C) Framework class object update window CWnd::UpdateWindow
D) Save the frame class object pointer CWinThread::m_pMainWnd

Event handling:
message map
1. In the operating class, declare the message mapping macro
DECLARE_MESSAGE_MAP()
2. Corresponding .cpp definition macro
	BEGIN_MESSAGE_MAP(MyFrame, CFrameWnd) //Derived class name, base class name
	ON_WM_LBUTTONDOWN() //Message mapping entry flag
	END_MESSAGE_MAP()
	
3. Declaration of the message processing function in the corresponding class

4. Corresponding to the definition of .cpp message processing function

4. Create a project according to the wizard
1. Document view structure
Documentation: It is a class that is specially used to store loading (read and write) data
View: It is a class that is specially used to display and modify data.

Framework class: a container that holds views



2. Some important functions
a) Application class CWinApp: InitInstance(), the entry address of the program
b) Frame class CFrameWnd:
PreCreateWindow() is called before creating the window
OnCreate() triggers WM_CREATE after creating the window. It is the processing function of the WM_CREATE message.
c) View class CView:
OnDraw(): drawing
WM_PAINT message processing function OnPaint() internally calls OnDraw()
OnPaint() and OnDraw() exist at the same time, only OnPaint() is valid

3. Adding and deleting events
	a) The difference between frame and view
	Add event step: Select the required class -> Right-click -> Properties -> Message -> WM_LBUTTONDOW -> ADD
		

The frame is equivalent to the container, and the container holds the view
The view is equivalent to the wallpaper. When we click on the window, only the view responds. The frame is blocked by the view and cannot respond.



4. Character set
ANSI multibyte (single byte)
char p[] = "abcdet"; //One character, one byte

unicode wide byte, 2 bytes per character
TCHAR *p = L"abc"; //One character 2 bytes
wcslen(p);

MFC:
TCHAR: automatically adapts to bytes (conditional compilation), equivalent to char

TEXT()
_T()



5. Expansion
afx_xxxx: global function, not unique to a certain class
xxxEx: xxxW, extension

MFC naming convention:
Class names and function names: initial letter size of words
classMyClass
{
};

void SetName()
{
}

Function parameter: starting from the second word, the first letter is capitalized
isFlag
isPressTest

Member variables:
m_xxxx
m_hWnd



