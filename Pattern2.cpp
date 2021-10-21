#include<iostream>
using namespace std;
int main(){
int n;
cout<<"Enter number of Line => \n";
cin>>n;
int m=n-2;
		if(n==1) {
			cout<<"  *";
		}else {
			for(int q=1;q<=n-1;q++)
				cout<<" ";
			cout<<"*"<<endl;
			
			for(int i=1;i<=m;i++) {
				for(int j=1;j<=m-i+1;j++)
					cout<<(" ");
				cout<<("*");
				for(int k=1;k<=2*i-1;k++)
					cout<<(" ");
				cout<<"*"<<endl;
			}
			for(int p=1;p<=n;p++)
				cout<<("* ");
			cout<<endl;
			
		}

}