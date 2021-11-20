#include<iostream>
#include<cmath>
using namespace std;
int count=1;
class stack{
    public:
    char data;
    stack* next;
};

stack* top=NULL;

void push(stack* &head,char newData){
    stack* newNode=new stack();
    newNode->data=newData;
    if(top==NULL){
        top=newNode;
        head=newNode;
        return;
    }
    newNode->next=head;
    head=newNode;
    top=head;
    count++;
}

void pop(stack* &head){
    top=head->next;
    head=head->next;
}

bool isEmpty(stack* &head){
    return top==NULL;
}

char peek(stack* &head){
    if(top==NULL){
        cout<<"UnderFlow\n";
        return -1;
    }return top->data;
}

int size(stack* &head){
    return count;
}

void show(stack* head){
    char a[count];
    int i=0;
    if(top==NULL)
        cout<<"UnderFlow\n";

    cout<<"[ ";
    while(head!=NULL){
        a[i]=head->data;i++;
        //cout<<head->data<<" ";
        head=head->next;
    }
    for(int j=count-1;j>=0;j--){
        cout<<a[j]<<" ";
    }
    
    cout<<"]";cout<<endl;
}

int precedence(char ch){
    if(ch=='^')
        return 3;
    if(ch=='*' || ch=='/')
        return 2;
    if(ch=='+' || ch=='-')
        return 1;
    return -1;
}

string PolishExp(string s){
    s=s+')';
    string P="";
    stack* head=NULL;
    push(head,'(');
    for(int i=0;i<s.length();i++){
        if(s[i]>='a' && s[i]<='z' || s[i]>='A' && s[i]<='Z' || s[i]>='0' && s[i]<='9'){
            P=P+s[i];
        }else if(s[i]=='('){
            push(head,'(');
        }else if((s[i]=='+' || s[i]=='-' || s[i]=='/' || s[i]=='*' || s[i]=='^') && precedence(peek(head))>=precedence(s[i])){
            P=P+peek(head);
            pop(head);
            push(head,s[i]);
        }else if((s[i]=='+' || s[i]=='-' || s[i]=='/' || s[i]=='*' || s[i]=='^') && precedence(s[i])>precedence(peek(head))){
            push(head,s[i]);
        }
        else if(s[i]==')'){
            while(peek(head)!='('){
                if(peek(head)!='('){
                    P=P+peek(head);
                    pop(head);
                }
                if(peek(head)=='('){
                   pop(head);
                   break;
                }
            }
        }
    }
    //cout<<"Postfix Expression is => "<<P<<endl;
    return P;
}


int main(){
    cout<<"Enter Your Infix Expression without giving any space => ";
    string Q;cin>>Q;cout<<endl;//(1+2)*3-(4-5)*(6+7)
    cout<<"Postfix Expression is => "<<PolishExp(Q)<<endl;//12+3*45-67+*-
    return 0;
}