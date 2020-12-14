/*
x0 = 0 用牛顿迭代法 求e^x+10x-2=0近似根 误差不超过0.0005
牛顿迭代法 x_n = x_(n-1)-f(x_(n-1))/f'(x_(n-1))
*/
#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;
double calculate(double x){
	return pow(M_E,x)+10*x-2;//e^x+10x-2
}
double calculate_diff(double x){
	return pow(M_E,x)+10;//求导数值
}
double x_iter(double x){
	return x-calculate(x)/calculate_diff(x);//迭代
}
int main(){
	const double precision=0.0005;//精度
	double x=0;
	double result=calculate(x);
	while(fabs(result)>precision){
		x = x_iter(x);
		result = calculate(x);
	}
	cout<<setprecision(8)<<fixed<<x<<endl;
	cin.get();
	return 0;
}