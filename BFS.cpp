#include<iostream>
using namespace std;
#define max 100
class queue{
    int* arr;
    int front,rear;
    public:
    queue(){
        arr=new int[max];
        front=-1;
        rear=-1;
    }

    void enQueue(int data){
        if(rear==max-1){
            cout<<"Overflow \n";
            return;
        }rear++;
        arr[rear]=data;
        if(front==-1) front++;
    }
    int deQueue(){
        int a=-1;
        if(front==-1 || front>rear){
            cout<<"Underflow \n";
            return -1;
        }
        a=front;front++;
        return a;
    }
    int top(){
        if(front==-1 || front>rear){
            cout<<"No elements are there \n";
            return -1;
        }return arr[front];
    }
    /*void isEmpty(){
        if(front==-1 || front>rear){
            cout<<"true"<<endl;
        }else
            cout<<"false"<<endl;
    }*/

    int isEmpty(){
        if(front==-1 || front>rear){
            return 1;
        }return 0;
    }
    void printQ(){
        if(front==-1 || front>rear){
            cout<<"No elements are there \n";
        }else{
            int n=rear-front+1;
            cout<<"[ ";
            for(int i=0;i<n;i++){
                cout<<arr[i]<<" ";
            }cout<<"]\n";
        }
    }
};

int main(){
    queue q;
    cout<<"Enter number of vertices => ";int n;cin>>n;cout<<endl;
    int visited[n];
    cout<<"From which vertices you want to start ? ";int p;cin>>p;cout<<endl;

    for(int i=0;i<n;i++){
        visited[i]=0;
    }int a[n][n];
    cout<<"Enter the values of the adjancy matrix => ";cout<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }cout<<"Ans is => \n";
    cout<<p<<" ";
    visited[0]=1;
    q.enQueue(p);
    while(!q.isEmpty()){
        int node=q.deQueue();
        for(int j=0;j<n;j++){
            if(a[node][j]==1 && visited[j]==0){
                cout<<j<<" ";
                visited[j]=1;
                q.enQueue(j);
            }
        }

    }

    return 0;
}