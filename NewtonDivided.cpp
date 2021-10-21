#include<iostream>
#include<iomanip>
using namespace std;
int main(){
    cout<<"Enter number of values of x => ";int n;cin>>n;
    cout<<"\n enter the values of x => \n";float x[n];
    for(int i=0;i<n;i++){
        cin>>x[i];
    }
     cout<<"\n enter the values of y => \n";float y[n];
    for(int i=0;i<n;i++){
        cin>>y[i];
    }cout<<endl;
    cout<<"x \t f(x)\n";
    for(int i=0;i<n;i++){
        cout<<x[i]<<" \t "<<y[i]<<endl;
    }
    float tempX[n],tempY[n];
    for(int i=0;i<n;i++){
        tempX[i]=x[i];tempY[i]=y[i];
    }
    
    float DivDiff[n-1][n-1];
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            DivDiff[i][j]=(tempY[j+1]-tempY[j])/(tempX[j+1+i]-tempX[j]);
            tempY[j]=DivDiff[i][j];
            
        }

    }cout<<endl;
    for(int i=0;i<n-1;i++){
        cout<<i+1<<" st order divided diff => ";
        for(int j=0;j<n-1-i;j++){
            cout<<DivDiff[i][j]<<"   ";
        }
        cout<<endl;
    }
    cout<<"\n Give the point where You want to evaluate f(x) => ";float p;cin>>p;
    float ans=y[0];
    for(int i=0;i<n-1;i++){
        float q=1;
        for(int k=0;k<=i;k++){
            q=q*(p-x[k]);
        }
        ans=ans+(q*DivDiff[i][0]);
    }
    cout<<"Required ans is => "<<fixed<<setprecision(3)<<ans<<endl;


    return 0;
}