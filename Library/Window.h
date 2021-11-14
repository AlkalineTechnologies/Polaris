//
// Created by Lysander Mealy on 10/16/21.
//

#ifndef POLARIS_WINDOW_H
#define POLARIS_WINDOW_H
// Polaris Library
#include <Inputs.h>
// c++ Standard Library
#include "string"

#ifdef __linux__
    #include <xcb/xcb.h>
    #include <X11/Xlib.h>
    #include <X11/Xlib-xcb.h>
#endif /* __linux__ */

namespace Polaris {
    class Window {
    public:
        explicit Window(std::string title, int width = 800, int height = 600, bool fullscreen = true,
                        bool show = false);

        void setTitle(std::string title);
        
        void Fullscreen(bool state);

        void show();

        void hide();
        
        //close() implies TERMINATING THE WINDOW, NOT HIDING IT.
        void close();
        
        Polaris::InputStream getInputStream();
    
        #ifdef __linux__
            Display             *Xdisplay               = XOpenDisplay(NULL);
            xcb_connection_t    *connection = XGetXCBConnection(Xdisplay);;
            xcb_screen_t *screen = xcb_setup_roots_iterator(xcb_get_setup(connection)).data;
            xcb_window_t         window = xcb_generate_id(connection);
            xcb_generic_event_t *event; 
            void EventLoop();
        #endif // __linux__

    private:
        std::string _title;
        int _width, _height;
        static Polaris::InputStream *_inputStream;
        void *_window;
    };
}

#endif //POLARIS_WINDOW_H