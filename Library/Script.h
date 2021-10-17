//
// Created by Lysander Mealy on 10/17/21.
//

#ifndef POLARIS_SCRIPT_H
#define POLARIS_SCRIPT_H

#include "Game.h"

namespace Polaris {
    class Script: public Component {
    private:
        void firstFrame() override { begin(); }
        void frame() override {
            deltaTime = Polaris::Game::getInstance()->getDeltaTime();
            update();
        }

    public:
        virtual void begin() {}
        virtual void update() {}

        double deltaTime;
    };
}

#endif //POLARIS_SCRIPT_H
