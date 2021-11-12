#include<iostream>
#include<cmath>
using namespace std;
//Chinmoy Mondal
//Admission No. 21MS0044
// use f function for 1st order equ.

float f(float x,float y){
    return 6*x+y;
}
int main(){
    
    cout<<"Give the value of X where you want to calculate Y => ";float p;cin>>p;cout<<endl;
    cout<<"Enter the value of h => ";float h;cin>>h;cout<<endl;
    float m=p/h;int n=(int)m;
    cout<<"Give the value of X0 => ";float x[n+1];cin>>x[0];cout<<endl;
    cout<<"Give the value of Y0 => ";float y[n+1];cin>>y[0];cout<<endl;
    float k1,k2,k3,k4;
    for(int i=0;i<n;i++){
        cout<<endl;
        cout<<"Step:- "<<i+1<<endl;
        k1=h*f(x[i],y[i]);cout<<"k1 is "<<k1<<endl;
        k2=h*f(x[i]+(h/2),y[i]+(k1/2));cout<<"k2 is "<<k2<<endl;
        k3=h*f(x[i]+(h/2),y[i]+(k2/2));cout<<"k3 is "<<k3<<endl;
        k4=h*f(x[i]+h,y[i]+k3);cout<<"k4 is "<<k4<<endl;
        float k;
        k=(k1+2*k2+2*k3+k4)/6;cout<<"k is "<<k<<endl;
        y[i+1]=y[i]+k;
        x[i+1]=x[i]+h;
        cout<<"Y["<<i+1<<"] = "<<y[i+1]<<endl;
    }
    cout<<"required ans is "<<y[n]<<endl;
    return 0;
}