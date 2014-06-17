#include <vector>
#include <cmath>
using namespace std;

double interest_rate_trees_gbm_spot_rate( const vector< vector<double> > & tree,  const double& q, const int & T){
    vector<double> Bnext(T+1,1.0);
    vector<double> B(T+1);
    for (int n=T;n>0;--n){
	for (int i=0;i<n;++i){
	    B[i]=exp(-tree[n-1][i])*(q*Bnext[i]+(1-q)*Bnext[i+1]);
	    Bnext[i]=B[i]; // now safe, not being used anymore
	};
    };
    double spotrate = -log(B[0])/double(T);
    return spotrate;
};
