#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main(){

        cout<<"Give the dimension of the Square matrix => \n";
        int n; cin>>n;
        float coMatrix[n][n];
        cout<<"-----Please Give a Tridiagonal matrix -----\n";
        cout<<"Please Give the values of the coefficient matrix => \n";
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                cin>>coMatrix[i][j];
            }
        } float x[n];float d[n];
         
        cout<<"Give the values of d_i's => ";
        for(int i=0;i<n;i++) {
            cin>>d[i];
            
        }
        float alpha[n];float beta[n];
        float a[n];float b[n];float c[n];
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(i==j)
                    b[i]=coMatrix[i][j];
            }
        }
        for(int i=1;i<n;i++) {
            for(int j=0;j<n-1;j++) {
                if(j==i-1)
                    a[i]=coMatrix[i][j];
            }
        }
        for(int i=0;i<n-1;i++) {
            for(int j=1;j<n;j++) {
                if(j==i+1)
                    c[i]=coMatrix[i][j];
            }
        }

        alpha[0]=b[0];beta[0]=((d[0])/(b[0]));
        
        for(int i=1;i<n;i++) {
            alpha[i]=b[i]-((a[i]*c[i-1])/alpha[i-1]);
        }
        for(int i=1;i<n;i++) {
            beta[i]=((d[i]-(a[i]*beta[i-1]))/alpha[i]);
        }
        x[n-1]=beta[n-1];
        for(int i=n-2;i>=0;i--) {
            x[i]=beta[i]-((c[i]*x[i+1])/alpha[i]);
        }
        cout<<" The required solution is => \n";
        cout<<"[ ";
        for(int i=0;i<n;i++) {
            cout<<fixed<<setprecision(3)<<x[i]<<"  ";
        }cout<<" ]\n";
    
    
    return 0;
}