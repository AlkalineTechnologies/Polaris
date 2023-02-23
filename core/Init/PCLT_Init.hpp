#ifndef __PCLT_INIT_HPP__
#define __PCLT_INIT_HPP__

#include <Libraries/argparse.hpp>
#include <string>

// future parameters: Project Name, Project Location, PCLT-version
void Init_Workspace(argparse::ArgumentParser& program, std::string Location ="");
#endif