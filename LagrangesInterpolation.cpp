#include<iostream>
#include<iomanip>
using namespace std;
int main(){
   int l=0;
   while(l==0){
        cout<<"Enter number of values of x => ";int n;cin>>n;
    cout<<"\n enter the values of x => \n";float x[n];
    for(int i=0;i<n;i++){
        cin>>x[i];
    }
     cout<<"\n enter the values of y => \n";float y[n];
    for(int i=0;i<n;i++){
        cin>>y[i];
    }
    cout<<"x \t f(x)\n";
    for(int i=0;i<n;i++){
        cout<<x[i]<<" \t "<<y[i]<<endl;
    }




    cout<<"\n Give the point where You want to evaluate f(x) => ";float p;cin>>p;
    float ans=0;
    for(int i=0;i<n;i++){
        float a,q=1;
        for(int j=0;j<n;j++){
            if(i!=j){
                q=q*((p-x[j])/(x[i]-x[j]));
                a=q;
            }
        }ans=ans+(a*y[i]);
       
    }
    cout<<"\n f("<<p<<") is => "<<fixed<<setprecision(3)<<ans<<endl;cout<<endl;
    cout<<"To run the code again press 0 Otherwise press 1.\n"<<endl;cin>>l;

   }
    return 0;
}