#include<iostream>
using namespace std;
class node{
    public:
        int data;
        node* left;
        node* right;

    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};
void preOrder(node* root){
    if(root==NULL) return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
void inOrder(node* root){
    if(root==NULL) return;
    inOrder(root->left);
    cout<<root->data<<" "; 
    inOrder(root->right);
}
void postOrder(node* root){
    if(root==NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

int main(){
    node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->left->right->left=new node(6);
    root->left->right->right=new node(7);
    cout<<"PreOrder traversal is => \n";
    preOrder(root);cout<<endl;
    cout<<"InOrder traversal is => \n";
    inOrder(root);cout<<endl;
    cout<<"PostOrder traversal is => \n";
    postOrder(root);cout<<endl;
    


    return 0;
}