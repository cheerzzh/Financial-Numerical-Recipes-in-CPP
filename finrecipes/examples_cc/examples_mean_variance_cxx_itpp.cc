#include "fin_recipes.h"

#ifdef _HAVE_ITPP_

#include "fin_recipes_itpp.h"

void test_mean_variance_calculations_itpp(){
    cout << " testing basic mean variance calculations using IT++ " << endl;
    vec e = " 0.05 0.1 0.075";
    mat V = "0.9  -0.2 0.0; -0.2 1.0 -0.3; 0.0 -0.3 0.6";
    vec w = "0.3333 0.3333 0.333";
    cout << " mean "     << mv_calculate_mean(e,w)     << endl;
    cout << " variance " << mv_calculate_variance(V,w) << endl;
    cout << " stdev "    << mv_calculate_st_dev(V,w)   << endl;
};

void test_mean_variance_calculations_portfolio_itpp(){
    cout << " Example mean variance optimal portfolis using itpp " << endl;
    vec e = " 0.05 0.1 0.075";
    mat V = "0.9  -0.2 0.0; -0.2 1.0 -0.3; 0.0 -0.3 0.6";
    double r=0.075;
    mat w = mv_calculate_portfolio_given_mean_unconstrained(e,V,r);
    cout << " suggested portfolio " << endl;
    cout << w << endl;
};


#endif

void examples_mean_variance_itpp() {
    cout << "-------------------------------" << endl;
    cout << "Mean Variance Examples using itpp " << endl;
    cout << "-------------------------------" << endl;
#ifdef _HAVE_ITPP_
    test_mean_variance_calculations_itpp();
    test_mean_variance_calculations_portfolio_itpp();
#endif
};
