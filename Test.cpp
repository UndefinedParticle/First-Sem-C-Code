#include<iostream>
#include<cmath>
using namespace std;
//Akshat Pandey 21ms0013
int main()
{
cout<<"Please be careful while entering"<<endl;
     
    cout<<" Using boundary values.\n";cout<<endl;
    cout<<"My u1 start from u13"<<endl;
                cout<<"Lower bound of  x is? ";
                int x1;cin>>x1;cout<<endl;
                cout<<"Upper bound of  x is? ";
                int x2;cin>>x2;cout<<endl;
                cout<<"Lower bound of  y is?";
                int y1;cin>>y1;cout<<endl;
                cout<<"Upper bound of  y is? ";
                int y2;cin>>y2;cout<<endl;
                cout<<"Number of iteration you want ";int ita;cin>>ita;cout<<endl;
                cout<<"Step length for X-axix ? ";int lx;cin>>lx;cout<<endl;
                cout<<"Step length for Y-axix ? ";int ly;cin>>ly;cout<<endl;
                int n=max(x2,y2);float u[n+1][n+1][ita+2];
                for(int i=y1;i<=x2;i=i+lx){
                    cout<<"u["<<i<<"]["<<y1<<"][0] = ";cin>>u[i][y1][0];cout<<endl;
                    cout<<"u["<<i<<"]["<<y2<<"][0] = ";cin>>u[i][y2][0];cout<<endl;
                }
                for(int i=x1;i<=y2;i=i+ly){
                    cout<<"u["<<x1<<"]["<<i<<"][0] = ";cin>>u[x1][i][0];cout<<endl;
                    cout<<"u["<<x2<<"]["<<i<<"][0] = ";cin>>u[x2][i][0];cout<<endl;
                }
                for(int k=1;k<=ita;k++){
                    for(int i=y1;i<=x2;i=i+lx){
                        u[i][y1][k]=u[i][y1][0];
                        u[i][y2][k]=u[i][y2][0];
                    }
                }
                for(int k=1;k<=ita;k++){
                    for(int i=y1;i<=x2;i=i+lx){
                        u[i][y1][k]=u[x1][i][0];
                        u[x2][i][k]=u[x2][i][0];
                    }
                }
                for(int j=y2-1;j>y1;j--){
                    for(int i=x1+1;i<x2;i++){
                        u[i][j][0]=0;
                    }
                }cout<<endl;
                int mid=x2/2;
                u[mid][mid][0]=(u[x1][mid][0]+u[x2][mid][0]+u[mid][y2][0]+u[mid][y1][0])/4;
                cout<<"u["<<mid<<"]["<<mid<<"][0] = "<<u[mid][mid][0]<<"  ";cout<<endl;
                for(int j=y2-1;j>y1;j=j-ly){
                    for(int i=x1+1;i<x2;i=i+lx){
                        if((i==(x1+lx))&&(j==(y2-ly)) || (i==(x2-lx))&&(j==(y2-ly)) || (i==(x1+lx))&&(j==(y1+ly)) || (i==(x2-lx))&&(j==(y1+ly))){
                            u[i][j][0]=(u[i-1][j+1][0]+u[i+1][j-1][0]+u[i+1][j+1][0]+u[i-1][j-1][0])/4;
                            cout<<"u["<<i<<"]["<<j<<"][0] = "<<u[i][j][0]<<"  ";
                        }
                    }
                    cout<<endl;
                }
                for(int j=y2-1;j>y1;j=j-ly){
                    for(int i=x1+1;i<x2;i=i+lx){
                        if((i==(x1+lx))&&(j==(y2-ly)) || (i==(x2-lx))&&(j==(y2-ly)) || (i==(x1+lx))&&(j==(y1+ly)) || (i==(x2-lx))&&(j==(y1+ly))||(i==mid)&&(j==mid)){
                            continue;
                        }else{
                            u[i][j][0]=(u[i-1][j][0]+u[i+1][j][0]+u[i][j+1][0]+u[i][j-1][0])/4;
                            cout<<"u["<<i<<"]["<<j<<"][0] = "<<u[i][j][0]<<"  ";
                        }
                    }cout<<endl;
                }cout<<endl;
                //Gauss-Seidal Method
                for(int k=0;k<ita;k++)
                {
                    cout<<"Iteration "<<k+1<<endl;
                    for(int j=y2-1;j>y1;j=j-ly){
                        for(int i=x1+1;i<x2;i=i+lx){
                            u[i][j][k+1]=(u[i-1][j][k+1]+u[i+1][j][k]+u[i][j+1][k+1]+u[i][j-1][k])/4;
                            cout<<"u["<<i<<"]["<<j<<"]["<<k<<"] = "<<u[i][j][k]<<"  ";
                        }cout<<endl;
                    }cout<<endl;cout<<endl;}      
        return 0;
}