#include<iostream>
using namespace std;

float U(float x,float t){
    if(x==0)
        return 0;
    else if(x==8)
        return 0;
    else if(t==0)
        return (4*x-(x*x)/2);
    else 
        return -1;
}

int main(){
    cout<<"Enter the value of c^2 => ";float cc;cin>>cc;cout<<endl;
    cout<<"Lower limit of i => ";int li;cin>>li;cout<<endl;
    cout<<"Upper limit of i => ";int ui;cin>>ui;cout<<endl;
    cout<<"Lower limit of j => ";int lj;cin>>lj;cout<<endl;
    cout<<"Upper limit of j => ";int uj;cin>>uj;cout<<endl;
    cout<<"Enter the value of h => ";float h;cin>>h;cout<<endl;
    cout<<"Enter the value of k => ";float k;cin>>k;cout<<endl;
    float alpha=(cc*k)/(h*h);
    float u[ui+2][uj+2];
    for(int j=lj;j<=uj;j++){
        for(int i=li;i<=ui+1;i++){
            u[i][j]=U(i,j);
        }
    }
    if(alpha==0.5){
        for(int j=lj;j<=uj;j++){
            for(int i=li+h;i<=ui;i=i+h){
                u[i][j+1]=(u[i-1][j]+u[i+1][j])/2;
                cout<<"u["<<i<<"]["<<j+1<<"] = "<<u[i][j+1]<<" ";
            }cout<<endl;cout<<endl;
        }
    }else{
        for(int j=lj;j<=uj;j++){
            for(int i=li+h;i<=ui;i=i+h){
                u[i][j+1]=(alpha*u[i-1][j])+((1-2*alpha)*u[i][j])+alpha*u[i+1][j];
                cout<<"u["<<i<<"]["<<j+1<<"] = "<<u[i][j+1]<<" ";
            }cout<<endl;cout<<endl;
        }
    }

    return 0;
}