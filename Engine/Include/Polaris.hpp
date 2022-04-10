#ifndef __POLARIS_INCLUDE_HPP__
#define __POLARIS_INCLUDE_HPP__

#include <Core/Include/Entry.hpp>

namespace Polaris{
    extern Core::Instance Entry();


    namespace Application{
        extern void Initialize();
        extern void Terminate();
    }
    // exit will call the main entry function of the engine by using the function pointer
    void Exit(int _status);
}

#endif

//TODO: Add module support