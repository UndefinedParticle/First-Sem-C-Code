#include<iostream>
using namespace std;
long factorial(int n){
    if(n==0)
        return 1;
    return (n*factorial(n-1));
}

int main(){
    cout<<"Enter an integer value => ";
    int n;cin>>n;cout<<endl;
    cout<<"Factorial of "<<n<<" is => "<<factorial(n)<<endl;
    return 0;
}