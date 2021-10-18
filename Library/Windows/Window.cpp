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
    LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

    Polaris::Window::Window(std::string title, int width, int height, bool fullscreen, bool show) {
        _title = title;
        _width = width;
        _height = height;

        WNDCLASS wc = {};

        wc.lpfnWndProc = WindowProc;
        wc.hInstance = GetModuleHandle(nullptr);
        wc.lpczClassName = L"Polaris Engine";

        RegisterClass(&wc);

        window = CreateWindowEx(
            0,
            CLASS_NAME,
            stringToWideString(title).c_str(),
            WS_OVERLAPPEDWINDOW,

            CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

            NULL,
            NULL,
            hInstance,
            NULL
            );

        if (show) {
            ShowWindow((HWND)window, SW_SHOW);
        }
    }

    Polaris::Window::setTitle(std::string title) {
        SetWindowText((HWND)window, stringToWideString(title).c_str());
    }

    Polaris::Window::show() {
        ShowWindow((HWND)window, SW_SHOW);
    }

    Polaris::Window::hide() {
        ShowWindow((HWND)window, SW_HIDE);
    }

    LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
        switch (uMsg)
        {
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;

        case WM_PAINT:
            {
                PAINTSTRUCT ps;
                HDC hdc = BeginPaint(hwnd, &ps);



                FillRect(hdc, &ps.rcPaint, (HBRUSH) (COLOR_WINDOW+1));

                EndPaint(hwnd, &ps);
            }
            return 0;

        }
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
}
#endif