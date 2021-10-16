//
// Created by Lysander Mealy on 10/16/21.
//

#ifndef POLARIS_APP_H
#define POLARIS_APP_H

#include <thread>

namespace Polaris {
    class App {
    public:
        ~App();
        static App *AllocateNew();

        void run();
        App *getInstance();
        void *getNative();

    private:
        App();
        static App *_instance;
        void *_native;
    };
}

#endif //POLARIS_APP_H
