#include<iostream>
#include<cmath>
using namespace std;

void towerOfHanoi(int n,char beg,char aux,char end){
    if(n==1){
        cout<<beg<<" --> "<<end<<endl;
        return;
    }towerOfHanoi(n-1,beg,end,aux);
    cout<<beg<<" --> "<<end<<endl;
    towerOfHanoi(n-1,aux,beg,end);
    return;
}

int main(){
    cout<<"Enter the number of disks to be transformed => ";int n;cin>>n;cout<<endl;
    if(n<1){
        cout<<"Given input is not valid.\n";
    }else{
        cout<<"Total "<<pow(2,n)-1<<" moves are required for n="<<n<<" :-"<<endl;
        towerOfHanoi(n,'A','B','C');
    }cout<<endl;


    return 0;
}