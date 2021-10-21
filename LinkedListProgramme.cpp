#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
};

void add(Node* &head,int newData){
    Node* newNode=new Node();
    newNode->data=newData;
    if(head==NULL){
        head=newNode;
        return;
    }
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
}
void addFirst(Node* &head,int newData){
    Node* newNode=new Node();
    newNode->data=newData;
    newNode->next=head;
    head=newNode;
}

void insertAt(Node* &head,int loc){
    int newData;
    cout<<"Enter the element => \n";
    cin>>newData;
    Node *newNode=new Node();
    newNode->data=newData;
    Node *temp=head;
    for(int i=1;i<loc-1;i++){
    if(temp==NULL){
        cout<<"Can't Insert. \n";
        return;
    }
    temp=temp->next;
    }
    newNode->next=temp->next;
    temp->next=newNode;

}
void deleteFirst(Node* &head){
    head=head->next;
}

void deleteLast(Node* &head){
    Node *temp=head->next;
    Node *temp1=head;
    while(temp->next!=NULL){
       temp=temp->next;
       temp1=temp1->next;
    }
    temp1->next=NULL;

}

void deleteAt(Node* &head,int pos){
    Node *temp=head;
    Node *temp1=head;
    for(int i=1;i<pos-1;i++){
        temp=temp->next;
    }
    for(int i=1;i<pos;i++){
        temp1=temp1->next;
    }
    temp->next=temp1->next;
}



void show(Node* head){
    cout<<"[ ";
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }cout<<"]";cout<<endl;
}

int main(){
    Node *l=NULL; // l is the name of my list.
    
    add(l,1);
    add(l,2);
    add(l,3);
    add(l,4);
    show(l);
    addFirst(l,0);
    show(l);
    deleteFirst(l);
    show(l);
    insertAt(l,4);
    show(l);
    deleteAt(l,4);
    show(l);
    deleteLast(l);
    show(l);

    
    return 0;
}