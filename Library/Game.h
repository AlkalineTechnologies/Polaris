//
// Created by Lysander Mealy on 10/16/21.
//

#ifndef POLARIS_GAME_H
#define POLARIS_GAME_H

#include <thread>

namespace Polaris {
    class Game {
    public:
        ~Game();
        static Game *CreateNew();

        void run();

        [[nodiscard]] static Game *getInstance() {
            return _instance;
        }
        [[nodiscard]] void *getNative() const {
            return _native;
        }
        [[nodiscard]] double getDeltaTime() const {
            return (double)_deltaTimeReal / 1000000000.0;
        }

        int frameCap = 0;

    private:
        Game();
        void _gameLoop();

        static Game *_instance;

        void *_native;
        std::thread *gameLoopThread;

        bool _terminate = false;
        long _deltaTimeReal = 1;
        long _deltaTimeUncapped = 0;
    };
}

#endif //POLARIS_GAME_H
