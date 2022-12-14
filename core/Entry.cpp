#include "argparse.hpp"
#include <string>
#include <map>

#include "Args.hpp"


int main(int argc, char** argv){
    argparse::ArgumentParser program("PCLT");

    // add arguments

    program.add_argument("-n","--new")
        .nargs(3) //* Project Name, Project Type, Project Location
        .help("Initialize a new Polaris Project");
        
    program.add_argument("-i","--init")
        .nargs(1) //* Where to init the Workspace
        .help("Initialize a new Polaris Module");

    program.add_argument("-b","--build")
        .nargs(0)
        .help("Build a Polaris Project");

    try {
        program.parse_args(argc, argv);
    }
    catch (const std::runtime_error& err) {
        std::cout << err.what() << std::endl;
        std::cout << program;
        return 0;
    }

    Args_To_Act(program);
}