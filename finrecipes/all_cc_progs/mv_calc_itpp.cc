#include <cmath>
using namespace std;

#include <itpp/itbase.h>
using namespace itpp;

double mv_calculate_mean(const vec& e, const vec& w){ 
    vec tmp = e.transpose()*w;
    return tmp(0); 
};

double mv_calculate_variance(const mat& V, const vec& w){ 
    mat tmp = w.transpose()*V*w;
    return tmp(0,0);
};

double mv_calculate_st_dev(const mat& V, const vec& w){ 
    double var = mv_calculate_variance(V,w);
    return sqrt(var);
};
