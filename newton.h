
#ifndef HAVE_NEWTON_H
#define HAVE_NEWTON_H 1

#include <cmath>
#include <complex>
#include <functional>
#include <iostream>
#include <limits>


class
abstract_newton_solver
{
  
protected :  

  virtual
  double
  eval (const double x) = 0;

  virtual
  double
  prime (const double x) = 0;

private :
  int    maxit;
  double funtol;
  double xtol;
  double x;
  double dfdx;
  double dx;
  double r;
  int    iter;
  
 public:
  
  abstract_newton_solver (const int maxit_ = 100,
                          const double funtol_ = std::numeric_limits<double>::epsilon () * 1000.0,
                          const double xtol_ = std::numeric_limits<double>::epsilon () * 1000.0)
    : maxit (maxit_), funtol (funtol_), xtol (xtol_)
  { x = 0; dfdx = 0; r = 0; iter = 0; }
    

  void
  solve (const double x0);
  
  double
    get_result ()
  { return x; };
  
  double
    get_residual ()
  { return r; };
  
  int
    get_iter ()
  { return iter; };
  
};

class
fd_newton_solver
: public abstract_newton_solver
{
  
 private :
  
  double
    prime (const double x);
  
  const double delta;
  
 public :
  
  fd_newton_solver (const double delta_ = std::numeric_limits<double>::epsilon () * 10.0,
                    const int maxit_ = 100,
                    const double funtol_ = std::numeric_limits<double>::epsilon () * 1000.0,
                    const double xtol_ = std::numeric_limits<double>::epsilon () * 1000.0)
    : delta(delta_), abstract_newton_solver(maxit_, funtol_, xtol_) {};
  
};


class
cs_newton_solver
: public abstract_newton_solver
{
  
 protected :
  
  virtual
    std::complex<double>
    eval (const std::complex<double> x) = 0;
  
 private :
  
  double
    prime (const double x);
  
  const double delta;
  
 public :
  
  cs_newton_solver (const double delta_ = 1.0e-100,
                    const int maxit_ = 100,
                    const double funtol_ = std::numeric_limits<double>::epsilon () * 1000.0,
                    const double xtol_ = std::numeric_limits<double>::epsilon () * 1000.0)
    : delta(delta_), abstract_newton_solver(maxit_, funtol_, xtol_) {};
  
};

#endif

