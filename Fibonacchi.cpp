#include<iostream>
using namespace std;
int fibonacchi(int n){
    if(n==0 || n==1)
        return n;
    return fibonacchi(n-1)+fibonacchi(n-2);
}

int main(){
    cout<<"Give an integer value => ";
    int n;cin>>n;cout<<endl;
    cout<<"Fibonacchi series for "<<n<<" is => \n";
    for(int i=0;i<=n;i++){
        cout<<fibonacchi(i)<<" ";
    }cout<<endl;
    return 0;
}