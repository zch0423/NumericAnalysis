#include <iostream>
#include <iomanip>
#define n 4
using namespace std;

int main() {
    //Gauss elimination
    float a[n][n]={1.1348,3.8326,1.1651,3.4017,
                    0.5301,1.7875,2.5330,1.5435,
                    3.4129,4.9317,8.7643,1.3142,
                    1.2371,4.9998,10.6721,0.0147};
    float b[n]={9.5342,6.3941,18.4231,16.9237};
    //get a and b by input
    /*
    for(int i=0;i<n;i++){
        cout<<"Please enter row"<<i+1;
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    cout<<"Please enter the value of b:";
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    cout<<endl;
    */
    float l;//divisor
    int i=0,j=0,k=0;
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            l = a[j][i]/a[i][i];
            for(k=i;k<n;k++){
                a[j][k]=a[j][k]-a[i][k]*l;//eliminate
            }
            b[j]-=l*b[i];//update b[j]
        }
    }
    float x[n]={};//solve
    for(i=n-1;i>=0;i--){
        for(j=n-1;j>i;j--){
            b[i]-=x[j]*a[i][j];
        }
        x[i]=b[i]/a[i][i];
    }
    cout<<"Solution:";
    for(i=0;i<n;i++){
        cout<<fixed<<setprecision(4)<<x[i]<<' ';
    }
    cout<<endl;
    cin.get();
    return 0;
}