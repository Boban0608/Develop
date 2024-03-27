#include "kbd.h"
#include "ram.h"
#include <iostream>
using namespace std;

void Input()
{
    cout << "Input 8 numbers:\n";
    for (int i = 0; i < 8; i++)
    {
        int tmp;
        cout << "Input " << i+1 << " number: ";
        cin >> tmp;
        Write(tmp, i);
    }
}