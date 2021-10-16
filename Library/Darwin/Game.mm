//
// Created by Lysander Mealy on 10/16/21.
//

#ifdef __APPLE__

#include <Game.h>

#include <Cocoa/Cocoa.h>

#include <thread>

namespace Polaris {
    id app;

    Game::~Game() = default;

    Game::Game() {
        delete _instance;

        [NSAutoreleasePool new];
        _native = [NSApplication sharedApplication];
        [(id)_native setActivationPolicy:NSApplicationActivationPolicyRegular];

        [(id)_native activateIgnoringOtherApps:YES];

        app = (id)_native;

        _instance = this;
    }

    Game *Game::AllocateNew() {
        return new Game();
    }

    void Game::run() {
        [app run];
    }

    Game *Game::getInstance() {
        return _instance;
    }

    void *Game::getNative() {
        return _native;
    }

    Game *Game::_instance = nullptr;
}

#endif