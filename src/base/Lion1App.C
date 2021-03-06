#include "Lion1App.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template<>
InputParameters validParams<Lion1App>()
{
  InputParameters params = validParams<MooseApp>();

  params.set<bool>("use_legacy_uo_initialization") = false;
  params.set<bool>("use_legacy_uo_aux_computation") = false;
  params.set<bool>("use_legacy_output_syntax") = false;

  return params;
}

Lion1App::Lion1App(InputParameters parameters) :
    MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  Lion1App::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  Lion1App::associateSyntax(_syntax, _action_factory);
}

Lion1App::~Lion1App()
{
}

// External entry point for dynamic application loading
extern "C" void Lion1App__registerApps() { Lion1App::registerApps(); }
void
Lion1App::registerApps()
{
  registerApp(Lion1App);
}

// External entry point for dynamic object registration
extern "C" void Lion1App__registerObjects(Factory & factory) { Lion1App::registerObjects(factory); }
void
Lion1App::registerObjects(Factory & factory)
{
}

// External entry point for dynamic syntax association
extern "C" void Lion1App__associateSyntax(Syntax & syntax, ActionFactory & action_factory) { Lion1App::associateSyntax(syntax, action_factory); }
void
Lion1App::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}
