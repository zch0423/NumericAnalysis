/*
在区间[0,1]内用二分法求方程e^x+10x-2=0的近似根，要求误差不超过0.0005
*/
#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;
double calculate(double x){
	return pow(M_E,x)+10*x-2;//e^x+10x-2
}

double bisection(double a=0,double b=1){
	//递归法求解
	const double precision = 0.0005;
	double temp=(a+b)/2;
	double result=calculate(temp);

	if(fabs(result)<precision){
		return (a+b)/2;
	}
	if(result>0){
		return bisection(a,temp);
	}
	else{
		return bisection(temp,b);
	}

}

int main(){
	//观察得f(0)<0,f(1)>0 且f(x)递增
	const double precision = 0.0005;//精度
	double a=0,b=1;//上下值
	double result = calculate((a+b)/2);

	while(fabs(result)>precision){
		if(result>0){
			b = (a+b)/2;
		}
		else{
			a = (a+b)/2;
		}
		result = calculate((a+b)/2);
	}
	cout<<setprecision(8)<<fixed<<(a+b)/2<<endl;//小数点后8位
	// cout<<bisection()<<endl;//递归法
	cin.get();
	return 0;
}