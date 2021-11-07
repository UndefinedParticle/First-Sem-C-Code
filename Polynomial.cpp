#include<iostream>
using namespace std;
class Node{
    public:
    int coeff,power;
    Node *next;
};
void myPoly(Node *&head){
    
    cout<<"enter the degree of the polynomial => \n";int d;cin>>d;
    float a[d+1];
    for(int i=d;i>=0;i--){
        cout<<"Enter the coefficient of x^"<<i<<"  \n";cin>>a[i];
        Node *newNode=new Node();
        if(head==NULL){
            
            newNode->coeff=a[i];
            newNode->power=i;
            head=newNode;
            newNode->next=NULL;
        }else{
            newNode->coeff=a[i];
            newNode->power=i;
            Node *temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newNode;
        }cout<<"newNode is "<<&newNode<<endl;
        cout<<"coeff is "<<&newNode->coeff<<endl;
        
    }
}

void addPoly(Node *&poly1,Node *&poly2,Node *&poly)
{
    while (poly1!=NULL && poly2!=NULL){
        Node *newNode=new Node();
        if(poly==NULL){
            if (poly1->power > poly2->power) {
                newNode->power = poly1->power;
                newNode->coeff = poly1->coeff;
                poly1 = poly1->next;
            }else if (poly1->power < poly2->power) {
                newNode->power = poly2->power;
                newNode->coeff = poly2->coeff;
                poly2 = poly2->next;
            }else {
                newNode->power = poly1->power;
                newNode->coeff = poly1->coeff + poly2->coeff;
                poly1 = poly1->next;
                poly2 = poly2->next;
            }
            poly=newNode;
            newNode->next = NULL;
        }else{
            if (poly1->power > poly2->power) {
                newNode->power = poly1->power;
                newNode->coeff = poly1->coeff;
                poly1 = poly1->next;
            }else if (poly1->power < poly2->power) {
                newNode->power = poly2->power;
                newNode->coeff = poly2->coeff;
                poly2 = poly2->next;
            }else {
                newNode->power = poly1->power;
                newNode->coeff = poly1->coeff + poly2->coeff;
                poly1 = poly1->next;
                poly2 = poly2->next;
            }
        
            Node *temp=poly;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newNode; 
        }

    }
}

void show(Node *head){
    while(head!=NULL){
        cout<<head->coeff<<"x^"<<head->power;
        if (head->next != NULL)
            cout<<" + ";
        head=head->next;
    }cout<<endl;
}
int main(){
    cout<<"Number of Polynomials => ";int n;cin>>n;
    Node *Poly[n],*sum[n];
    for(int i=0;i<n;i++){
        Poly[i]=NULL;
        sum[i]=NULL;
    }
    for(int i=0;i<n;i++){
        cout<<"  Polynomial  "<<i+1<<"\n ------------------ \n";
        myPoly(Poly[i]);
        cout<<"The Polynomial Equation is => \n";
        show(Poly[i]);cout<<endl;
    }
    Node *temp=Poly[0];
    cout<<"The Equaton after Addition  is => \n";
    for(int i=0;i<n-1;i++){
        addPoly(temp,Poly[i+1],sum[i]);
        temp=sum[i];
    }
    show(sum[n-2]);cout<<endl;

    return 0;
}