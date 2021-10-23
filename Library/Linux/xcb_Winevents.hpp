#ifndef __LINUX_WINDOW_EVENTS_HPP__
#define __LINUX_WINDOW_EVENTS_HPP__


#include <xcb/xcb.h>
#include <xcb/xcb_ewmh.h>
#include <iostream>

extern xcb_connection_t *connection;
extern xcb_screen_t *screen;        
extern xcb_window_t window;         
extern xcb_generic_event_t *event; 


static void Window_Loop(){
    while ((event = xcb_wait_for_event (connection))) {
        
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
                    std::cout << "XCB_KEY_PRESS" << std::endl;
                }
                break;
            case XCB_KEY_RELEASE:
                {
                    xcb_key_release_event_t *krelease = (xcb_key_release_event_t *) event;
                    std::cout << "XCB_KEY_RELEASE" << std::endl;
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
#endif