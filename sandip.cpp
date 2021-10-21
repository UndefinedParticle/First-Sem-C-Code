#include<iostream>
#include<stack>
using namespace std;
int main()
{
	stack<int> s;
    s.push(21);
    s.push(22);
    s.push(24);
    s.push(25);
    s.pop();
    
	cout<<s.top()<<endl;
    return 0;
	
}