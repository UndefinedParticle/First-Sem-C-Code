#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main(){
    cout<<"Lower bound of  x => ";
    int x1;cin>>x1;cout<<endl;
    cout<<"Upper bound of  x => ";
    int x2;cin>>x2;cout<<endl;
    cout<<"Lower bound of  y => ";
    int y1;cin>>y1;cout<<endl;
    cout<<"Upper bound of  y => ";
    int y2;cin>>y2;cout<<endl;
    cout<<"Number of iteration => ";int ita;cin>>ita;cout<<endl;
    cout<<"Step length for X-axix => ";int lx;cin>>lx;cout<<endl;
    cout<<"Step length for Y-axix => ";int ly;cin>>ly;cout<<endl;
    int n=max(x2,y2);float u[n+1][n+1][ita+2];//u[i][j][k] where k is the number of iteration 
                                            // and k=0 means it is in initial stage.
    for(int i=y1;i<=x2;i=i+lx){              
        cout<<"u["<<i<<"]["<<y1<<"][0] = ";cin>>u[i][y1][0];cout<<endl;
        cout<<"u["<<i<<"]["<<y2<<"][0] = ";cin>>u[i][y2][0];cout<<endl;
    }
    for(int i=x1+lx;i<y2;i=i+ly){
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
            u[x1][i][k]=u[x1][i][0];
            u[x2][i][k]=u[x2][i][0];
        }
    }
    for(int j=y2-ly;j>y1;j=j-ly){
            for(int i=x1+lx;i<x2;i=i+lx){
                u[i][j][0]=0;
            }
        }cout<<endl;
    if(x2==4){
        int mid=x2/2;
        u[mid][mid][0]=(u[x1][mid][0]+u[x2][mid][0]+u[mid][y2][0]+u[mid][y1][0])/4;
        cout<<"u["<<mid<<"]["<<mid<<"][0] = "<<u[mid][mid][0]<<"  ";cout<<endl;
        for(int j=y2-1;j>y1;j=j-ly){
            for(int i=x1+1;i<x2;i=i+lx){
                if((i==(x1+lx))&&(j==(y2-ly)) || (i==(x2-lx))&&(j==(y2-ly)) || (i==(x1+lx))&&(j==(y1+ly)) || (i==(x2-lx))&&(j==(y1+ly))){
                    u[i][j][0]=(u[i-1][j+1][0]+u[i+1][j-1][0]+u[i+1][j+1][0]+u[i-1][j-1][0])/4;
                    cout<<"u["<<i<<"]["<<j<<"][0] = "<<u[i][j][0]<<"  ";
                }
            }cout<<endl;
        }
        for(int j=y2-1;j>y1;j=j-ly){
            for(int i=x1+1;i<x2;i=i+lx){
                if((i==(x1+lx))&&(j==(y2-ly)) || (i==(x2-lx))&&(j==(y2-ly)) || (i==(x1+lx))&&(j==(y1+ly)) || (i==(x2-lx))&&(j==(y1+ly))||(i==mid)&&(j==mid)){
                    continue;
                }else{
                    u[i][j][0]=(u[i-1][j][0]+u[i+1][j][0]+u[i][j+1][0]+u[i][j-1][0])/4;
                    cout<<"u["<<i<<"]["<<j<<"][0] = "<<fixed<<setprecision(2)<<u[i][j][0]<<"  ";
                }
            }cout<<endl;
        }cout<<endl;
 
    }else if(x2==3){
        for(int j=y2-ly;j>y1;j=j-ly){
            for(int i=x1+lx;i<x2;i=i+lx){
                if((i==x1+lx)&&(j==y2-ly)){
                    u[i][j][0]=(u[i-1][j+1][0]+u[i+1][j-1][0]+u[i+1][j+1][0]+u[i-1][j-1][0])/4;
                }else
                    u[i][j][0]=(u[i-1][j][0]+u[i+1][j][0]+u[i][j+1][0]+u[i][j-1][0])/4;
                cout<<"u["<<i<<"]["<<j<<"][0] = "<<fixed<<setprecision(2)<<u[i][j][0]<<"  ";
            }cout<<endl;
        }cout<<endl;
    }else{

        for(int j=y2-1;j>y1;j=j-ly){
            for(int i=x1+1;i<x2;i=i+lx){
                if((i==(x1+lx))&&(j==(y2-ly)) || (i==(x2-lx))&&(j==(y2-ly)) || (i==(x1+lx))&&(j==(y1+ly)) || (i==(x2-lx))&&(j==(y1+ly))){
                    u[i][j][0]=(u[i-1][j+1][0]+u[i+1][j-1][0]+u[i+1][j+1][0]+u[i-1][j-1][0])/4;
                    cout<<"u["<<i<<"]["<<j<<"][0] = "<<u[i][j][0]<<"  ";
                }
            }cout<<endl;
        }
        for(int j=y2-1;j>y1;j=j-ly){
            for(int i=x1+1;i<x2;i=i+lx){
                if((i==(x1+lx))&&(j==(y2-ly)) || (i==(x2-lx))&&(j==(y2-ly)) || (i==(x1+lx))&&(j==(y1+ly)) || (i==(x2-lx))&&(j==(y1+ly))){
                    continue;
                }else{
                    u[i][j][0]=(u[i-1][j][0]+u[i+1][j][0]+u[i][j+1][0]+u[i][j-1][0])/4;
                    cout<<"u["<<i<<"]["<<j<<"][0] = "<<fixed<<setprecision(2)<<u[i][j][0]<<"  ";
                }
            }cout<<endl;
        }cout<<endl;


    }

    //Gauss-Seidal Method
    for(int k=0;k<ita;k++){
        cout<<"Iteration "<<k+1<<endl;
        for(int j=y2-1;j>y1;j=j-ly){
            for(int i=x1+1;i<x2;i=i+lx){
                u[i][j][k+1]=(u[i-1][j][k+1]+u[i+1][j][k]+u[i][j+1][k+1]+u[i][j-1][k])/4;
                cout<<"u["<<i<<"]["<<j<<"]["<<k<<"] = "<<fixed<<setprecision(2)<<u[i][j][k]<<"  ";
                }cout<<endl;
            }cout<<endl;cout<<endl;
        }

    return 0;
}