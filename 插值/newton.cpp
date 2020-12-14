#include <iostream>
#include <iomanip>
#define N 5
using namespace std;

void newton(double dif_table[N][N],double *x,double t);
void output(double t,double ans);
void table(double dif_table[N][N],double *x,double *fx);

int main(){
	double x[N] = {0.4,0.55,0.8,0.9,1};
	double fx[N] = {0.41075,0.57815,0.88811,1.02652,1.17520};
	double test[3] = {0.5,0.7,0.85};
	double dif_table[N][N]={};//差商表

	table(dif_table,x,fx);//计算差商表
	cout<<"Newton:"<<endl;
	for(int i=0;i<3;++i){
		newton(dif_table,x,test[i]);//计算值
	}
	return 0;
}

void newton(double dif_table[N][N],double *x,double t){
	int i,j;
	double ans = 0;
	double temp = 0;
	for(i=0;i<N;++i){
		temp = dif_table[i][i];
		for(j=0;j<i;++j){
			temp *= (t-x[j]);
		}
		ans += temp;
	}
	output(t,ans);
}

void table(double dif_table[N][N],double *x,double *fx){
	//完成差商表的计算
	int i,j;
	double temp;
	for(i=0;i<N;++i)
		dif_table[i][0] = fx[i];//第一列fx

	for(j=1;j<N;++j){
		//列
		for(i=j;i<N;++i){//行
			temp = (dif_table[i][j-1]-dif_table[i-1][j-1])/(x[i]-x[i-j]);//注意下标
			dif_table[i][j] = temp;
		}
	}
}

void output(double t,double ans){
	cout<<"f("<<setprecision(2)<<fixed
	<<t<<"):"<<setprecision(6)<<fixed
	<<ans<<endl;
}
