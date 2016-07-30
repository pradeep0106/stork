#ifndef SWAMIJIAPP_H
#define SWAMIJIAPP_H

#include "MooseApp.h"

class SwamijiApp;

template<>
InputParameters validParams<SwamijiApp>();

class SwamijiApp : public MooseApp
{
public:
  SwamijiApp(InputParameters parameters);
  virtual ~SwamijiApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* SWAMIJIAPP_H */
