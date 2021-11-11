#include<iostream>
#include<cmath>
using namespace std;

// use f function for 1st order equ.

float f(float x,float y){
    return x+y;
}

// please use f1 and g function for 2nd order equ.

float f1(float t,float x,float z){
    return z+x*x;
}
float g(float t,float x,float z){
    return t+x*x;
}
int main(){
    cout<<"Order of the main equation => ";int o;cin>>o;cout<<endl;
    switch(o){
        case 1:
            {
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
            }
            break;
        case 2:
            {
                cout<<"Give the value of T where you want to calculate X & Z => ";float p;cin>>p;cout<<endl;
                cout<<"Enter the value of h => ";float h;cin>>h;cout<<endl;
                cout<<"Give the value of T0 => ";float t0;cin>>t0;cout<<endl;
                cout<<"Give the value of X0 => ";float x0;cin>>x0;cout<<endl;
                cout<<"Give the value of Z0 => ";float z0;cin>>z0;cout<<endl;
                float k1,k2,k3,k4;
                float l1,l2,l3,l4;
                k1=h*f1(t0,x0,z0);l1=h*g(t0,x0,z0);
                k2=h*f1(t0+h/2,x0+k1/2,z0+l1/2);l2=h*g(t0+h/2,x0+k1/2,z0+l1/2);
                k3=h*f1(t0+h/2,x0+k2/2,z0+l2/2);l3=h*g(t0+h/2,x0+k2/2,z0+l2/2);
                k4=h*f1(t0+h,x0+k3,z0+l3);l4=h*g(t0+h,x0+k3,z0+l3);
                float k=(k1+2*k2+2*k3+k4)/6;cout<<"k is "<<k<<endl;
                float l=(l1+2*l2+2*l3+l4)/6;cout<<"l is "<<l<<endl;
                float x1=x0+k,z1=z0+l;
                cout<<"X("<<p<<") is "<<x1<<endl;
                cout<<"Z("<<p<<") is "<<z1<<endl;

            }
            break;
        default:
            cout<<"Code is not available for this case\n";
    }
    


    return 0;
}