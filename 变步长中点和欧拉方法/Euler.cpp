#include <iostream>
#include <cmath>
#include <iomanip>
#define y0 1//y初始值
#define length 1//区间长度
using namespace std;

double calReal(double x);//计算真实值
double f(double x,double y);//计算f
double euler_iter(double x,double y,double y1,double h);//迭代
double* euler(double h);//欧拉方法
double* imEuler(double h);//改进欧拉方法
double relativeError(double result,double real);//计算相对误差
void display(double h,double* result1,double* result2);//显示

int main(){
    double *result1 = {};
    double *result2 = {};

    result1 = euler(0.1);
    result2 = imEuler(0.1);
    display(0.1,result1,result2);
    return 0;
}

double* euler(double h){
    //欧拉法
    double *result;
    int count;
    count = length/h+0.5;
    result = new double[count+1];//存放结果
    double x;
    double y = y0;//初始y x
    int i = 0;

    for(i=0;i<=count;++i){
        x = i*h;
        y = euler_iter(x,y,y,h);//迭代
        result[i] = y;
    }
    return result;
}

double* imEuler(double h){
    double *result;
    int count;//x个数
    count  = length/h+0.5;
    result = new double[count+1];
    double x,y=y0;
    double temp1,temp2;//存放中间变量T1 T2
    int i=0;

    result[0] = y0;//初值
    for(i=0;i<=count;++i){
        x = i*h;
        temp1 = euler_iter(x,y,y,h);
        temp2 = euler_iter(x+h,y,temp1,h);
        y = (temp1+temp2)/2;
        result[i+1] = y;//记录
    }
    return result;
}

void display(double h,double* result1,double* result2){
    int count;
    count = length/h+0.5;
    int i;
    double real=0,e1=0,e2=0;//真值和误差
    double x;
    double r1,r2;//对应欧拉方法和改进欧拉方法结果

    //标题
    cout<<setw(5)<<left<<"|xi"
    <<setw(10)<<"|Euler"
    <<setw(10)<<"|Erorr"
    <<setw(15)<<"|Improved Euler"
    <<setw(10)<<"|Error"
    <<setw(13)<<"|Real Result"<<'|'<<endl;
    for(i=0;i<=count;++i){
        x = i*h;
        real = calReal(x);//真值
        r1 = result1[i];
        r2 = result2[i];
        e1 = relativeError(r1,real);//误差
        e2 = relativeError(r2,real);
        //输出
        cout<<'|'<<setprecision(1)<<fixed<<setw(4)<<left<<x
        <<'|'<<setprecision(6)<<setw(9)<<r1
        <<'|'<<setprecision(6)<<setw(9)<<e1
        <<'|'<<setprecision(6)<<setw(14)<<r2
        <<'|'<<setprecision(6)<<setw(9)<<e2
        <<'|'<<setprecision(8)<<setw(12)<<real<<'|'<<endl;
    }

}

double relativeError(double result,double real){
    return abs(result-real)/real;
}

double calReal(double x){
    //真实值
    return pow((1+x*x),1/3.0);
}

double f(double x,double y){
    //计算f的值
    return 2*x/3/pow(y,2);
}

double euler_iter(double x,double y,double y1,double h){
    //计算迭代过程
    return y+h*f(x,y1);
}