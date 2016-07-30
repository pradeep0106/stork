#include "SwamijiApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template<>
InputParameters validParams<SwamijiApp>()
{
  InputParameters params = validParams<MooseApp>();

  params.set<bool>("use_legacy_uo_initialization") = false;
  params.set<bool>("use_legacy_uo_aux_computation") = false;
  params.set<bool>("use_legacy_output_syntax") = false;

  return params;
}

SwamijiApp::SwamijiApp(InputParameters parameters) :
    MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  SwamijiApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  SwamijiApp::associateSyntax(_syntax, _action_factory);
}

SwamijiApp::~SwamijiApp()
{
}

// External entry point for dynamic application loading
extern "C" void SwamijiApp__registerApps() { SwamijiApp::registerApps(); }
void
SwamijiApp::registerApps()
{
  registerApp(SwamijiApp);
}

// External entry point for dynamic object registration
extern "C" void SwamijiApp__registerObjects(Factory & factory) { SwamijiApp::registerObjects(factory); }
void
SwamijiApp::registerObjects(Factory & factory)
{
}

// External entry point for dynamic syntax association
extern "C" void SwamijiApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory) { SwamijiApp::associateSyntax(syntax, action_factory); }
void
SwamijiApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}
