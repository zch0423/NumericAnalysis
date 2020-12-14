#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

void midPoint(double init_h,int n);
double calG(double h);

int main(){
    midPoint(0.8,9);
    return 0;
}

void midPoint(double init_h,int n){
    //p为最短步长
    cout<<"Real:"<<setprecision(10)<<fixed<<M_E<<endl;
    cout<<"Calculated result:"<<endl;
    cout.precision(6);
    int count = 1;
    while(count<=n){
        cout<<setw(3)<<left<<count<<calG(init_h)<<endl;
        init_h /= 2;//二分
        ++count;
    }
}

double calG(double h){
    //计算G
    double result = 0;
    result = (exp(1+h)-exp(1-h))/(2*h);
    return result;
}
