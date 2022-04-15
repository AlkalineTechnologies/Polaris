#include <Core/Include/Entry.hpp>
#include <Include/Polaris.hpp>

#include <future>
#include <iostream>

// BOOTUP
Polaris::Core::Instance::Instance(){
    // SETUP EVENT MANAGER
    // SETUP LOGGER
    // SETUP CRASH HANDLER
    // SETUP APP INFO
    // SETUP MODULES
    // SEND POLARIS "READY"
}

// SHUTDOWN
Polaris::Core:: Instance::~Instance(){

    // SEND POLARIS "SHUTDOWN"
    // SHUTDOWN MODULES
    // SHUTDOWN CRASH HANDLER
    // SHUTDOWN EVENT MANAGER
    // SHUTDOWN LOGGER
}

int main(int argc, char** argv){
    
    std::future<Polaris::Core::Instance> _ENTRY_THREAD = std::async(std::launch::async, Polaris::Entry);
    std::cout << "Polaris Engine is starting up...\n" << std::endl;
    return 0;
}

// should have written this in rust... probably...

// reminder: Polaris' components and modules are different.
// components are a part of the engine, and are used to build the engine.  [e.g Entry, Logger, CrashHandler, AppInfo, Modules]cd 
// modules are "add-ons" to the engine, and are used to extend the engine. [e.g. graphics, audio, etc.]