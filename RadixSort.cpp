#include<iostream>
using namespace std;
int Max(int arr[],int n){
    int max=arr[0];
    for(int i=1;i<n;i++){
        if(max<arr[i])
            max=arr[i];
    }return max;
}
void radixSort(int arr[],int n,int m){


    

}


int main(){
    cout<<"Enter the size of the arrray => ";int n;cin>>n;cout<<endl;
    cout<<"Enter the elements of the array => \n";
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    radixSort(arr,0,n-1);

    cout<<"The sorted array is => \n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    return 0;
}