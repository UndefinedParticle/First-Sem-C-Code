#include<iostream>
#include<iomanip>
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
    float x1[m],y1[m][m+1];
    cout<<"Enter the values of x => \n";
    for(int i=1;i<m+1;i++){
        cin>>x1[i];
    }cout<<endl;
    float nX=x[0],nY=y[0];
    float temp;
    for(int i=1;i<m+1;i++){
        y1[i][0]=nY+h1*f(nX,nY);
        cout<<"For X= "<<x1[i]<<endl;
        cout<<"     Y"<<i<<"^("<<0<<") = "<<y1[i][0]<<endl;
        for(int j=1;j<=m+1;j++){
            y1[i][j]=nY+((h1/2)*(f(nX,nY)+f(x1[i],y1[i][j-1])));
            cout<<"     Y"<<i<<"^("<<j<<") = "<<y1[i][j]<<endl;
            temp=y1[i][j];
        }cout<<endl;
        nX=x1[i];
        nY=temp;
    }

    return 0;
}