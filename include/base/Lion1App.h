#ifndef LION1APP_H
#define LION1APP_H

#include "MooseApp.h"

class Lion1App;

template<>
InputParameters validParams<Lion1App>();

class Lion1App : public MooseApp
{
public:
  Lion1App(InputParameters parameters);
  virtual ~Lion1App();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* LION1APP_H */
