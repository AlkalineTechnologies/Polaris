// c++ standard
#include <string>

// X11 
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>

// Polaris
#include <Window.h>

//references
void INIT_XLIB(int height,  int width, std::string title);
void CLOSE_XLIB();
void REDRAW_XLIB();

typedef XID Wndw;
/*
    Display *display;
    Window parent;
    int x, y; 
    unsigned int width, height;
    unsigned int border_width;
    int depth;
    unsigned int class;
    Visual *visual
    unsigned long valuemask;
    XSetWindowAttributes *attributes;
*/


Display *display;
int screen;
Wndw window;
GC  Gcontxt; 
XEvent event;
KeySym key;
char KeyPressBuffer[256];
unsigned long white, black, red, green, blue, alpha;
unsigned long RGB(int r, int g, int b);

namespace Polaris {
    bool _show;
    std::string _Tt;
    int _w; int _h;
    bool _fullscreen;
    Window::Window(std::string Title, int width, int height, bool fullscreen, bool show){
        _Tt = Title;
        _w = width; _h = height;
        _fullscreen = fullscreen; _show = show;

        INIT_XLIB(_h, _w, _Tt);
        if (show){
            while (1){
                XNextEvent(display, &event);
            }
        }

    }
    void Window::show(){
        while(1){
            XNextEvent(display, &event);
        }
    }

}

void INIT_XLIB( int height,  int width, std::string title){
    display = XOpenDisplay((char *) 0);
    screen  = DefaultScreen(display);
    black   = BlackPixel(display, screen);
    white   = WhitePixel(display, screen);
    red     = RGB(255,0,0);
    green   = RGB(0,255,0);
    blue    = RGB(0,0,255);
    window  = XCreateSimpleWindow(display, DefaultRootWindow(display),0,0, width, height, 5, white, black);
    XSetStandardProperties(display, window, title.c_str(), NULL, None, NULL, 0, NULL);
    XSelectInput(display, window, ExposureMask | ButtonPressMask | KeyPressMask );
    Gcontxt = XCreateGC(display, window, 0,0);
    XSetBackground(display, Gcontxt, white);
    XSetForeground(display, Gcontxt, black);
    XMapRaised(display, window);
    

}
void REDRAW_XLIB(){
    XClearWindow(display, window);
}
void CLOSE_XLIB(){
    XFreeGC(display, Gcontxt);
    XDestroyWindow(display, window);
    // exit(0);
}
unsigned long RGB(int r, int g, int b){
    return b + (g << 8) + (r << 16);
}