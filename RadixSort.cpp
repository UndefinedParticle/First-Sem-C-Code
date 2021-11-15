#include<iostream>
using namespace std;
int Max(int arr[],int n){
    int max=arr[0];
    for(int i=1;i<n;i++){
        if(max<arr[i])
            max=arr[i];
    }return max;
}
void countSort(int arr[], int n, int exp){
    int output[n]; // output array
    int i, count[10] = { 0 };
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}
void radixSort(int arr[],int n){
    int m = Max(arr, n);
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}
void printArray(int a[],int n){
    cout<<"[ ";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }cout<<"]\n";
}


int main(){
    cout<<"Enter the size of the arrray => ";int n;cin>>n;cout<<endl;
    cout<<"Enter the elements of the array => \n";
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    radixSort(arr,n);
    cout<<"The sorted array is => \n";
    printArray(arr,n);
    return 0;
}