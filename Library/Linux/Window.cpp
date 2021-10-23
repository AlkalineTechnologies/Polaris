#ifdef __linux__

// polaris
#include <Window.h>
#include <Linux/xcb_Winevents.hpp>

// xcb libraries
#include <xcb/xcb.h>
#include <xcb/xproto.h>
#include <xcb/xcb_ewmh.h>


// c++ standard library
#include <unistd.h>
#include <iostream>
#include <string>
#include <cstring>
#include <future>



xcb_connection_t *connection    = xcb_connect(NULL, NULL);
xcb_screen_t *screen            = xcb_setup_roots_iterator(xcb_get_setup(connection)).data;
xcb_window_t window             = xcb_generate_id(connection);
xcb_generic_event_t *event; 

void Init_XCB(int width, int height, const char *title) {
    xcb_create_window(connection, XCB_COPY_FROM_PARENT, window, screen->root, 0, 0, width, height, 0, XCB_WINDOW_CLASS_INPUT_OUTPUT, screen->root_visual, 0, NULL);
    
    xcb_change_property (connection,
                             XCB_PROP_MODE_REPLACE,
                             window,
                             XCB_ATOM_WM_NAME,
                             XCB_ATOM_STRING,
                             8,
                             std::strlen (title),
                             title );
    xcb_map_window(connection, window);
    xcb_flush(connection);

}
void disconnect_XCB() {
    xcb_disconnect(connection);
}

namespace Polaris{
    Polaris::Window::Window(std::string title, int width, int height, bool fullscreen, bool show) {
        Init_XCB(width, height, title.c_str());
        if (show){
            this->show();
        }
    };

    void Polaris::Window::setTitle(std::string title) {
        xcb_change_property (connection,
                             XCB_PROP_MODE_REPLACE,
                             window,
                             XCB_ATOM_WM_NAME,
                             XCB_ATOM_STRING,
                             8,
                             std::strlen (title.c_str()),
                             title.c_str() );
        xcb_flush(connection);
    }

    void Polaris::Window::show() {
        xcb_map_window(connection, window);
        xcb_flush(connection);
    };
    void Polaris::Window::hide() {
        xcb_unmap_window(connection, window);
        xcb_flush(connection);
    };

}


// void CLOSE_XLIB(){
//     XFreeGC(display, Gcontxt);
//     XDestroyWindow(display, window);
//     // exit(0);
// }
// unsigned long RGB(int r, int g, int b){
//     return b + (g << 8) + (r << 16);
// }
#endif