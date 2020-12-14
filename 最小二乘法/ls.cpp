#include <iostream>
#include <iomanip>
#include <cmath>
#define N 2
#define n 9//9组数据
using namespace std;

void solve(double matrix[N+1][N+1],double a[N+1],double b[N+1]);
//求解a
void cal_matrix(double x[n],double matrix[N+1][N+1]);
//计算矩阵A
void sum(double x[n],double y[n],double b[N+1]);
//计算右边一列
void sum(int m,double x[n],double matrix[N+1][N+1]);
//计算matrix的第m列 依次为x^m x^(m+1)
void output(double a[N+1]);
//格式化输出

int main(){
    double x[n] = {1,3,4,5,6,7,8,9,10};
    double y[n] = {10,5,4,2,1,1,2,3,4};
    double matrix[N+1][N+1]={};
    double b[N+1] = {};
    double a[N+1] = {};
    cal_matrix(x,matrix);//求出A
    sum(x,y,b);//求出b
    solve(matrix,a,b);
    output(a);
    return 0;
}

void cal_matrix(double x[n],double matrix[N+1][N+1]){
    int m = 0;
    for(m=0;m<(N+1);++m)
        sum(m,x,matrix);
}

void sum(double x[n],double y[n],double b[N+1]){
    int i,j;
    double temp = 0;
    int m = 0;
    for(i=0;i<(N+1);++i){
        temp = 0;//重置
        for(j=0;j<n;++j)
            temp += (pow(x[j],m)*y[j]);
        b[i] = temp; 
        ++m;
    }
}

void sum(int m,double x[n],double matrix[N+1][N+1]){
    int i,j;
    int count = m;
    double temp = 0;
    for(i=0;i<(N+1);++i){
        temp = 0;//重置
        for(j=0;j<n;++j){
            temp += pow(x[j],count);
        }
        matrix[i][m] = temp;
        ++count;
    }
}

void solve(double matrix[N+1][N+1],double a[N+1],double b[N+1]){
    //列主元法求解
    double l;//相除结果
    int i=0,j=0,k=0;
    double pivot;
    int index;//记录
    double temp;
    for(i=0;i<(N+1);i++){
        index = i;//初始化
        pivot = abs(matrix[i][i]);//初始化
        for(j=i+1;j<(N+1);j++){
            if(abs(matrix[j][i])>abs(pivot)){
                pivot=abs(matrix[j][i]);
                index = j;
            }
        }
        if(index>i){
            //如果主元改变交换行
            for(k=i;k<(N+1);k++){
                temp = matrix[i][k];
                matrix[i][k] = matrix[index][k];
                matrix[index][k] = temp;
            }
            //交换b的行
            temp = b[i];
            b[i] = b[index];
            b[index] = temp;
        }

        //消去
        for(j=i+1;j<(N+1);j++){//行
            l = matrix[j][i]/matrix[i][i];
            for(k=i;k<(N+1);k++){//列
                matrix[j][k]=matrix[j][k]-matrix[i][k]*l;//消去
            }
            b[j]-=l*b[i];
        }
    }
    for(i=N;i>=0;i--){
        for(j=N;j>i;j--){
            b[i]-=a[j]*matrix[i][j];
        }
        a[i]=b[i]/matrix[i][i];
    }
}

void output(double a[N+1]){
    for(int i=0;i<(N+1);++i){
        cout<<setprecision(4)<<fixed
        <<'a'<<i<<':'<<a[i]<<' ';
    }
}
