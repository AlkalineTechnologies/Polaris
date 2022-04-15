// polaris header

#ifndef __POLARIS_MODULES_HPP__
#define __POLARIS_MODULES_HPP__

#include <vector>

namespace Polaris {
    namespace Modules{
        
        class Module {
            protected:
                static std::vector<Module*> _ModuleInstances;
            public:
                Module();
                virtual ~Module();
                virtual void Initialize() = 0;
                virtual void Shutdown() = 0;

        };
    }
}
#endif