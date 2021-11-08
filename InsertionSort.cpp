#include<iostream>
#include<cmath>
using namespace std;

void insertionSort(int a[],int n){
    for(int i=1;i<n;i++){
        int current=a[i];
        int j=i-1;
        while(a[j]>current&&j>=0){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=current;
    }
}

int main(){
    cout<<"Enter the size of the arrray=> ";int n;cin>>n;cout<<endl;
    cout<<"Enter the elements of the array => \n";
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    insertionSort(arr,n);

    cout<<"The sorted array is => \n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    return 0;
}