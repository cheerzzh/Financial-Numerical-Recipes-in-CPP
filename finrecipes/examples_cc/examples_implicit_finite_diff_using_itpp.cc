void test_implicit_finite_differences_using_itpp(){
    double S = 50.0;
    double K = 50.0;
    double r = 0.1; 
    double sigma = 0.4;
    double time=0.5;
    int no_S_steps=200;
    int no_t_steps=200;
    cout << " black scholes put price = "  << option_price_put_black_scholes(S,K,r,sigma,time)<< endl;
    cout << " implicit American put price = ";
    cout << option_price_put_american_finite_diff_implicit_itpp(S,K,r,sigma,time,no_S_steps,no_t_steps) << endl;
};

void examples_finite_diffs_using_itpp(){
    cout << "----------------------------" << endl;
    cout << "Finite Differences examples using it++ " << endl;
    cout << "----------------------------" << endl;
    test_implicit_finite_differences_using_itpp();
};
