#ifndef STATE_H
#define STATE_H

#include <string>

using namespace std;

class State
{
  private:
    std::string _name;
    bool _ok;
    double _failProb;
    double _timeRate; // = 365.3*24;
    double _failTime;
    bool _sampled;

  public:
    //with default value
    State(std::string name, double failProb);
    //	setter function
    bool getOK(double time);
    //void execute(double timeHours);
    void sample(double startTime);
    double failTime();
};

#endif