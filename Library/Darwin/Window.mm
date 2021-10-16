//
// Created by Lysander Mealy on 10/16/21.
//

#ifdef __APPLE__

#include <Window.h>

#include <Cocoa/Cocoa.h>

#define toNSString(str) [NSString stringWithCString:str.c_str() encoding:NSUTF8StringEncoding]
#define toNSStringWithEncoding(str, _encoding) [NSString stringWithCString:str.c_str() encoding:_encoding]

namespace Polaris {
    Window::Window(std::string title, int width, int height, bool fullscreen, bool show) {
        _title = title;
        _width = width;
        _height = height;

        if (fullscreen) {
            NSRect frame = [[NSScreen mainScreen] frame];

            _window = [[[NSWindow alloc] initWithContentRect:frame
                                                   styleMask:NSWindowStyleMaskBorderless
                                                     backing:NSBackingStoreBuffered
                                                       defer:NO] autorelease];
            [(NSWindow *) _window setTitle:[NSString stringWithCString:title.c_str() encoding:NSUTF8StringEncoding]];
            [(NSWindow *) _window setLevel:kCGPopUpMenuWindowLevel];
        } else {
            NSRect frame = NSMakeRect(0, 0, width, height);

            _window = [[[NSWindow alloc] initWithContentRect:frame
                                                   styleMask:NSWindowStyleMaskTitled | NSWindowStyleMaskClosable |
                                                             NSWindowStyleMaskResizable |
                                                             NSWindowStyleMaskMiniaturizable
                                                     backing:NSBackingStoreBuffered
                                                       defer:NO] autorelease];
            [(NSWindow *) _window setTitle:toNSString(title)];
        }

        if (show) {
            [(NSWindow *) _window makeKeyAndOrderFront:nil];
        }
    }

    void Window::setTitle(std::string title) {
        _title = title;
        [(NSWindow *) _window setTitle:toNSString(title)];
    }

    void Window::show() {
        [(NSWindow *) _window makeKeyAndOrderFront:nil];
    }

    void Window::hide() {
        [(NSWindow *) _window orderOut:nil];
    }
}

#endif