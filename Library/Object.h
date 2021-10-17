//
// Created by Lysander Mealy on 10/17/21.
//

#ifndef POLARIS_OBJECT_H
#define POLARIS_OBJECT_H

#include <vector>
#include "Component.h"

namespace Polaris {
    class Object {
    public:
        void addComponent(Component *component) {
            components.push_back(component)
        }
        Component *getComponent()

    private:
        std::vector<Component *> components;
    };
}

#endif //POLARIS_OBJECT_H
