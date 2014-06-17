#include <iostream>
using namespace std;
#include "fin_recipes.h"

void test_merton_jump_diff_call(){
    double S=100; double K=100; double r=0.05;
    double sigma=0.3; 
    double time_to_maturity=1;
    double lambda=0.5;
    double kappa=0.5;
    double delta=0.5;
    cout << " Merton Jump diffusion call = " 
	 << option_price_call_merton_jump_diffusion(S,K,r,sigma,time_to_maturity,lambda,kappa,delta)
	 << endl;
};

void test_heston(){
#ifdef _HAVE_GSL_
    double S=100;
    double K=100;
    double r=0.01;
    double v=0.01;
    double tau=0.5;
    double rho=0;
    double kappa=2;
    double lambda=0.0;
    double theta=0.01;
    double sigma=0.01;
    cout << "heston call price " << heston_call_option_price( S, K, r, v, tau, rho, kappa, lambda, theta, sigma) << endl;
#endif
};

void alternative_formulas_examples(){
    cout << "-----------------------------" << endl;
    cout << "Alternative formulas " << endl;
    cout << "-----------------------------" << endl;
    test_merton_jump_diff_call();
    test_heston();
};

