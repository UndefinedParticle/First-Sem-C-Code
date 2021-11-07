#include<iostream>
#include<cmath>
using namespace std;

float U(float x,float y){
    {if(x==0)return 0;
    if(x==4)return 8+2*y;
    if(y==0) return x*x/2;
    if(y==4) return x*x;}
    return -1;
}
/*float U2(float x=4,float y){
    return 8+2*y;
}
float U3(float x,float y=0){
    return (x*x)/2;
}
float U4(float x,float y=4){
    return x*x;
}*/
int main(){

    cout<<"         ----- Menu -----\n";cout<<endl;
    cout<<"   1. Using boundary equations.\n   2. Using boundary values.\n";cout<<endl;
    int input;cin>>input;
    switch(input){
        case 1:
            {
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
                int n=max(x2,y2);float u[n+1][n+1][ita+1];
                for(int k=0;k<=ita;k++){
                    for(int i=y1;i<=x2;i=i+lx){
                        u[i][y1][k]=U(i,y1);//cout<<"u["<<i<<"]["<<y1<<"] = "<<u[i][y1][k]<<"  ";
                        u[i][y2][k]=U(i,y2);//cout<<"u["<<i<<"]["<<y2<<"] = "<<u[i][y2][k]<<"  ";cout<<endl;
                        if(k==0){
                            cout<<"u["<<i<<"]["<<y1<<"][0] = "<<u[i][y1][k]<<"  ";
                            cout<<"u["<<i<<"]["<<y2<<"][0] = "<<u[i][y2][k]<<"  ";cout<<endl;
                        }
                    }
                }cout<<endl;
                for(int k=0;k<=ita;k++){
                    for(int i=x1;i<=y2;i=i+ly){
                        u[x1][i][k]=U(x1,i);//cout<<"u["<<x1<<"]["<<i<<"] = "<<u[x1][i][k]<<"  ";
                        u[x2][i][k]=U(x2,i);//cout<<"u["<<x2<<"]["<<i<<"] = "<<u[x2][i][k]<<"  ";cout<<endl;
                        if(k==0){
                            cout<<"u["<<x1<<"]["<<i<<"][0] = "<<u[x1][i][k]<<"  ";
                            cout<<"u["<<x2<<"]["<<i<<"][0] = "<<u[x2][i][k]<<"  ";cout<<endl;
                        }
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
                for(int k=0;k<ita;k++){
                    cout<<"Iteration "<<k+1<<endl;
                    for(int j=y2-1;j>y1;j=j-ly){
                        for(int i=x1+1;i<x2;i=i+lx){
                            u[i][j][k+1]=(u[i-1][j][k+1]+u[i+1][j][k]+u[i][j+1][k+1]+u[i][j-1][k])/4;
                            cout<<"u["<<i<<"]["<<j<<"]["<<k<<"] = "<<u[i][j][k]<<"  ";
                        }cout<<endl;
                    }cout<<endl;cout<<endl;
                }

            }
            break;
        case 2:
            {
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
                for(int k=0;k<ita;k++){
                    cout<<"Iteration "<<k+1<<endl;
                    for(int j=y2-1;j>y1;j=j-ly){
                        for(int i=x1+1;i<x2;i=i+lx){
                            u[i][j][k+1]=(u[i-1][j][k+1]+u[i+1][j][k]+u[i][j+1][k+1]+u[i][j-1][k])/4;
                            cout<<"u["<<i<<"]["<<j<<"]["<<k<<"] = "<<u[i][j][k]<<"  ";
                        }cout<<endl;
                    }cout<<endl;cout<<endl;
                }



            }
            break;
        default:
            cout<<"Given Input Is Not Found.\n";
    }



    return 0;
}


/*

for(int k=1;k<=ita;k++){
                    cout<<"Iteration "<<k<<endl;
                    for(int j=y2-1;j>y1;j--){
                        for(int i=x1+1;i<x2;i++){
                            if(k==1){
                                int mid=x2/2;
                                if(0==u[x1][mid]&&0==u[x2][mid]&&0==u[mid][y2]&&0==u[mid][y1]){
                                    u[mid][mid]=(u[x1][y2]+u[x2][y2]+u[x2][y1]+u[x1][y1]);
                                    
                                    cout<<"u["<<i<<"]["<<j<<"] = "<<u[mid][mid]<<"  ";cout<<endl;
                                    //u[i][j]=(u[i-1][j]+u[i+1][j]+u[i][j+1]+u[i][j-1]);
                                }else{
                                    u[mid][mid]=(u[x1][mid]+u[x2][mid]+u[mid][y2]+u[mid][y1]);
                                    //u[mid][mid]=(u[mid-1][mid+1]+u[mid+1][mid-1]+u[mid+1][mid+1]+u[mid-1][mid-1]);
                                    cout<<"u["<<i<<"]["<<j<<"] = "<<u[i][j]<<"  ";cout<<endl;
                                }
                            }else{
                                if(u[i-1][j]==0&&u[i+1][j]==0&&u[i][j+1]==0&&u[i][j-1]==0){
                                    u[i][j]=(u[i-1][j+1]+u[i+1][j-1]+u[i+1][j+1]+u[i-1][j-1]);
                                    
                                    cout<<"u["<<i<<"]["<<j<<"] = "<<u[i][j]<<"  ";cout<<endl;
                                }else{
                                    u[i][j]=(u[i-1][j]+u[i+1][j]+u[i][j+1]+u[i][j-1]);
                                    //u[i][j]=(u[i-1][j+1]+u[i+1][j-1]+u[i+1][j+1]+u[i-1][j-1]);
                                    cout<<"u["<<i<<"]["<<j<<"] = "<<u[i][j]<<"  ";cout<<endl;
                                }
                            }
                        }
                    }cout<<endl;

                }

*/