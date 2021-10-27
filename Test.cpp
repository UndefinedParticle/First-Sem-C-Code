#include<stdio.h>
//#include<conio.h>
#include<math.h>
//#define F(x,y) sqrt(x+y)
float F(float x,float y)
{
    return 3*x+(y/2);
}
int main()
{
	float x0,y0,h,a,k1,k2,k3,k4,k,f;
	int i,n;
    printf("Enter the initial value of x: ");
	scanf("%f",&x0);
	printf("enter the initial value of y: ");
	scanf("%f",&y0);
	printf("Enter the step length h : ");
	scanf("%f",&h);
	printf("Enter the value of last point: ");
	scanf("%f",&a);
	n=(a-x0)/h;
	for(i=1;i<=n;i++)
	{
		k1=h*F(x0,y0);
		k2=h*F(x0+h/2,y0+k1/2);
		k3=h*F(x0+h/2,y0+k2/2);
		k4=h*F(x0+h,y0+k3);
		k=(k1+k4+2*(k2+k3))/6;
		printf(" k1=%f , k2=%f , k3=%f , k4=%f , k=%f ",k1,k2,k3,k4,k);
		f=y0+k;
		printf("***The required value at x=%f  is y%d=%f",x0+h,i,f);
		x0=x0+h;
		y0=f;
	}
	return 0;
}