#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of the array => \n";
    cin>>n;
    cout<<"Give the elements of the array => \n";
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }cout<<"-----Internal process-----\n";
    for(int i=0;i<n-1;i++) {
        bool sorted=true;
			for(int j=0;j<n-1-i;j++) {

				if(a[j]>a[j+1]) {

					int temp=a[j];

					a[j]=a[j+1];

					a[j+1]=temp;
                    sorted=false;

				}

			}if(sorted) break;
            cout<<i<<" ) ";
			for(int k=0;k<n;k++)

				cout<<a[k]<<" ";

			cout<<endl;

		}

		cout<<endl;
    cout<<"The sorted numbers are => \n";

		for(int i=0;i<n;i++) {

			cout<<a[i]<<" ";

		}cout<<endl;
        return 0;
}