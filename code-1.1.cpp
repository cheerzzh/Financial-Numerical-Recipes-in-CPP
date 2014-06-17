#include <iostream>
#include <cmath>
using namespace std;

double power(double x, double n){
	//define a simple power function
	double p = exp(n*log(x));
	return p;
};

int main(){
	for ( int n =1;n<6;n++){
		cout << "2^" <<n<<"="<<power(2,n)<<endl;
	};
};