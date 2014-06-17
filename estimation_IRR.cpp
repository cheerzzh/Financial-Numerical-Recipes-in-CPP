#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>

//using namespace std;
const double ERROR = -1e30;

double cash_flow_pv_discrete(const std::vector<double>& cflow_times, const std::vector<double>& cflow_amounts,const double& r)
{
	double PV = 0.0;
	for(int t=0; t < cflow_times.size();t++)
	{
		PV += cflow_amounts[t]/pow(1.0+r,cflow_times[t]);
	};

	return PV;
};

double cash_flow_irr_discrete(const std::vector<double>&  cflow_times,
	const std::vector<double> cflow_amounts)
{
	//simple minded irr function, find one root if exists

	//check whether length match
	if(cflow_times.size() != cflow_amounts.size()) return ERROR;

	const double ACCURACY = 1.0e-5;
	const int MAX_ITERATIONS = 50;
	double x1 = 0.0;
	double x2 = 0.2;

	//create an initial bracket, with a root somewhere between 
	double f1 = cash_flow_pv_discrete(cflow_times,cflow_amounts,x1);
	double f2 = cash_flow_pv_discrete(cflow_times,cflow_amounts,x2);

	int i;
	// apply bisection method
	for(i=0;i<MAX_ITERATIONS;i++)
	{	
		// make sure on different sides
		if(f1*f2<0) break;
		// adjust
		if(fabs(f1)<fabs(f2))
		{
			f1 = cash_flow_pv_discrete(cflow_times,cflow_amounts,x1+=1.6*(x1-x2));
		}
		else
		{
			f2 = cash_flow_pv_discrete(cflow_times,cflow_amounts,x2+=1.6*(x2-x1));

		};
	};
	if(f1*f2>0) return ERROR;
	double f = cash_flow_pv_discrete(cflow_times,cflow_amounts,x1);
	double rtb;
	double dx = 0;
	if(f<0.0)
	{
		rtb = x1;
		dx = x2-x1;
	}
	else
	{
		rtb = x2;
		dx = x1 - x2;
	};
	for(i=0;i<MAX_ITERATIONS;i++)
	{
		dx *= 0.5;
		double x_mid = rtb + dx;
		double f_mid = cash_flow_pv_discrete(cflow_times,cflow_amounts,x_mid);
		if(f_mid<= 0.0) rtb = x_mid;
		if((fabs(f_mid)<ACCURACY)||(fabs(dx)<ACCURACY)) return x_mid;
	};

	return ERROR;
}


int main()
{
	std::vector<double> cflows;
	cflows.push_back(-100.0);
	cflows.push_back(10.0);
	cflows.push_back(110.0);

	std::vector<double> times;
	times.push_back(0);
	times.push_back(1);
	times.push_back(2);

	double r = 0.05;
	std::cout << "present value, 5 percent dicretely compounded interest = ";
	std::cout << cash_flow_pv_discrete(times,cflows,r)<<std::endl;
	std::cout << "internal rate of return, discrete compoundeding= ";
	std::cout << cash_flow_irr_discrete(times,cflows)<<std::endl;

	return 0;
}

/*
present value, 5 percent dicretely compounded interest = 9.29705
internal rate of return, discrete compoundeding= 0.1
*/





