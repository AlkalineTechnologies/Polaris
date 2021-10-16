//
// Created by Lysander Mealy on 10/16/21.
//

#ifdef __APPLE__

#include <App.h>

#include <Cocoa/Cocoa.h>

#include <thread>

namespace Polaris {
    id app;

    App::~App() = default;

    App::App() {
        delete _instance;

        [NSAutoreleasePool new];
        _native = [NSApplication sharedApplication];
        [(id)_native setActivationPolicy:NSApplicationActivationPolicyRegular];

        [(id)_native activateIgnoringOtherApps:YES];

        app = (id)_native;

        _instance = this;
    }

    App *App::AllocateNew() {
        return new App();
    }

    void App::run() {
        [app run];
    }

    App *App::getInstance() {
        return _instance;
    }

    void *App::getNative() {
        return _native;
    }

    App *App::_instance = nullptr;
}

#endif