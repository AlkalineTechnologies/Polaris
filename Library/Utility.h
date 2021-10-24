//
// Created by Lysander Mealy on 10/24/21.
//

#ifndef POLARIS_UTILITY_H
#define POLARIS_UTILITY_H

namespace Polaris {
    namespace Utility {
        template<size_t size, typename T, typename ...TVariadic>
        T *variadicToArray(T arg0, TVariadic... args) {
            T toReturn[size] = {arg0, variadicToArray<size - 1>(args...)};
            return toReturn;
        }
    }
}


#endif //POLARIS_UTILITY_H
