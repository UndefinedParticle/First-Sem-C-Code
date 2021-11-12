#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node* left;
        Node* right;
};
Node* addElement(Node* &root,int newData){
    Node* newNode=new Node();
    newNode->data=newData;
    if(root==NULL){
        root=newNode;
        newNode->left=NULL;
        newNode->right=NULL;
        return newNode;
    }
    Node* temp=root;
    if(temp->data>=newData){
        temp->left=addElement(temp->left,newData);
    }else{
        temp->right=addElement(temp->right,newData);
    }
    return root;
}
Node* binarySearch(Node* root,int x){
    if(root==NULL) return NULL;
    if(root->data==x){
        cout<<"Element is found\n";
        return root;
    }else if(root->data>=x){
        return binarySearch(root->left,x);
    }else if(root->data<x){
        return binarySearch(root->right,x);
    }else{
        cout<<"Element is not found\n";
        return root;
    }
    
}


void preOrder(Node* root){
    if(root==NULL) return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
void inOrder(Node* root){
    if(root==NULL) return;
    inOrder(root->left);
    cout<<root->data<<" "; 
    inOrder(root->right);
}
void postOrder(Node* root){
    if(root==NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}


int main(){
    Node* root=NULL;
    addElement(root,8);
    addElement(root,10);
    addElement(root,3);
    addElement(root,1);
    addElement(root,6);
    addElement(root,14);
    addElement(root,7);
    cout<<"PreOrder traversal is => \n";
    preOrder(root);cout<<endl;
    cout<<"InOrder traversal is => \n";
    inOrder(root);cout<<endl;
    cout<<"PostOrder traversal is => \n";
    postOrder(root);cout<<endl;
    binarySearch(root,100);

    return 0;
}