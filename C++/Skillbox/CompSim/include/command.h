#pragma once
#include <iostream>
enum Command
{
    SUM = 1,
    SAVE = 2,
    LOAD = 3,
    INPUT = 4,
    DISPLAY = 5,
    EXIT = 6,
    NOT_DEFINED = 99
};

Command GetCommand(std::string command);