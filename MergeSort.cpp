#include<iostream>
using namespace std;

void mergeArray(int arr[],int first,int mid,int last){
    
    int n1=mid-first+1;int a[n1];
    int n2=last-(mid+1)+1;int b[n2];
    for(int i=0;i<n1;i++)
        a[i]=arr[first+i];
    for(int j=0;j<n1;j++)
        b[j]=arr[mid+1+j];
    int i=0,j=0,k=first;
    while(i<n1 && j<n2){
        if(a[i]<b[j]){
            arr[k]=a[i];
            k++;i++;
        }else{
            arr[k]=b[j];
            k++;j++;
        }
    }
    while(i<n1){
        arr[k]=a[i];
        k++,i++;
    }
    while(i<n1){
        arr[k]=b[j];
        k++,j++;
    }
}

void mergeSort(int arr[],int first,int last){
    if(first<last){
        int mid=(first+last)/2;
        mergeSort(arr,first,mid);
        mergeSort(arr,mid+1,last);
        mergeArray(arr,first,mid,last);
    }

}

int main(){
    cout<<"Enter the size of the arrray=> ";int n;cin>>n;cout<<endl;
    cout<<"Enter the elements of the array => \n";
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    mergeSort(arr,0,n-1);

    cout<<"The sorted array is => \n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    return 0;
}