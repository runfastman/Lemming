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

#ifndef MyPostProc_H
#define MyPostProc_H

#include "GeneralPostprocessor.h"
#include "State.h"
#include <string>

//Forward Declarations
class MyPostProc;

// libMesh forward declarations
namespace libMesh
{
class System;
class EquationSystems;
}

template<>
InputParameters validParams<MyPostProc>();

class MyPostProc : public GeneralPostprocessor
{
public:
  MyPostProc(const InputParameters & parameters);

  virtual void initialize() override;
  virtual void execute() override;
  virtual Real getValue() override;
  virtual void initialSetup() override;

protected:
  enum OutEnum
  {
    stateVal,
    failProb
  };
  
  const OutEnum _outData;
  const System * _system_pointer;
  const EquationSystems * _es_pointer;

  State _st1;//(name, 0.00087);
  State _st2;//("st1", 0.00087);
  
  bool _runOK; 
  //double _missionTime;
  //int _failCnt; 
  //int _totCnt;
};

#endif //MyPostProc_H
