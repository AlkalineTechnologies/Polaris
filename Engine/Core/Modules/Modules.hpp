// polaris header

#ifndef __POLARIS_MODULES_HPP__
#define __POLARIS_MODULES_HPP__

#include <vector>
#include <string>

namespace Polaris {
    namespace Modules{
        
        class Module {
            protected:
                int _id;
                static std::vector<Module*> _ModuleInstances;
            public:
                Module(std::string _name, int _id);
                ~Module();
                void Initialize();
                void Shutdown();
                
                // Module Profile
                std::string _name, _author, _version, _description;

        };
    }
}
#endif