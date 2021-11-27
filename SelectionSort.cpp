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
    }
    int min,min1;
    cout<<"-----Internal process-----\n";
    for(int i=0;i<n-1;i++) {
        
        min=i;min1=min;
			for(int j=i;j<n;j++) {

				if(a[min]>a[j]) {
                    min=j;
				}

			}
            if(min==min1){
                continue;
            }
          int temp=a[i];
           a[i]=a[min];
           a[min]=temp;

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