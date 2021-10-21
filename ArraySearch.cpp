#include<iostream>
using namespace std;
class myClass{
    public:
        int search(int arr[],int n,int x){
            for(int i=0;i<n;i++){
	        if(arr[i]==x)
	            return i+1; 
	        }return -1;
        }
};
int main(){
    int n,x;
    cout<<"Enter size of the array => \n";
    cin>>n;int a[n];
    cout<<"Give the array elements => \n";
    for(int i=0;i<n;i++)
        cin>>a[i];
    int l=1;
    while(l==1){
        cout<<"Enter Your element that you want to search => \n";
    cin>>x;
    myClass obj;
    int ans=obj.search(a,n,x);
    if(ans==-1){
        cout<<"Number is not found \n";
    }else
        cout<<"The position of the element "<<x<<" is "<<ans<<endl;
    cout<<"If you want to search again press 1 \n";
    cin>>l;

    }
    return 0;
}