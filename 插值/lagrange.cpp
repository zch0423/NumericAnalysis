#include <iostream>
#include <iomanip>
#define N 5
using namespace std;

void lagrange(double *x,double *fx,double t);
void display(double t,double ans);

int main(){
	double x[N] = {0.4,0.55,0.8,0.9,1};
	double fx[N] = {0.41075,0.57815,0.88811,1.02652,1.17520};
	cout<<"Lagrange"<<endl;
	lagrange(x,fx,0.5);
	lagrange(x,fx,0.7);
	lagrange(x,fx,0.85);
	return 0;
}

void lagrange(double *x,double *fx,double t){
	int i,j;
	double ans = 0;
	double numerator = 1;//分子
	double denominator = 1;//分母
	for(i=0;i<N;++i){
		numerator = 1;
		denominator = 1;
		for(j=0;j<N;++j){
			if(j!=i){
				numerator *= (t-x[j]);
				denominator *= (x[i]-x[j]);
			}
		}
		ans += numerator/denominator*fx[i];//加每一个基函数
	}
	display(t,ans);
}

void display(double t,double ans){
	//格式化输出
	cout<<"f("<<setprecision(2)<<fixed<<t<<"):"
		<<setprecision(6)<<fixed<<ans<<endl;
}
