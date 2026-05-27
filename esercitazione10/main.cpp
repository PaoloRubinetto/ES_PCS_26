#include <iostream>
#include <Eigen/Dense>
#include "conjugate_gradient.hpp"



int main() 
{
    std::cout << "--- Esercitazione 10: Gradiente Coniugato ---\n\n";

    double user_tol;
    std::cout << "Inserisci la tolleranza desiderata (es. 1e-8, 1e-12): ";
    std::cin >> user_tol;

    int user_max_it;
    std::cout << "Inserisci il numero massimo di iterazioni consentite: ";
    std::cin >> user_max_it;

    const unsigned int n = 100;
    std::cout << "\nGenerazione matrice " << n << "x" << n << " simmetrica definita positiva...\n";
    
    Eigen::MatrixXd B = Eigen::MatrixXd::Random(n, n);
    Eigen::MatrixXd A = B.transpose() * B;
    A += n * Eigen::MatrixXd::Identity(n, n);

    Eigen::VectorXd x_ex = Eigen::VectorXd::Ones(n); 
    Eigen::VectorXd b = A * x_ex;
    Eigen::VectorXd x0 = Eigen::VectorXd::Zero(n);

    std::cout << "Risoluzione del sistema in corso...\n";
    auto result = conjugate_gradient(A, b, x0, user_tol, user_max_it);
    
    Eigen::VectorXd x_sol = result.first;
    int iter = result.second;

    Eigen::VectorXd final_res = b - A * x_sol;
    double res_norm = final_res.norm();
    double err_rel = (x_sol - x_ex).norm() / x_ex.norm();

    std::cout << "\n--- Report di Convergenza ---\n";
    std::cout.precision(4);
    std::cout << std::scientific;
    std::cout << "Iterazioni eseguite: " << iter << " / " << user_max_it << "\n";
    std::cout << "Norma del residuo:   " << res_norm << "\n";
    std::cout << "Errore relativo:     " << err_rel << "\n";

    double initial_res_norm = (b - A * x0).norm();
    if (res_norm <= user_tol * initial_res_norm) {
        std::cout << "\n[SUCCESSO] Il metodo ha raggiunto la tolleranza richiesta.\n";
    } else {
        std::cout << "\n[ATTENZIONE] Tolleranza non raggiunta. Fermato per limite iterazioni.\n";
    }

    return 0;
}