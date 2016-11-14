/****************************************************************/
/*               DO NOT MODIFY THIS HEADER                      */
/* MOOSE - Multiphysics Object Oriented Simulation Environment  */
/*                                                              */
/*           (c) 2010 Battelle Energy Alliance, LLC             */
/*                   ALL RIGHTS RESERVED                        */
/*                                                              */
/*          Prepared by Battelle Energy Alliance, LLC           */
/*            Under Contract No. DE-AC07-05ID14517              */
/*            With the U. S. Department of Energy               */
/*                                                              */
/*            See COPYRIGHT for full restrictions               */
/****************************************************************/

#include "MyPostProc.h"
#include "SubProblem.h"
#include <stdlib.h>

#include "libmesh/system.h"

template <>
InputParameters validParams<MyPostProc>()
{
  InputParameters params = validParams<GeneralPostprocessor>();
  MooseEnum out_enum("stateVal failProb", "failProb");
  params.addParam<MooseEnum>("outData", out_enum, "output options (outStateVal, failProb). Default == failProb");
  return params;
}

MyPostProc::MyPostProc(const InputParameters &parameters) : GeneralPostprocessor(parameters),
                                                            _outData(parameters.get<MooseEnum>("outData").getEnum<OutEnum>()),
                                                            _system_pointer(nullptr),
                                                            _es_pointer(nullptr),
                                                            _st1("st1", 0.0289),
                                                            _st2("st2", 0.0289),
                                                            _runOK(true)
//_missionTime(24);
//_failCnt(0),
//_totCnt(0)
{

  switch (_outData)
  {
  case stateVal:
    break;
  case failProb:
    break;
  default:
    mooseError("Unhandled enum");
  }
}

void MyPostProc::initialize()
{
  
  
  // double _missionTime = 24;
  // _totCnt++;
  // _runOK = true;
  // _st1.execute(missionTime);
  // if(_st1.getOK() == false)
  // {
  //   //return 0;
  //   _st2.execute(missionTime);
  //   if (_st2.getOK() == false)
  //   {
  //     _failCnt++;
  //     _runOK = false;
  //   }
  // }
}

void MyPostProc::initialSetup()
{
  srand(0);
  _st1.sample(_t_step);
}

void MyPostProc::execute()
{
  if(!_runOK)
    _fe_problem.terminateSolve();

  _runOK = true;
  if (_st1.getOK(_t_step) == false)
  {
    _st2.sample(_t_step);
    if (_st2.getOK(_t_step) == false)
    {
      _runOK = false;
    }
  }
}

Real MyPostProc::getValue()
{
  switch (_outData)
  {
  case stateVal:    
    return _runOK;
  case failProb:
    return _runOK;//(double)_failCnt / _totCnt;
  }

  //testInc = testInc +2;

  return 1;
}
