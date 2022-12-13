#ifndef __ARG_ACTIONS_HPP__
#define __ARG_ACTIONS_HPP__

#include "argparse.hpp"



void arg_New_Project(argparse::ArgumentParser& program){
    
}

void arg_New_Module(argparse::ArgumentParser& program){
    
}

void arg_Init_Dir(argparse::ArgumentParser& program){
    
}

void arg_Build(argparse::ArgumentParser& program){
    
}


void Args_To_Act(argparse::ArgumentParser& program){
    if (program["-n"] == "project"){
        arg_New_Project(program);
    }
    else if (program["-n"] == "module"){
        arg_New_Module(program);
    }
}

#endif