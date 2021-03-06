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

#include "DebugResidualAux.h"
#include "NonlinearSystem.h"

template<>
InputParameters validParams<DebugResidualAux>()
{
  InputParameters params = validParams<AuxKernel>();
  params.addRequiredParam<NonlinearVariableName>("debug_variable", "The variable that is being debugged.");
  return params;
}

DebugResidualAux::DebugResidualAux(const InputParameters & parameters) :
    AuxKernel(parameters),
    _debug_var(_nl_sys.getVariable(_tid, getParam<NonlinearVariableName>("debug_variable"))),
    _residual_copy(_nl_sys.residualGhosted())
{
  if (!_nodal)
    mooseError("Cannot use DebugResidualAux on elemental variables");
}

DebugResidualAux::~DebugResidualAux()
{
}

Real
DebugResidualAux::computeValue()
{
  dof_id_type dof = _current_node->dof_number(_nl_sys.number(), _debug_var.number(), 0);
  return _residual_copy(dof);
}
