#include "disk.h"
#include "ram.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
void Save ()
{
    ofstream stream("numbers.bin", ios::binary);
    if (stream.is_open())
    {
        for (int i = 0; i < 8; i++)
        {
            int tmp = Read(i);
            stream.write((char*) &tmp, sizeof(tmp));
        }
        cout << "You write data to current folder in file numbers.bin!\n";
    } else 
    {
        cout << "An error saving to file!\n";
    }
    stream.close();
}
void Load ()
{
    ifstream stream("numbers.bin", ios::binary);
    if (stream.is_open())
    {
        for (int i = 0; i < 8; i++)
        {
            int tmp;
            stream.read((char*) &tmp, sizeof(tmp));
            Write(tmp,i);
        }
        cout << "You read data from file numbers.bin to ram!\n";
    } else 
    {
        cout << "Error reading file or file is absent\n";
    }
    stream.close();
    
}