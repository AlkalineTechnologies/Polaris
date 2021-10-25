//
// Created by Lysander Mealy on 10/16/21.
//

#ifndef POLARIS_WINDOW_H
#define POLARIS_WINDOW_H

#include "string"

namespace Polaris {
    class Window {
    public:
        explicit Window(std::string title, int width = 800, int height = 600, bool fullscreen = true,
                        bool show = false);

        void setTitle(std::string title);

        void Fullscreen();

        void show();

        void hide();

    private:
        std::string _title;
        int _width, _height;

        void *_window;
    };
}

#endif //POLARIS_WINDOW_H