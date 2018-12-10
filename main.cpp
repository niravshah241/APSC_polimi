#include "newton.h"

class
problem1_cs : public cs_newton_solver
{
  double
  eval (const double x);

  std::complex<double>
  eval (const std::complex<double> x);
};


class
problem1_fd : public fd_newton_solver
{
  double
  eval (const double x);
};

// Define a template function to compute
// sin (cos (x))
// for either double or complex input


// Define the method "eval" for both
// classes problem1_cs and problem1_fd 


int
main ()
{

  problem1_cs cs;
  cs.solve (0.6);

  std::cout << "PROBLEM 1 COMPLEX STEP ALGORITHM:\n";
  std::cout << "solution after " << cs.get_iter ()
            << " iterations = " << cs.get_result ()
            << " residual = " << cs.get_residual ()
            << std::endl;

  // Expected output:
  // PROBLEM 1 COMPLEX STEP ALGORITHM:
  // solution after 7 iterations = 1.5708 residual = 6.12323e-17

  cs.solve (1.5);

  std::cout << "PROBLEM 2 COMPLEX STEP ALGORITHM:\n";
  std::cout << "solution after " << cs.get_iter ()
            << " iterations = " << cs.get_result ()
            << " residual = " << cs.get_residual ()
            << std::endl;

  // Expected output:
  // PROBLEM 2 COMPLEX STEP ALGORITHM:
  // solution after 3 iterations = 1.5708 residual = 6.12323e-17

  problem1_fd fd;
  fd.solve (0.6);

  std::cout << "PROBLEM 1 FINITE DIFFERENCES ALGORITHM:\n";
  std::cout << "solution after " << fd.get_iter ()
            << " iterations = " << fd.get_result ()
            << " residual = " << fd.get_residual ()
            << std::endl;

  // Expected output:
  // PROBLEM 1 FINITE DIFFERENCES ALGORITHM:
  // solution after 25 iterations = 14.1372 residual = 9.64744e-14

  fd.solve (1.5);

  std::cout << "PROBLEM 2 FINITE DIFFERENCES ALGORITHM:\n";
  std::cout << "solution after " << fd.get_iter ()
            << " iterations = " << fd.get_result ()
            << " residual = " << fd.get_residual ()
            << std::endl;

  // Expected output:
  // PROBLEM 2 FINITE DIFFERENCES ALGORITHM:
  // solution after 3 iterations = 1.5708 residual = 6.12323e-17

  return 0;
  
};
