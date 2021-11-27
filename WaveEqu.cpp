#include<iostream>
#include<cmath>
using namespace std;

float U(float x,float t){
    if(x==0)
        return 0;
    else if(x==5)
        return 0;
    else if(t==0)
        return (x*(5-x));
    else 
        return -1;
}
float Ut(float x,float t){
    return 0;
}

int main(){
    cout<<"Enter the value of c^2 => ";float cc;cin>>cc;cout<<endl;
    cout<<"Lower limit of i => ";int li;cin>>li;cout<<endl;
    cout<<"Upper limit of i => ";int ui;cin>>ui;cout<<endl;
    cout<<"Lower limit of j => ";int lj;cin>>lj;cout<<endl;
    cout<<"Upper limit of j => ";int uj;cin>>uj;cout<<endl;
    cout<<"Enter the value of h => ";float h;cin>>h;cout<<endl;
    //cout<<"Enter the value of k => ";float k;cin>>k;cout<<endl;
    float k=h/(sqrt(cc));
    float alpha=k/h;
    float u[ui+2][uj+2];
    for(int j=lj;j<=uj;j++){
        for(int i=li;i<=ui;i=i+h){
            u[i][j]=U(i,j);
        }
    }
    for(int i=li+h;i<ui;i=i+h){
        u[i][1]=Ut(i,0)*k+u[i][0];
    }
    for(int j=lj+1;j<uj;j++){
        for(int i=li+h;i<ui;i=i+h){
            u[i][j+1]=u[i-1][j]+u[i+1][j]-u[i][j-1];
            //cout<<"u["<<i<<"]["<<j+1<<"] = "<<u[i][j+1]<<" ";
        }//cout<<endl;cout<<endl;
    }
    cout<<"Ans => \n\n";
    for(int j=lj;j<=uj;j++){
        for(int i=li;i<=ui;i=i+h){
            cout<<"u["<<i<<"]["<<j<<"] = "<<u[i][j]<<" ";
        }cout<<endl;
    }

    return 0;
}