
#include <cmath>
#include <vector>
#include <iostream>

double cash_flow_pv_discrete(const std::vector<double>& cflow_times, const std::vector<double>& cflow_amounts,const double& r)
{
	double PV = 0.0;
	for(int t=0; t < cflow_times.size();t++)
	{
		PV += cflow_amounts[t]/pow(1.0+r,cflow_times[t]);
	};

	return PV;
};

int main()
{
	std::vector<double> cflows;
	cflows.push_back(-100.0);
	cflows.push_back(75);
	cflows.push_back(75);

	std::vector<double> times;
	times.push_back(0);
	times.push_back(1);
	times.push_back(2);

	double r = 0.1;
	std::cout<<"Present value, 10 percent discretely compounded interest = "
	<<cash_flow_pv_discrete(times,cflows,r)<<std::endl;

	return 0;
}

//Present value, 10 percent discretely compounded interest = 30.1653