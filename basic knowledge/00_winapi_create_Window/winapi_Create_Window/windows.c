#include <windows.h>

//window procedure function
LRESULT CALLBACK DealMessage(HWND hWnd, //Window handle, the window to which the message belongs
	UINT uMsg,	//message sign
	WPARAM wParam, // additional Information
	LPARAM lParam
	)
{
	switch (uMsg)
	{
	case WM_LBUTTONDOWN: // left click
		MessageBox(hWnd, TEXT("MCdonals"), TEXT("left click"), MB_OK);
		break;
	case WM_RBUTTONDOWN :

		MessageBox(hWnd, TEXT("KFC"), TEXT("right click"), MB_OK);
		break;
	case WM_PAINT:
	{
					 PAINTSTRUCT ps; //create paint struct
					 HDC dc = BeginPaint(hWnd, &ps); // begin
					 TCHAR * p = L"aaaaaaa"; // change to wide charater
					 TextOutW(dc, 300, 15, p, wcslen(p));

					 EndPaint(hWnd, &ps);
					 break;
	}

	case WM_DESTROY:
		PostQuitMessage(2); //WM_QUIT, back to main, return msg.wParam
		break;
	default:
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}


	return 0;
}


//WINAPI: Modify the function and stipulate that the function parameters are pushed into the stack from right to left.
// After the function call is completed, the stack is automatically cleared.
//CALLBACK
int WINAPI WinMain(HINSTANCE hInstance, //Application instance
	HINSTANCE hPrevInstance, //Previous application instance, not use
	LPSTR lpCmdLine, //Command line parameters
	int nCmdShow //Window display style, maximize, minimize
	)
{
	/*
	1. Define the entry function WinMain()
	2. Create a window
	a) Design window class WNDCLASS (assign values to member variables)
	b) Register window class
	c) Create window class
	d) Display and update windows
	3. Message loop
	4. Window procedure function
	*/

	//Design window class WNDCLASS (assign values to member variables)
	WNDCLASS wc;
	wc.cbClsExtra = 0; //Additional information about the class
	//wc.style = CS_HREDRAW;
	wc.cbWndExtra = 0; 
						//Get the system default white brush
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); //Background color, must be written

	//wc.hCursor = NULL;//default cursor
	wc.hCursor = LoadCursor(NULL, IDC_HELP); //Load system default cursor
	//wc.hIcon = NULL; 
	wc.hIcon = LoadIcon(NULL, IDI_WARNING); //Load system default icon

	wc.hInstance = hInstance; //instace of application
	wc.lpfnWndProc = DealMessage; //Window procedure function name, message processing function

	wc.lpszClassName = TEXT("abc"); //class name
	wc.lpszMenuName = NULL; //menu name
	wc.style = nCmdShow; //display style

	//b)Register the window class and tell the system the entry address of the window procedure function
	RegisterClass(&wc);

	//c)create windows class
	HWND hWnd = CreateWindow(TEXT("abc"), TEXT("hello, windwos"), WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		NULL, NULL, hInstance, NULL);

	//d)Show and update windows
	ShowWindow(hWnd,SW_SHOWMAXIMIZED);
	UpdateWindow(hWnd);

	//message loop
	MSG msg;
	//If WM_QUIT is received, return 0 and exit.
	//If an error occurs, return -1 and do not exit.
	while (GetMessage(&msg, NULL, 0, 0))
	{
		//Convert virtual keys to standard characters WM_CHAR
		TranslateMessage(&msg);

		//Distribute messages to the operating system
		DispatchMessage(&msg);
	}

	return msg.wParam;
	//

}