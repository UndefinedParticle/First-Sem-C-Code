#include<iostream>
#include<cmath>
using namespace std;

void swap(int a[],int i,int j){
    int temp=a[i];
    a[i]=a[j];
    a[j]=temp;
}

int partition(int arr[],int first,int last){
    int pivot=arr[last];
    int i=first-1,j;
    for(j=first;j<=last-1;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr,i,j);
        }
    }
    swap(arr,i+1,last);

    return i+1;
}

void quickSort(int arr[],int first,int last){
    if(first<last){
        int pi=partition(arr,first,last);
        quickSort(arr,first,pi-1);
        quickSort(arr,pi+1,last);
    }

}

int main(){
    cout<<"Enter the size of the arrray=> ";int n;cin>>n;cout<<endl;
    cout<<"Enter the elements of the array => \n";
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    quickSort(arr,0,n-1);
    cout<<"The sorted array is => \n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    return 0;
}