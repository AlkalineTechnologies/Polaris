#ifdef __linux__

// polaris
#include <Window.h>
#include <Linux/LINUX_WM.hpp>
#include <Inputs.h>
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
#include <cstring>
#include <string>
#include <thread>
 
uint32_t window_mask            = XCB_CW_BACK_PIXEL | XCB_CW_EVENT_MASK;
uint32_t window_properties[32]  ; 


// void Init_XCB(int width, int height, const char *title) {
    
//     xcb_create_window(connection, 
//                         XCB_COPY_FROM_PARENT, 
//                         window, 
//                         screen->root, 
//                         0, 0, 
//                         width, 
//                         height, 0, 
//                         XCB_WINDOW_CLASS_INPUT_OUTPUT,
//                         screen->root_visual, window_mask, 
//                         window_properties);

//     xcb_change_property (connection,
//                             XCB_PROP_MODE_REPLACE,
//                             window,
//                             XCB_ATOM_WM_NAME,
//                             XCB_ATOM_STRING,
//                             8,
//                             std::strlen (title),
//                             title );
    
//     xcb_map_window(connection, window);
//     xcb_flush(connection);

// }




namespace Polaris{
    Polaris::Window::Window(std::string title, int width, int height, bool fullscreen, bool show) {
        
        // Xdisplay    = XOpenDisplay(NULL);
        // connection  = XGetXCBConnection(Xdisplay);
        // screen      = xcb_setup_roots_iterator(xcb_get_setup(connection)).data;
        // window      = xcb_generate_id(connection);
        window_properties[0] = screen->white_pixel;
        window_properties[1] = XCB_EVENT_MASK_EXPOSURE | XCB_EVENT_MASK_KEY_PRESS | XCB_EVENT_MASK_KEY_RELEASE | XCB_EVENT_MASK_BUTTON_PRESS | XCB_EVENT_MASK_BUTTON_RELEASE | XCB_EVENT_MASK_POINTER_MOTION | XCB_EVENT_MASK_ENTER_WINDOW | XCB_EVENT_MASK_LEAVE_WINDOW;
        this->_title = title;
        xcb_create_window(this->connection, 
                        XCB_COPY_FROM_PARENT, 
                        this->window, 
                        screen->root, 
                        0, 0, 
                        width, 
                        height, 0, 
                        XCB_WINDOW_CLASS_INPUT_OUTPUT,
                        screen->root_visual, window_mask, 
                        window_properties);

        xcb_change_property (this->connection,
                            XCB_PROP_MODE_REPLACE,
                            this->window,
                            XCB_ATOM_WM_NAME,
                            XCB_ATOM_STRING,
                            8,
                            title.size(),
                            title.c_str() );
    
        xcb_map_window(this->connection, window);
        xcb_flush(this->connection);
       
        if (show){
            this->show();
        }
            this->Fullscreen(fullscreen);
    }

    void Polaris::Window::setTitle(std::string title) {
        xcb_change_property (this->connection,
                             XCB_PROP_MODE_REPLACE,
                             this->window,
                             XCB_ATOM_WM_NAME,
                             XCB_ATOM_STRING,
                             8,
                             std::strlen (title.c_str()),
                             title.c_str() );
        xcb_flush(this->connection);
    }
    void Polaris::Window::Fullscreen(bool state) {
        if (state){
            uint32_t pos[] ={0,0};
            xcb_configure_window(this->connection, this->window, XCB_CONFIG_WINDOW_X | XCB_CONFIG_WINDOW_X, pos);
            Atom window_type = XInternAtom(this->Xdisplay, "_NET_WM_WINDOW_TYPE", False);
            long value = XInternAtom(this->Xdisplay, "_NET_WM_WINDOW_TYPE_DOCK", False);
            XChangeProperty(this->Xdisplay, this->window, window_type, 4, 32, PropModeReplace, (unsigned char *) &value, 1);
    

            const static uint32_t values[] = { screen->width_in_pixels, screen->height_in_pixels, 0, 0};
            
            xcb_configure_window (this->connection, 
                this->window, 
                XCB_CONFIG_WINDOW_WIDTH | XCB_CONFIG_WINDOW_HEIGHT | XCB_CONFIG_WINDOW_X | XCB_CONFIG_WINDOW_Y,
                values);

            xcb_flush(this->connection);
        } else{
            Atom window_type = XInternAtom(this->Xdisplay, "_NET_WM_WINDOW_TYPE", False);
            long value = XInternAtom(this->Xdisplay, "_NET_WM_WINDOW_TYPE_NORMAL", False);
            XChangeProperty(this->Xdisplay, this->window, window_type, 4, 32, PropModeReplace, (unsigned char *) &value, 1);
    

            const static uint32_t values[] = { _width, _height };
            xcb_configure_window (this->connection, 
                this->window, 
                XCB_CONFIG_WINDOW_WIDTH | XCB_CONFIG_WINDOW_HEIGHT ,
                values);

            xcb_flush(connection);
        }
    }
    void Polaris::Window::show() {
        xcb_map_window(this->connection, this->window);
        xcb_flush(this->connection);
    };
    void Polaris::Window::hide() {
        xcb_unmap_window(this->connection, this->window);
        xcb_flush(this->connection);
    };
        
    
    void Polaris::Window::close(){
        xcb_destroy_window(this->connection, this->window);
        xcb_disconnect(this->connection);
    }
    Polaris::InputStream Polaris::Window::getInputStream() {

    };

    void Polaris::Window::EventLoop(){
    // poll events for a specific xcb window
    while ((this->event =  xcb_wait_for_event(this->connection)) != NULL) {
        
        switch (event->response_type & ~0x80) {
            case XCB_EXPOSE:
                {
                    xcb_expose_event_t *expose = (xcb_expose_event_t *) event;
                    std::cout << "XCB_EXPOSE" << std::endl;
                }
                break;
            case XCB_CLIENT_MESSAGE:
                {
                    xcb_client_message_event_t *msg = (xcb_client_message_event_t *) event;
                    std::cout << "XCB_CLIENT_MESSAGE" << std::endl;
                }
                break;
            case XCB_KEY_PRESS:
                {
                    xcb_key_press_event_t *kpress = (xcb_key_press_event_t *) event;
                    // xcb_get_property(connection,);
                    std::cout << "XCB_KEY_PRESS: " << kpress->detail  << "from: " << this->_title << std::endl;
                }
                break;
            case XCB_KEY_RELEASE:
                {
                    xcb_key_release_event_t *key_event = (xcb_key_release_event_t *)event;
                    xcb_key_press_event_t *kp = (xcb_key_press_event_t *)event;
                    // print the pressed the key
                    std::cout << "XCB_KEY_RELEASE: " << (int)kp->detail << std::endl;

                    // std::cout << ">>ID:    " << (int) kp->response_type << std::endl;
                }
                break;
            case XCB_BUTTON_PRESS:
                {
                    xcb_button_press_event_t *BtnPress = (xcb_button_press_event_t *) event;
                    std::cout << "XCB_BUTTON_PRESS" << std::endl;
                }
                break;
            case XCB_BUTTON_RELEASE:
                {
                    xcb_button_release_event_t *BtnRls = (xcb_button_release_event_t *) event;
                    std::cout << "XCB_BUTTON_RELEASE" << std::endl;
                }
                break;
            case XCB_MOTION_NOTIFY:
                {
                    xcb_motion_notify_event_t *MTNntf = (xcb_motion_notify_event_t *) event;
                    std::cout << "XCB_MOTION_NOTIFY" << std::endl;
                }
                break;
            default:
                std::cout << "UNKNOWN" << std::endl;
                break;
        }
            free(event);
            std::cout.flush();
        }
    }
}
#endif