#include<iostream>
#include<cmath>
#include<string>
using namespace std;

class stack{
    public:
    float data;
    stack* next;
};

stack* top=NULL;

void push(stack* &head,float newData){
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
}

void pop(stack* &head){
    top=head->next;
    head=head->next;
}

bool isEmpty(stack* &head){
    return top==NULL;
}

float peek(stack* &head){
    if(top==NULL){
        cout<<"UnderFlow\n";
        return -1;
    }return top->data;
}

void show(stack* head){
    if(top==NULL)
        cout<<"UnderFlow\n";

    cout<<"[ ";
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }cout<<"]";cout<<endl;
}
//!= '\n'
float PostEvaluation(string s){
    stack* head=NULL;
    for(float i=0;i<s.length();i++){
        /*if('0'<=s[i]&&s[i]<='9'){
            float num=s[i]-'0';
            push(head,num);
        }*/
    int num = 0, mult = 1, numOfDigits = 0, count = 0;

    if ((s[i] >= '0' && s[i] <= '9') || s[i] == ' ') {
      int j = i;
      while (s[j] != ' ') {
        count++;
        j++;
      }
      mult = pow(10, count - 1);
      while ((s[i] >= '0' && s[i] <= '9') && s[i] != ' ') {

        push(head,s[i] - '0');
        int temp = peek(head);
        pop(head);
        num = num + mult * temp;
        mult /= 10;
        i++;
        if (s[i] == ' ') {
          push(head,num);

          break;
        }
      }

    } else{
            float o1=peek(head);pop(head);
            float o2=peek(head);pop(head);
            switch(s[i]){
                case '+':
                    push(head,o2+o1);
                    break;
                case '-':
                    push(head,o2-o1);
                    break;
                case '/':
                    push(head,o2/o1);
                    break;
                case '*':
                    push(head,o2*o1);
                    break;
                case '^':
                    push(head,pow(o2,o1));
                    break;
            }
        }
    }
    
    return peek(head);

}


int main(){
    cout<<"Give Your Postfix Expression => ";
    string s;//cin>>s;
    getline(cin,s);
    cout<<endl;
    float ans=PostEvaluation(s);
    cout<<"Your Ans is => "<<ans<<endl;
    

    return 0;
}