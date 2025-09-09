#include <iostream>
#include <armadillo>

int main()
{
  arma::mat A = arma::randu<arma::mat>(3,3);
  arma::vec b = arma::randu<arma::vec>(3);
  
  arma::vec x = solve(A,b);

  std::cout << "A = \n" << A << "\n";
  std::cout << "b = \n" << b << "\n";
  std::cout << "x = \n" << x << "\n";

  return 0;
}
