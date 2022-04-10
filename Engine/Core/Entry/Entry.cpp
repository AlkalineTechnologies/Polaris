#include "Entry.hpp"
#include "Polaris.hpp"

#include <future>

// BOOTUP
Polaris::Core::Instance::Instance(){

}

// SHUTDOWN
Polaris::Core:: Instance::~Instance(){

}

int main(int argc, char** argv){
    
    std::future<Polaris::Core::Instance> _ENTRY_THREAD = std::async(std::launch::async, Polaris::Entry);

    return 0;
}
