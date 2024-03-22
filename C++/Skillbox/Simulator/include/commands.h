#pragma once
#include <iostream>
#include <string>
#include "struct.h"
using namespace std;

incision Scalpel()
{
    incision incision;
    cout << "Input 2 coordinate to make incision.\n";
    cout << "Input 1-st in format [x y]: ";
    cin >> incision.x0 >> incision.y0;
    cout << "Input 2-nd in format [x y]: ";
    cin >> incision.x1 >> incision.y1;
    cout << endl << endl;
    cout << "You make incision between coordinate [" << incision.x0 << "," 
         << incision.y0 << "] and [" << incision.x1 << "," << incision.y1 
         << "]" << endl << endl;
    return incision;
}
void Hemostat()
{
    suturestr hemo;
    cout << endl << "You take hemostat.\n";
    cout << "Input coordinates to make clamp in format [x y]: ";
    cin >> hemo.x >> hemo.y;
    cout << endl << "--== You make clamp by coordinate [" << hemo.x << ","
         << hemo.y << "] ==--" << endl << endl;
}
void Tweezers()
{
    suturestr tweez;
    cout << endl << "You take tweezers.\n";
    cout << "Input coordinates to use tweezers in format [x y]: ";
    cin >> tweez.x >> tweez.y;
    cout << endl << "--== You use tweezers by coordinate [" << tweez.x << ","
         << tweez.y << "] ==--" << endl << endl;
}
suturestr Suture()
{
    suturestr suturestr;
    cout << endl << "You take suture.\n";
    cout << "Input coordinates to make stitch in format [x y]: ";
    cin >> suturestr.x >> suturestr.y;
    cout << endl << "--== You make stitch by coordinate [" << suturestr.x << ","
         << suturestr.y << "] ==--" << endl << endl;
    return suturestr;
}
command GetCommand(string input)
{
    command cmd = NotDefined;
    try 
    {
        cmd = (command) stoi(input);
    }
    catch (std::invalid_argument& e)
    {
        std::cerr << "Can't understand your input." << "\n";
    }
    return cmd;
}
void SimEnd()
{
    cout << endl << "--== You finish your surgery! ==--" << endl;
    cout << "--== Congratulation!!!! ==--" << endl;
}