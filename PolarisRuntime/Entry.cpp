#include <Entry.hpp>
#include <vector>

std::vector<Polaris::App *> Polaris::App::Instances ;

namespace Polaris {
    Polaris::App::App(){
        // Add the pointer to the current instance of the class to the list of apps
        Instances.push_back(this);
    }
};
