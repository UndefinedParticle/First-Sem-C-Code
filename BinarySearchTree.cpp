#include<iostream>
using namespace std;
int count=0,i=0;
int a[20];
class Node{
    public:
        int data;
        Node* left;
        Node* right;
};
Node* addElement(Node* &root,int newData){
    Node* newNode=new Node();
    newNode->data=newData;//count++;
    if(root==NULL){
        root=newNode;
        newNode->left=NULL;
        newNode->right=NULL;
        count++;
        return newNode;
    }
    Node* temp=root;
    if(temp->data>=newData){
        temp->left=addElement(temp->left,newData);
    }else{
        temp->right=addElement(temp->right,newData);
    }//count++;
    return root;
}
int size(Node* root){
    return count;
}
Node* binarySearch(Node* root,int x){
    if(root==NULL) return NULL;
    if(root->data==x){
        //cout<<"Element is found\n";
        return root;
    }else if(root->data>=x){
        return binarySearch(root->left,x);
    }else if(root->data<x){
        return binarySearch(root->right,x);
    }else{
        //cout<<"Element is not found\n";
        return root;
    }
    
}
Node* minValueNode(Node* node){
    Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
 
    return current;
}

Node* deleteNode(Node* &root,int x){
    if (root == NULL)
        return root;
    if (x < root->data)
        root->left = deleteNode(root->left, x);
    else if (x > root->data)
        root->right = deleteNode(root->right, x);
    else{
        if(root->left==NULL&&root->right==NULL){
            return NULL;
        }else if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        }else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
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
    cout<<root->data<<" ";a[i]=root->data;i++;
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
    addElement(root,58);
    addElement(root,53);
    addElement(root,78);
    addElement(root,35);
    addElement(root,55);
    addElement(root,72);
    addElement(root,88);
    addElement(root,61);
    addElement(root,75);
    cout<<"Order of the tree is "<<size(root)<<endl;
    cout<<"PreOrder traversal is => \n";
    preOrder(root);cout<<endl;
    cout<<"InOrder traversal is => \n";
    inOrder(root);cout<<endl;
    cout<<"PostOrder traversal is => \n";
    postOrder(root);cout<<endl;
    //binarySearch(root,100);
    deleteNode(root,14);
    cout<<"InOrder traversal is => \n";
    inOrder(root);cout<<endl;
    return 0;
}