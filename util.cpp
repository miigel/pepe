#include "util.h"

std::string inttostr(int i)
{
    std::stringstream ss;
    ss << i;
    return ss.str();
}

std::string doubletostr(double d)
{
    std::stringstream ss;
    ss << d;
    return ss.str();
}

int random(int min, int max)
{
    double gap = max - min;
    return (int)((rand()*(gap/RAND_MAX*1.0))+0.5) + min;
}
