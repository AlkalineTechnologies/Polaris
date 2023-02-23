#ifndef __ARG_HPP__
#define __ARG_HPP__

#include "Init/PCLT_Init.hpp"
#include "Init/Module_Init.hpp"
#include <Libraries/argparse.hpp>

void Args_To_Act(argparse::ArgumentParser& program){
    if (program.is_used("-i")){
        Init_Workspace(program, program.get<std::string>("-i"));
    }
    else if (program.is_used("-n")){
    
    }
    else if (program.is_used("-b")){
    
    }
}

#endif