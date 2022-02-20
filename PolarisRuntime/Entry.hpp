#ifndef __ENTRY_HPP__
#define __ENTRY_HPP__
#include <iostream>
#include <vector>


namespace Polaris{
    class App{
        protected:
            static std::vector<App*> Instances;  // List of all the apps
        public:
            App(); // add the pointer to the current instance of the class to the list of apps
            ~App(); 
            int Exit(); // remove the pointer to the current instance of the class to the list of apps
    };
};


#endif