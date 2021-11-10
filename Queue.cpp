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
    void deQueue(){
        if(front==-1 || front>rear){
            cout<<"Underflow \n";
            return;
        }front++;
    }
    int top(){
        if(front==-1 || front>rear){
            cout<<"No elements are there \n";
            return -1;
        }return arr[front];
    }
    void isEmpty(){
        if(front==-1 || front>rear){
            cout<<"true"<<endl;
        }else
            cout<<"false"<<endl;
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

    queue que;
    que.enQueue(1);
    que.enQueue(2);
    que.enQueue(3);
    que.enQueue(4);
    que.printQ();
    cout<<que.top()<<endl;
    que.deQueue();
    cout<<que.top()<<endl;
    que.isEmpty();
    //cout<<que.isEmpty()<<endl;
    return 0;
}