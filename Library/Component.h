//
// Created by Lysander Mealy on 10/17/21.
//

#ifndef POLARIS_COMPONENT_H
#define POLARIS_COMPONENT_H

namespace Polaris {
    class Component {
    protected:
        virtual void firstFrame() {}

        virtual void frame() {}
    };
}

#endif //POLARIS_COMPONENT_H
