#ifdef __WIN32

#include "../Game.h"

#include <Windows.h>

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
        MSG msg = { };
        while (GetMessage(&msg, NULL, 0, 0) > 0) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);

        }
    }

    Game *Game::getInstance() {
        return _instance;
    }

    void *Game::getNative() {
        return _native;
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