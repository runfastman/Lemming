#include "State.h"
#include <stdlib.h>
#include <string>
#include <cmath>

using namespace std;

State::State(string name, double failProb) : _name(name),
                                             _ok(true),
                                             _failProb(failProb),
                                             _timeRate(1),
                                             _sampled(false)
{
}

bool State::getOK(double time)
{
    if (_sampled)
        return _failTime > time;
    else
        return true;
}

// void State :: execute(double timeHours)
// {
//     int max = RAND_MAX;
//     int r = rand();
//     double randNum = (double)r / max;

//     double tempD = std::log(1-randNum) * -1;
//     double timeToFail = (tempD / _failProb) * _timeRate;
//     if(timeToFail < timeHours)
//     //if(randNum > 0.5)
//     {
//         _ok = false;
//     }
//     else
//     {
//         _ok = true;
//     }
// }

void State::sample(double startTime)
{
    if (! _sampled)
    {
        int max = RAND_MAX;
        int r = rand();
        double randNum = (double)r / max;

        double tempD = std::log(1 - randNum) * -1;
        double timeToFail = (tempD / _failProb) * _timeRate;
        _failTime = timeToFail + startTime;
        _sampled = true;
    }
}

double State::failTime() 
{
    return _failTime;
}
