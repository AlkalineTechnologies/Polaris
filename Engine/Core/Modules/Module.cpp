#include "Modules.hpp"
#include <algorithm>

namespace Polaris{
    namespace Modules{
        std::vector<Module*> Module::_ModuleInstances;
        
        Module::Module(){
            _ModuleInstances.push_back(this);
        }
        
        Module::~Module(){
            _ModuleInstances.erase(std::remove(_ModuleInstances.begin(), _ModuleInstances.end(), this), _ModuleInstances.end());
        }
        
        void Module::Initialize(){
            
        }
        
        void Module::Shutdown(){
            
        }
    }
}