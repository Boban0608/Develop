#include "gpu.h"
#include "ram.h"
#include <iostream>

void Display() 
{
    for (int i = 0; i < 8; i++ )
    {
       int tmp = Read(i);
       std::cout << tmp << " ";
    }
    std::cout << std::endl;
}