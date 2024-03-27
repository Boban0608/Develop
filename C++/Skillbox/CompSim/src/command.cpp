#include "command.h"
#include <iostream>
#include <string>


Command GetCommand (std::string command)
{
    Command cmd = NOT_DEFINED;
    try
    {
        cmd = (Command)stoi (command);
    }
    catch (std::invalid_argument& e)
    {
        std::cerr << "Can't understand your input." << "\n";
    }
    return cmd; 
}