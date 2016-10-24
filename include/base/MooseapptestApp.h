#ifndef MOOSEAPPTESTAPP_H
#define MOOSEAPPTESTAPP_H

#include "MooseApp.h"

class MooseapptestApp;

template<>
InputParameters validParams<MooseapptestApp>();

class MooseapptestApp : public MooseApp
{
public:
  MooseapptestApp(InputParameters parameters);
  virtual ~MooseapptestApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* MOOSEAPPTESTAPP_H */
