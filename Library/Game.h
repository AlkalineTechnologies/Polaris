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

    private:
        Game();
        static Game *_instance;
        void *_native;
    };
}

#endif //POLARIS_GAME_H
