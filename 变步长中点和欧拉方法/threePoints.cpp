#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

void threePoint(double h,double x);
double f(double x);

int main(){
    cout<<"Real:"<<setprecision(10)
    <<fixed<<M_E<<endl;
    double h1 = 1,h2 = 0.1, h3 = 0.01;
    double x = 1;
    cout<<"Calculated result:"<<endl;
    cout.precision(3);
    threePoint(h1,x);
    threePoint(h2,x);
    threePoint(h3,x);
    return 0;
}

double f(double x){
    //f(x)的值
    return exp(x);
}

void threePoint(double h,double x){
    //根据中心差商公式计算
    double x0 = x-h;
    double x2 = x+h;
    double result = 0;
    result = (f(x2)-f(x0))/(2*h);
    cout<<result<<endl;
}


