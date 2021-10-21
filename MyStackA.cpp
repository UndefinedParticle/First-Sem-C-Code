#include<iostream>
using namespace std;
#define max 100
class stack{
    int arr[max];
    int top;
    public:
        stack(){
            top=-1;
        }
    void push(int x){
        if(top==max-1){
            cout<<"Overflow \n";
            return;
        }top++;
        arr[top]=x;
    }
    void pop(){
        if(top==-1){
            cout<<"Underflow \n";
            return;
        }top--;
    }
    int peek(){
        if(top==-1){
            cout<<"Stack is empty.\n";
            return 0;
        }return arr[top];
    }
    bool isEmpty(){
        return top==-1;
    } 


};



int main(){
    stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    cout<<"Top element is => "<<st.peek()<<endl;
    st.pop();
    cout<<"Top element is => "<<st.peek()<<endl;
    cout<<"Stack is empty or not => "<<st.isEmpty()<<endl;
    st.pop();
    st.pop();
    st.pop();
    cout<<"Top element is => "<<st.peek()<<endl;
    cout<<"Stack is empty or not => "<<st.isEmpty()<<endl;


    return 0;
}