/*
x0 = 0 用迭代公式x_(k+1)=(2-e^x_k)/10 k=0,1,2,... 
求e^x+10x-2=0近似根 误差不超过0.0005
*/
#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;
double calculate(double x){
	return pow(M_E,x)+10*x-2;//e^x+10x-2
}

double x_iter(double x){
	return (2-pow(M_E,x))/10;//迭代公式
}

int main(){
	const double precision=0.0005;
	double x=0;
	double result = calculate(x);
	while(fabs(result)>precision){
		x = x_iter(x);//迭代x
		result = calculate(x);
	}
	cout<<setprecision(8)<<fixed<<x<<endl;
	cin.get();
	return 0;
}
