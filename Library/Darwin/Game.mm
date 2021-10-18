//
// Created by Lysander Mealy on 10/16/21.
//

#ifdef __APPLE__

#include "../Game.h"

#include <Cocoa/Cocoa.h>

#include <iostream>

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
        gameLoopThread = new std::thread([&]() { _gameLoop(); });
        [app run];
    }

    void Game::_gameLoop() {
        while (!_terminate) {
            auto startTime = std::chrono::high_resolution_clock::now();

            std::cout << 1000000000 / _deltaTimeReal << std::endl;

            auto endTime = std::chrono::high_resolution_clock::now();
            std::chrono::duration<long, std::nano> timeElapsed = endTime - startTime;
            if (frameCap == 0) {
                _deltaTimeReal = timeElapsed.count();
                _deltaTimeUncapped = _deltaTimeReal;
            } else {
                _deltaTimeUncapped = timeElapsed.count();

                long targetNS = 1000000000 / frameCap - 10000;

                while (true) {
                    endTime = std::chrono::high_resolution_clock::now();
                    timeElapsed = endTime - startTime;
                    if (timeElapsed.count() >= targetNS) break;

                    timeval tv{ 0, 1 };
                    select(0, nullptr, nullptr, nullptr, &tv);
                }

                _deltaTimeReal = timeElapsed.count();
            }
        }
    }

    Game *Game::_instance = nullptr;
}

#endif