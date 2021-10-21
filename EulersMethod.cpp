#include<iostream>
using namespace std;

float f(float x,float y){
    return x-y;
}

int main(){
    cout<<"--- Eulers's Method ---\n";cout<<endl;
    cout<<"Give the nuymber of values of x => ";int n;cin>>n;cout<<endl;
    cout<<"Enter the value of h => ";float h;cin>>h;cout<<endl;
    float x[n+1],y[n+1];
    cout<<"Enter the initial value of x => ";cin>>x[0];
    cout<<"Enter the initial value of y => ";cin>>y[0];
    cout<<"Enter the values of x => \n";
    for(int i=1;i<n+1;i++){
        cin>>x[i];
    }cout<<endl;
    
    for(int i=0;i<n;i++){
        cout<<"When x= "<<x[i+1]<<" then ";
        y[i+1]=y[i]+h*f(x[i],y[i]);
        cout<<"y= "<<y[i+1]<<endl;
    }cout<<endl;
    cout<<"--- Modified Eulers's Method ---\n";cout<<endl;
    cout<<"Give the nuymber of values of x => ";int m;cin>>m;cout<<endl;
    cout<<"Enter the value of h => ";float h1;cin>>h1;cout<<endl;
    float x1[n+1],y1[n+1];
    cout<<"Enter the initial value of x => ";cin>>x[0];
    cout<<"Enter the initial value of y => ";cin>>y[0];
    cout<<"Enter the values of x => \n";
    for(int i=1;i<n+1;i++){
        cin>>x[i];
    }cout<<endl;

    return 0;
}