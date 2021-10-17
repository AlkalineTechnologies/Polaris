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
        static Game *AllocateNew();

        void run();
        Game *getInstance();
        void *getNative();

        int frameCap = 0;

    private:
        Game();
        void _gameLoop();

        static Game *_instance;

        void *_native;
        std::thread *gameLoopThread;

        bool _terminate = false;
        long _deltaTimeReal = 0;
        long _deltaTimeUncapped = 0;
    };
}

#endif //POLARIS_GAME_H
