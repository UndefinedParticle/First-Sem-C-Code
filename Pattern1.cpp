#include<iostream>
using namespace std;
int main(){

    cout<<"Enter nummber of line => ";
    int n; cin>>n;
    for(int i=1;i<=n;i++) {
			for(int j=1;j<=n-i+1;j++) {
				cout<<" ";
			}
			for(int k=1;k<=i;k++) {
				cout<<"* ";
			}
			cout<<endl;
		}
		cout<<endl;
		for(int i=1;i<=n;i++) {
			
			for(int k=1;k<=i;k++) {
				cout<<" ";
			}
			
			for(int j=1;j<=n-i+1;j++) {
				cout<<"* ";
			}
			
			cout<<endl;
		}
        return 0;


}