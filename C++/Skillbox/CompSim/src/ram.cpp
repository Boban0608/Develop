#include "ram.h"
int buffer[8];
void Write (int num, int i)
{
    buffer[i] = num;
}
int Read (int i)
{
    return buffer[i];
}