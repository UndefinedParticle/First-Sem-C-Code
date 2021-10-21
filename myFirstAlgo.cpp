#include<iostream>
using namespace std;
int n,pos,a[30];

    void create(){
        cout<<"Enter how many elements you want to insert in the array  => \n";
        cin>>n;  
        cout<<"Enter the  Values of the array  => \n";
        for(int i=0;i<n;i++)
            cin>>a[i];

    }
    void display(){
        cout<<"The Given array is => \n";
        for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
            
        }
    }
    void insert(){
        cout<<"\n Enter the position where you want to insert the value => \n";
        cin>>pos;
        pos=pos-1;
        for(int i=n-1;i>=pos;i--){
            a[i+1]=a[i];
        }
        cout<<"Enter whaat value you want to insert => \n";
        int m; cin>>m;
        a[pos]=m;
        n=n+1;
    }
    void del(){
        cout<<"\n Enter the position from where you want to delete the value => \n";
        cin>>pos;
        pos=pos-1;
        for(int i=pos;i<n-1;i++){
            a[i]=a[i+1];
        }
        n=n-1;

    }


int main(){
        create();
        display();
        int mySize =sizeof(a) / sizeof(a[12]);
        cout<<endl;
        cout<<mySize;
        int num;
        int l=1;
        cout<<endl;cout<<endl;
        while(l==1){
            cout<<"\n ------ MENU ------ \n 1.insert \n 2.delete \n 3.exit \n";
            cout<<"Enter your choice => \n";
            cin>>num;
            switch(num){
                case 1:
                    insert();display();
                    break;
                case 2:
                    del();display();
                    break;
                default:
                    cout<<"Invalid Input";
            }
            cout<<"\n To run this code again press 1 otherwise 0 \n";
            cin>>l;


        }

        return 0;

}