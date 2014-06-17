#include <vector>
#include <cmath>
using namespace std;

vector< vector<double> > 
build_interest_rate_tree_rendleman_bartter(const double& r0,
					   const double& u,
					   const double& d,
					   const int& n){
    vector< vector<double> > tree;
    for (int i=1;i<=n;++i){
	vector<double> r(i);
	for (int j=0;j<i;++j){
	    r[j] = r0*pow(u,j)*pow(d,i-j-1);
	};
	tree.push_back(r);
    };
    return tree;
};
