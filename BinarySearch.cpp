#include<iostream>
using namespace std;
int binarySearch(int a[],int n, int x){
    int start=0,end=n-1,mid;
    while(start<=end){
        mid=(start+end)/2;
        if(x==a[mid])
            return 1;
        if(x<a[mid])
            end=mid-1;
        else
            start=mid+1;
    }
    return -1;
}
int main(){
    int n,x;
    cout<<"Enter size of the array => \n";
    cin>>n;int a[n];
    cout<<"Give the array elements => \n";
    for(int i=0;i<n;i++)
        cin>>a[i];
    int temp;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1;j++){
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    int l=1;
    while(l==1){
        cout<<"Enter Your element that you want to search => \n";
        cin>>x;
        int ans=binarySearch(a,n,x);
        if(ans==-1){
            cout<<"Number is not found \n";
        }else
            cout<<"The number is present "<<endl;
        cout<<"If you want to search again press 1 \n";
        cin>>l;
    }
    return 0;
}