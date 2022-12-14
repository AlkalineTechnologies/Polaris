#ifndef __ARG_HPP__
#define __ARG_HPP__

#include "argparse.hpp"
#include "Init/PCLT_Init.hpp"
#include "Init/Module_Init.hpp"

void Args_To_Act(argparse::ArgumentParser& program){
    if (program.is_used("-i")){
        Init_Workspace(program);
    }
    else if (program.is_used("-n")){
        // program["-n"] == "project" ? InitProject(program) : Init_Module(program) ;
    }
    else if (program.is_used("-b")){
    
    }
}

#endif