#include <Include/Polaris.hpp>

void Polaris::Exit(int _status){
    // call destructor of the main entry function
    
    Polaris::Entry().~Instance();
}