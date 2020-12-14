#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
#include <iomanip>
#define precision 0.0001
#define n 6 //行数
using namespace std;

void read_data(double matrix[n][n+1]);
void calculate_a(double a[n][n],double matrix[n][n+1]);
void calculate_b(double b[n],double matrix[n][n+1]);
bool reach_precision(double x1[n],double x2[n]);
int gauss_seidel(double x2[n],double a[n][n],double b[n]);
void display_result(double x2[n]);
void swap(double x1[n], double x2[n]);

int main(){
    //AX=b
    double matrix[n][n+1]={};
    double a[n][n]={};//aij/aii
    double b[n]={};//bij/aii
    double x2[n]={};//x_k+1
    int count = 0;

    read_data(matrix);
    calculate_a(a,matrix);
    calculate_b(b,matrix);
    count = gauss_seidel(x2,a,b);
    display_result(x2);
    cout<<"Total Recursion times: "<<count<<endl;
    return 0;
}

void read_data(double matrix[n][n+1]){
    string path;
    cout<<"Please enter the absolute file path of data:";
    cin>>path;
    ifstream inf(path.c_str());
    assert(inf.is_open());
    int row=0,col = 0;
    string line;
    while(getline(inf,line)) {//按行读取
        istringstream temp(line);
        col = 0;
        while(temp>>matrix[row][col++]){
            if(col%(n+1)==0)
                break;
        }
        ++row;
    }
}

void calculate_a(double a[n][n],double matrix[n][n+1]){
    //aij/aii
    for(int row=0;row<n;++row)
        for(int col=0;col<n;++col)
            a[row][col] = matrix[row][col]/matrix[row][row];
}

void calculate_b(double b[n],double matrix[n][n+1]){
    //bij/aii
    for(int i=0;i<n;++i)
        b[i] = matrix[i][n]/matrix[i][i];
}

int gauss_seidel(double x2[n],double a[n][n],double b[n]){
    //迭代求解
    int i = 0;
    int j = 0;
    double x1[n]={};//x_k=0
    double temp_x[n];
    double temp = 0;
    int count = 0;
    while(true){
        for(i=0;i<n;++i){//x_i
            temp = 0;
            for(j=0;j<i;++j)//j=0 j=i-1
                temp = temp-a[i][j]*temp_x[j];
            for(j=i+1;j<n;++j)
                temp = temp-a[i][j]*x1[j];
            temp = temp+b[i];
            temp_x[i] = temp;
        }
        ++count;
        swap(x2,temp_x);//temp_x -> x2
        if(reach_precision(x1,x2))
            return count;//结束程序返回迭代次数
        swap(x1,temp_x);//temp_x -> x1
    }
}

bool reach_precision(double x1[n],double x2[n]){
    //范数2判断精度
    double temp = 0;
    for(int i=0;i<n;++i)
        temp += pow((x1[i]-x2[i]),2);
    if (sqrt(temp)<=precision) //达到精度
        return true;
    return false;
}

void display_result(double x2[n]){
    cout<<"Results: ";
    for(int i=0;i<n;++i)
        cout<<setprecision(4)<<fixed<<x2[i]<<' ';
    cout<<endl;
}

void swap(double x1[n],double x2[n]){
    for(int i=0;i<n;++i)
        x1[i] = x2[i];
}