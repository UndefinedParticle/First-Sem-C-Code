#include<iostream>
using namespace std;

int main(){
    cout<<"Order of the Matrix => ";int m;cin>>m;cout<<endl;
    int a[m][m];
    cout<<"Enter the the value of r for A^r => ";int r;cin>>r;cout<<endl;
    cout<<"Enter the elements of A matrix row wise => \n";
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
        
    int b[m][m],c[m][m];
    int P[m][m];
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            b[i][j]=a[i][j];
            P[i][j]=a[i][j];
        }
    }

    for(int z=2;z<=r;z++){
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                //c[i][j] = 0;
                int sum=0;
                for (int k = 0; k < m; k++)
                    sum=sum+ b[i][k] * a[k][j];
                c[i][j]=sum;
                sum=0;
            }
        }cout<<endl;
        cout<<"A^"<<z<<" is => \n";
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                b[i][j]=c[i][j];
                P[i][j]=P[i][j]+b[i][j];
                cout<<b[i][j]<<" ";
            }cout<<endl;
        }

    }cout<<endl;

    cout<<"B"<<r<<" is => \n";
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            cout<<P[i][j]<<" ";
        }cout<<endl;
    }cout<<endl;
    cout<<"Path matrix is => \n";
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            if(P[i][j]!=0)
                cout<<"1 ";
            else
                cout<<P[i][j]<<" ";
        }cout<<endl;
    }

    
    return 0;
}