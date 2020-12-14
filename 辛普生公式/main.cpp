#include <iostream>
#include <iomanip>
#include <cmath>
#define precision 5e-8
using namespace std;

double f1(double x);//e2
double f2(double x);//pi
double simpson(double a,double b,int n,double (*f)(double));
int isAllowedError(double a,double b,double (*f)(double));
void output(double ans,double rightAns);

int main(){
    double a1 = 1,b1 = 2;
    double a2 = 0,b2 = 1;
    double result1 = 0,result2 = 0;
    int n1 = 0,n2 = 0;
    double real1 = 0,real2 = 0;
    double (*f11)(double) = &f1;
    double (*f22)(double) = &f2;//函数指针
    n1 = isAllowedError(a1,b1,f11);
    n2 = isAllowedError(a2,b2,f22);
    result1 = simpson(a1,b1,n1,f11);
    result2 = simpson(a2,b2,n2,f22);
    real1 = M_E*M_E;
    real2 = M_PI;
    cout<<"Calculation for e^2"<<endl;
    output(result1,real1);
    cout<<"Calculation for pi"<<endl;
    output(result2,real2);
    return 0;
}

double f1(double x){
    return x*exp(x);
}

double f2(double x){
    return 4/(1+x*x);
}

double simpson(double a,double b,int n,double (*f)(double)){
    double dh = 0;
    dh = (b-a)/n/2;//h/2作为间隔
    double x;
    x = a+dh;//设置初始
    double s = 0;
    s = 4*f(x);
    for(int i=1;i<n;++i){
        x += dh;
        s += 2*f(x);//f(xi)
        x += dh;
        s += 4*f(x);//f(xi+1/2)
    }
    s = (f(a)+f(b)+s)*dh/3;//原来为h/6
    return s;
}

int isAllowedError(double a,double b,double (*f)(double)){
    int n = 0;
    double error = 1;
    double x = 0;
    double h = 0;
    //注意到函数单调
    x = (f(a)>f(b))?a:b;//取大
    while(abs(error)>=precision){
        n += 2;//n为偶数
        h = (b-a)/n;
        error = -pow(h,4)*(b-a)/180*pow(f(x),4);//误差计算
        cout<<setprecision(10)<<error<<endl;
    }   
    return n;
}

void output(double ans,double rightAns){
    cout<<"Calculation result:"<<setprecision(14)<<fixed<<ans<<endl;
    cout<<"Precise result:"<<setprecision(14)<<fixed<<rightAns<<endl;
}






