#include <iostream>
#include <iomanip>
#include <cmath>
#define n 4
using namespace std;
int main(){
	//column principle elimination
	float a[n][n]={1.1348,3.8326,1.1651,3.4017,
	                0.5301,1.7875,2.5330,1.5435,
	                3.4129,4.9317,8.7643,1.3142,
	                1.2371,4.9998,10.6721,0.0147};
	float b[n]={9.5342,6.3941,18.4231,16.9237};
	float l;//divisor
	int i=0,j=0,k=0;
	float pivot;//pivot column
	int index;//record the row index for pivot column
	float temp;
	for(i=0;i<n;i++){//a[i][i]
		// select pivot with maximum value
		index = i;//initialize
		pivot = abs(a[i][i]);//initialize
		for(j=i+1;j<n;j++){
			if(abs(a[j][i])>abs(pivot)){
				pivot=a[j][i];
				index = j;//update
			}
		}
		if(index>i){
			//pivot changed then exchange the row
			for(k=i;k<n;k++){
				temp = a[i][k];
				a[i][k] = a[index][k];
				a[index][k] = temp;
			}
			//exchange rows of b as well
			temp = b[i];
			b[i] = b[index];
			b[index] = temp;
		}

		//elimination
	    for(j=i+1;j<n;j++){//row
	        l = a[j][i]/a[i][i];
	        for(k=i;k<n;k++){//column
	            a[j][k]=a[j][k]-a[i][k]*l;//eliminate
	        }
	        b[j]-=l*b[i];//update b[j]
	    }
	}
	float x[n]={};//solve
	for(i=n-1;i>=0;i--){
	    for(j=n-1;j>i;j--){
	        b[i]-=x[j]*a[i][j];//update b[i]
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