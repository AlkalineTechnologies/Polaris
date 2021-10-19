//
// Created by Lysander Mealy on 10/18/21.
//

#ifdef _WIN32

#include "../Window.h"

#include <Windows.h>

std::wstring stringToWideString(const std::string& s)
{
    int len;
    int slength = (int)s.length() + 1;
    len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
    wchar_t* buf = new wchar_t[len];
    MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
    std::wstring r(buf);
    delete[] buf;
    return r;
}

namespace Polaris {
    LRESULT CALLBACK WindowProcA(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

    Polaris::Window::Window(std::string title, int width, int height, bool fullscreen, bool show) {
        _title = title;
        _width = width;
        _height = height;

        WNDCLASSA wc = {};

        wc.lpfnWndProc = WindowProcA;
        wc.hInstance = GetModuleHandleW(nullptr);
        wc.lpszClassName = "Polaris Engine";

        RegisterClassA(&wc);

        width = fullscreen ? GetSystemMetrics(SM_CXSCREEN) : CW_USEDEFAULT;
        height = fullscreen ? GetSystemMetrics(SM_CYSCREEN) : CW_USEDEFAULT;

        _window = CreateWindowExA(
            0,
            "Polaris Engine",
            title.c_str(),
            fullscreen ? WS_OVERLAPPEDWINDOW ^ WS_CAPTION : WS_OVERLAPPEDWINDOW,

            CW_USEDEFAULT, CW_USEDEFAULT, width, height,

            NULL,
            NULL,
            GetModuleHandleA(nullptr),
            NULL
            );

        if (show) {
            ShowWindow((HWND)_window, SW_SHOW);
        }
    }

    void Polaris::Window::setTitle(std::string title) {
        SetWindowTextA((HWND)_window,title.c_str());
    }

    void Polaris::Window::show() {
        ShowWindow((HWND)_window, SW_SHOW);
    }

    void Polaris::Window::hide() {
        ShowWindow((HWND)_window, SW_HIDE);
    }

    LRESULT CALLBACK WindowProcA(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
        switch (uMsg)
        {
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;

        case WM_PAINT:
            {
                PAINTSTRUCT ps;
                HDC hdc = BeginPaint(hWnd, &ps);



                FillRect(hdc, &ps.rcPaint, (HBRUSH) (COLOR_WINDOW+1));

                EndPaint(hWnd, &ps);
            }
            return 0;

        }
        return DefWindowProcA(hWnd, uMsg, wParam, lParam);
    }
}
#endif