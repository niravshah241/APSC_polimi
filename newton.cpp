#include "newton.h"

void
abstract_newton_solver::solve (const double x0)
{
  x = x0;
  for (iter = 0; iter < maxit; ++iter)
    {
      r    = eval (x);
      if (std::abs (r) < funtol) break;
      dfdx = prime (x);
      dx   = - r / dfdx;
      if (std::abs (dx) < xtol) break;
      x += dx;
    }
  
}

// Implement the method "fd_newton_solver::prime" using centered finite
// differences with a step "delta"
// double
// fd_newton_solver::prime (const double x)
// { ... }


// Implement the method "cs_newton_solver::prime" using the
// complex step method differences with a step "delta"
// double
// cs_newton_solver::prime (const double x)
// { ... }

