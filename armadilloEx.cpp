#include <armadillo>
#include <iostream>

int main() {
    arma::mat A = {{1,2},{3,4}};
    arma::mat B = {{5,6},{7,8}};
    arma::mat C = A * B;
    
    C.print("Resultado:");
    return 0;
}