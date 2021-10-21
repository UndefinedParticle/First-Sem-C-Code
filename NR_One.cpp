#include <iostream>
#include <cmath>
using namespace std;

float f(float x) { 
	return (x*x*x-x*x+2);
}

float df(float x) {
	return (3*x*x-2*x);
}

int main() {
	float a,x;
	cout<<"Give the initial value of the root => ";cin>>a;
	cout<<" x \t \t \t f(x) \n";cout<<endl;
	do{
		x=a-f(a)/df(a);
		cout<<x<<"\t \t"<<f(x)<<endl;
		a=x;
	}while(fabs(f(x))>0.0001);
	cout<<"The root of the equation by Newton Raphson method is => "<<x<<endl;

	return 0;
}