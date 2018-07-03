#include "stdio.h"

int main()
{
	float x[200]={0},y[200]={0};
	float qnf=60,qnw=20.518,qnd=39.482,qnl;
	float xf=0.65,xw=0.015,xd=0.98,R,Rmin=12.15,q=1;
	float xq=0.65,yq,a;
	int i ,j;
	R = 1.4* Rmin;
	qnl = qnd * R;
	x[0] = 1;
	y[1] = xd;
	printf( "请输入a\n");
	scanf( "%f" ,&a);
	for(i=1,j=2 ;x[i-1] > xq ;i++,j++)
	{
		x[i] = ( y[i] ) / ( a - (a-1) * y[i] );
		printf("x=%6f\n" ,x[i] );
		printf("y=%6f\n" ,y[i] );
		y[j] = R / (R+1) * x[i] + xd / (R+1);
	}
	printf("\n进料板=%d\n\n" ,i-1);
	for(i--,j--;x[j-2] > xw ;i++,j++)
	{
		y[j] = ( qnl + q * qnf ) / ( qnl + q * qnf - qnw ) * x[i] - qnw / (qnl + q * qnf - qnw ) * xw;
		x[j] = ( y[j] ) / ( a - (a-1) * y[j] );
		printf("x=%6f\n" ,x[i] );
		printf("y=%6f\n" ,y[i] );
	}
	printf("\n理论板数=%d\n",i);
	printf("效率0.7,实际板数=%0.2f\n",i/0.7);
	return 0;
}

