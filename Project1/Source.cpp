#include <windows.h>
#pragma managed

bool running = true;

//callback function
LRESULT window_callback(
	HWND Param1,
	UINT Param2,
	WPARAM Param3,
	LPARAM Param4
) {
	return DefWindowProc(Param1, Param2, Param3, Param4);
}
//winmain is the entry point for graphical window
int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine,int nShowCmd){ 

	//creating window class
	WNDCLASS window = {};
	window.style = CS_HREDRAW | CS_VREDRAW;
	window.lpszClassName = "Game Window";
	window.lpfnWndProc = window_callback; //callback to proccess messages sent to the window

	//register class
	RegisterClass(&window);  //passing the pointer to the window

	//creating window
	CreateWindowA(window.lpszClassName, "Game", WS_OVERLAPPED | WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT, 1280, 720, 0, 0, hInstance, 0);

	while (running) {
		//input

		//simulate

		//render
	}

}