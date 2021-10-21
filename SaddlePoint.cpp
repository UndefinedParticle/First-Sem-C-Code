#include<iostream>
using namespace std;
int main(){
    int m,n;
    cout<<"Enter the value of m => \n";cin>>m;
    cout<<"Enter the value of n => \n";cin>>n;
    cout<<"give the values of the matrix (row-wise) => \n";
    int a[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }cout<<endl;cout<<endl; 
    bool myBool=false;
    for(int i=0;i<m;i++){
        int MinInRow=a[i][0];
        int column=0;
        for(int j=0;j<n;j++){
            if(MinInRow>a[i][j]){
                MinInRow=a[i][j];
                column=j;
            }
        }int k;
        for( k=0;k<m;k++){
            if(MinInRow<a[k][column]){
                break;
            }
        }
        if(k==m){
            cout<<MinInRow<<" is a saddle point.\n";
            myBool=true;
        }
        
    }
    


    for(int i=0;i<m;i++){
        int MaxInRow=a[i][0];
        int column=0;
        for(int j=0;j<n;j++){
            if(MaxInRow<a[i][j]){
                MaxInRow=a[i][j];
                column=j;
            }
        }int k;
        for( k=0;k<m;k++){
            if(MaxInRow>a[k][column]){
                break;
            }
        }
        if(k==m){
            cout<<MaxInRow<<" is a saddle point.\n";
            myBool=true;
        }
        
    }
    if(myBool==false){
        cout<<"There is no saddle point. \n";
    }

}