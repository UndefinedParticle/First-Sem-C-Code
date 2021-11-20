#include<iostream>
using namespace std;
int adj[20][20],queue[20],rear=-1,front=-1,maxx=20,visited[20];
void enqueue(int v)
{
    if((front ==0 && rear==maxx-1)||(front ==rear+1))
    {
        cout<<"OVERFLOW"<<endl;
        return;
    }
    else if(front==-1)
    {
        front =0;
        rear=0;
    }
    else if(rear==maxx-1)
    {
        rear=0;
    }
    else
    {
        rear=rear+1;
    }

    queue[rear]=v;
}
int dequeue()
{int item;
    if(front==-1)
    {
        cout<<"underflow"<<endl;
        return -1;
    }
   item=queue[front];
     if(front ==rear)
    {
        front= -1;
        rear=-1;
    }
    else if(front==maxx-1)
    {
        front =0;
    }
    else
    {
        front+=1;

    }
    return item;
}
void bfs(int v,int n)
{
    for(int i=0;i<n;i++)
    {
if((adj[v][i]==1)&&(visited[i]!=1))
{
enqueue(i);
visited[i]=1;

}
    }
cout<<dequeue()<<"\t";
    if(front!=-1)
{
bfs(queue[front],n);
}
}

    

int main()
{int n,i,j;
cout<<"ENTER THE NO. OF NODES :"<<endl;
cin>>n;

cout<<"ENTER THE ADJACENCY MATRIX :"<<endl;
for(i=0;i<n;i++)
{
    for(j=0;j<n;j++)
    {
        cin>>adj[i][j];
    }
}
for(j=0;j<n;j++)
    {
      visited[n]=0;
    }
cout<<"ENTER YOUR STARTING NODE"<<endl;
int v;cin>>v;
enqueue(v);
visited[v]=1;
bfs(v,n);

    return 0;
    
    
     }