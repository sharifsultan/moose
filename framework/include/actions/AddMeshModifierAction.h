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

#ifndef ADDMESHMODIFIERACTION_H
#define ADDMESHMODIFIERACTION_H

#include "MooseObjectAction.h"

//Forward Declaration
class AddMeshModifierAction;

template<>
InputParameters validParams<AddMeshModifierAction>();


class AddMeshModifierAction : public MooseObjectAction
{
public:
  AddMeshModifierAction(InputParameters params);

  virtual void act();
};

#endif // ADDMESHMODIFIERACTION_H
