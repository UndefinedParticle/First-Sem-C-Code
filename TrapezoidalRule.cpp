#include<iostream>
#include<string>
#include<iomanip>
#include<cmath>
using namespace std;
float f(float x){
    return 1/(1+x*x);
}
int main(){
    float a,b,n;
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
    if(w%2!=0){
        cout<<"n Must be even no.\n";
    }else{
    cout<<"\n -----simpson's one-third Rule----- \n";
    float sum1=0,sum2=0;
    for(int i=1;i<m-1;i++){
        if(i%2==0)
            sum1=sum1+y[i];
            else 
                sum2=sum2+y[i];
    }
    float ans1=(h/3)*(y[0]+y[m-1]+2*sum1+4*sum2);
    cout<<"Your ans is => "<<ans1<<endl;
    cout<<"\n -----simpson's third-eight Rule----- \n";
    float sum3=0,sum4=0;int k=0;
    for(int i=3;i<m-2;i=i+3){
        sum3=sum3+y[i];
    }
    for(int i=1;i<m-1;i++){
        sum4=sum4+y[i];
    }
    float ans2=(3*h/8)*(y[0]+y[m-1]+(2*sum3)+3*(sum4-sum3));
    cout<<"Your ans is => "<<ans2<<endl;
    }
    /*cout<<"\n -----Weddles Rule----- \n";
    int p=n/6,q=n;
    float s=0;
    if(q%6==0)
    {
        for(int i=1; i<=p; i++)
        {
            s=s+((3*h/10)*(f(a)+f(a+2*h)+5*f(a+h)+6*f(a+3*h)+f(a+4*h)+5*f(a+5*h)+f(a+6*h)));
            a=a+6*h;
        }
        cout<<"Your ans is : "<<s<<endl;
    }
    else
    {
        cout<<" Weddle's rule is not applicable \n";
    }*/


return 0;
}