#ifdef __linux__

// polaris
#include <Window.h>
#include <Linux/xcb_Winevents.hpp>

// xcb libraries
#include <xcb/xcb.h>
#include <xcb/xproto.h>
#include <xcb/xcb_ewmh.h>
#include  <xcb/xcb_atom.h>
// X11 libraries
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xatom.h>
#include <X11/Xlib-xcb.h>

// c++ standard library
#include <unistd.h>
#include <iostream>
#include <string>
#include <cstring>
#include <future>


int _width, _height;
Display *Xdisplay               = XOpenDisplay(NULL);
xcb_connection_t *connection    = XGetXCBConnection(Xdisplay);
xcb_screen_t *screen            = xcb_setup_roots_iterator(xcb_get_setup(connection)).data;
xcb_window_t window             = xcb_generate_id(connection);
xcb_generic_event_t *event; 
uint32_t window_mask = XCB_CW_BACK_PIXEL | XCB_CW_EVENT_MASK;
uint32_t window_properties[32] = {
    /* 0 */ screen->white_pixel,
    /* 1 */ XCB_EVENT_MASK_EXPOSURE | XCB_EVENT_MASK_KEY_PRESS | XCB_EVENT_MASK_KEY_RELEASE | XCB_EVENT_MASK_BUTTON_PRESS | XCB_EVENT_MASK_BUTTON_RELEASE | XCB_EVENT_MASK_POINTER_MOTION | XCB_EVENT_MASK_ENTER_WINDOW | XCB_EVENT_MASK_LEAVE_WINDOW
    /* 2 */
};



void Init_XCB(int width, int height, const char *title) {
    xcb_create_window(connection, 
                        XCB_COPY_FROM_PARENT, 
                        window, 
                        screen->root, 
                        0, 0, 
                        width, 
                        height, 0, 
                        XCB_WINDOW_CLASS_INPUT_OUTPUT,
                        screen->root_visual, window_mask, 
                        window_properties);

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
    xcb_destroy_window(connection, window);
    xcb_disconnect(connection);
}

namespace Polaris{
    Polaris::Window::Window(std::string title, int width, int height, bool fullscreen, bool show) {
        _width = width;
        _height = height;
        Init_XCB(width, height, title.c_str());
        if (show){
            this->show();
        }
        if (fullscreen){
            this->Fullscreen();
        }
    }

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
    void Polaris::Window::Fullscreen(bool state) {
        if (state){
            Atom window_type = XInternAtom(Xdisplay, "_NET_WM_WINDOW_TYPE", False);
            long value = XInternAtom(Xdisplay, "_NET_WM_WINDOW_TYPE_DOCK", False);
            XChangeProperty(Xdisplay, window, window_type, 4, 32, PropModeReplace, (unsigned char *) &value, 1);
    

            const static uint32_t values[] = { screen->width_in_pixels, screen->height_in_pixels, 0 };
            /* Resize the window to width = 200 and height = 300 */
            xcb_configure_window (connection, 
                window, 
                XCB_CONFIG_WINDOW_WIDTH | XCB_CONFIG_WINDOW_HEIGHT | XCB_CONFIG_WINDOW_BORDER_WIDTH,
                values);

            xcb_flush(connection);
        } else{
            Atom window_type = XInternAtom(Xdisplay, "_NET_WM_WINDOW_TYPE", False);
            long value = XInternAtom(Xdisplay, "_NET_WM_WINDOW_TYPE_NORMAL", False);
            XChangeProperty(Xdisplay, window, window_type, 4, 32, PropModeReplace, (unsigned char *) &value, 1);
    

            const static uint32_t values[] = { _width, _height };
            xcb_configure_window (connection, 
                window, 
                XCB_CONFIG_WINDOW_WIDTH | XCB_CONFIG_WINDOW_HEIGHT ,
                values);

            xcb_flush(connection);
        }
    }
    void Polaris::Window::show() {
        xcb_map_window(connection, window);
        xcb_flush(connection);
    };
    void Polaris::Window::hide() {
        xcb_unmap_window(connection, window);
        xcb_flush(connection);
    };

};

#endif