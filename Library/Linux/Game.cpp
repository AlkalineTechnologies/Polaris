//
// Created by Lysander Mealy on 10/16/21.
//

#ifdef __linux__

#include "../Game.h"

#include <xcb/xcb.h>
#include <Linux/xcb_Winevents.hpp>
#include <unistd.h>

#include <iostream>

namespace Polaris {
    
    Game::~Game() = default;

    Game::Game() {
        delete _instance;
        _instance = this;
    }

    Game *Game::CreateNew() {
        return new Game();
    }

    void Game::run() {
        gameLoopThread = new std::thread([&]() { _gameLoop(); });

        Window_Loop();
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

                    timeval tv {0, 1};
                    select(0, nullptr, nullptr, nullptr, &tv);
                }
                _deltaTimeReal = timeElapsed.count();
            }
        }
    }

    Game *Game::_instance = nullptr;
}

#endif