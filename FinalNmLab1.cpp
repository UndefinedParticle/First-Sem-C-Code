#include<iostream>   //Chinmoy Mondal
#include<string>    //Admission No is => 21MS044
#include<iomanip>
#include<cmath>
using namespace std;
float f(float x){
    return 1/(1+x);
}

int main(){
    float a,b,n;cout<<endl;cout<<endl;
    cout<<"Please enter the limit where the function is continuous properly.\n\n";
    cout<<"Enter the value of a => ";cin>>a;
    cout<<"Enter the value of b => ";cin>>b;
   // b=acos(0.0);
    cout<<"Enter the value of n => ";cin>>n;
    int w=n;
    float h=(b-a)/n;
    int m=n+1;
    float x[m],y[m];
    x[0]=a;
    for(int i=1;i<m;i++){
        x[i]=x[i-1]+h;
    }
    for(int i=0;i<m;i++){
        y[i]=f(x[i]);
    }
    cout<<"x :  ";
    for(int i=0;i<m;i++){
        cout<<x[i]<<"  ";
    }cout<<endl;
    cout<<"f(x) :  ";
    for(int i=0;i<m;i++){
        cout<<fixed<<setprecision(4)<<y[i]<<"  ";
    }cout<<endl;
    cout<<"\n -----Trapezoidal Rule----- \n";
    float sum=0;
    for(int i=1;i<m-1;i++){
        sum=sum+y[i];
    }
    float ans=(h/2)*(y[0]+y[m-1]+2*(sum));
    cout<<"Your ans is => "<<ans<<endl;

    return 0;
}