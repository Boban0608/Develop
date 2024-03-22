#pragma once
enum command
{
    scalpel = 1,
    hemostat = 2,
    tweezers = 3,
    suture = 4,
    quit = 5,
    NotDefined = 55
};
struct incision
{
    double x0;
    double y0;
    double x1;
    double y1;
};
struct suturestr
{
    double x;
    double y;
};