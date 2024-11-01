#include <windows.h>
#pragma managed

bool running = true;

// Callback function to process messages sent to the window
LRESULT window_callback(
    HWND hwnd,
    UINT uMsg,
    WPARAM wParam,
    LPARAM lParam) {

    LRESULT result = 0;
    switch (uMsg) {
    case WM_CLOSE: {
        running = false;
        DestroyWindow(hwnd);
    } break;

    case WM_DESTROY: {
        PostQuitMessage(0);
    } break;

    default: {
        result = DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
    }
    return result;
}

// Entry point for the graphical window
int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {

    // Creating window class
    WNDCLASS window = {};
    window.style = CS_HREDRAW | CS_VREDRAW;
    window.lpszClassName = "Game Window";
    window.lpfnWndProc = window_callback; // Callback to process messages sent to the window

    // Register class
    RegisterClass(&window);

    // Creating the window with WS_OVERLAPPEDWINDOW style for standard window options
    HWND wind = CreateWindowA(window.lpszClassName, "Game", WS_OVERLAPPEDWINDOW | WS_VISIBLE,
        CW_USEDEFAULT, CW_USEDEFAULT, 1280, 720, 0, 0, hInstance, 0);

    while (running) {
        // Input
        MSG message;
        while (PeekMessage(&message, 0, 0, 0, PM_REMOVE)) {
            TranslateMessage(&message);
            DispatchMessage(&message);
        }

        // Simulate

        // Render
    }

    return 0;
}
