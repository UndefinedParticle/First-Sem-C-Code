#include<iostream>
#include<cmath>
using namespace std;
float F(float x,float y){
    return x*x+y*y;
}
int main(){

    
    cout<<"Enter the number of total input of X => ";int n;cin>>n;cout<<endl;
    cout<<"Enter the value of h => ";float h;cin>>h;cout<<endl;
    float x[n],y[n];
    cout<<"Give the value of X0 => ";cin>>x[0];cout<<endl;
    cout<<"Give the value of Y0 => ";cin>>y[0];cout<<endl;
    cout<<"Enter the values of X1 to Xn => ";
    for(int i=1;i<n;i++)
        cin>>x[i];
    cout<<"Enter the values of Y1 to Yn => ";
    for(int i=1;i<n;i++)
        cin>>y[i];
    cout<<"---- Predictor ----\n";
    float f[n+1];
    f[n-1]=F(x[n-1],y[n-1]);
    f[n-2]=F(x[n-2],y[n-2]);
    f[n-3]=F(x[n-3],y[n-3]);
    y[n]=y[0]+((4*h)/3)*(2*f[n-1]-f[n-2]+2*f[n-3]);
    cout<<"y => "<<y[n]<<endl;
    f[n]=F(x[n],y[n]);
    cout<<"---- Corrector ----\n";
    y[n]=y[n-2]+((h)/3)*(f[n]+4*f[n-1]+f[n-2]);
    cout<<"y => "<<y[n]<<endl;

    return 0;
}