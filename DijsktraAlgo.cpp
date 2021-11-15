#include<iostream>
using namespace std;
int min(int x,int y){
    if(x<=y)
        return x;
    else 
        return y;
}
int main(){
    cout<<"\n Give the total number of nodes => ";int m;cin>>m;cout<<endl;
    int W[m+1][m+1],Q[m+1][m+1];
    cout<<"Enter the values of the weighted matrix(row-wise) => \n\n";
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            cin>>W[i][j];
        }
    }
    //cout<<"Q["<<0<<"] =>\n";
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            if(W[i][j]==0){
                Q[i][j]=99999;
            }else{
                Q[i][j]=W[i][j];
            }
            //cout<<Q[i][j]<<"   ";
        }//cout<<endl;
    }

    for(int k=1;k<=m;k++){
        //cout<<"Q["<<k<<"] =>\n";
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                Q[i][j]=min(Q[i][j],Q[i][k]+Q[k][j]);
                //cout<<Q[i][j]<<"   ";
            }//cout<<endl;
        }
    }

    cout<<"Matrix Q containing shortest path is => \n\n";
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            cout<<Q[i][j]<<"   ";
        }cout<<endl;
    }

    return 0;
}