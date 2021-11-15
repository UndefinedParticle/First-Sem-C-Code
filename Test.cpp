#include <iostream>
#include<string>
using namespace std;

int main() {
	// your code goes here
	int t,x;
	cin>>t;
	for(x=0;x<t;x++)
	{
	    string s;
	    cin>>s;
	    int n=s.length();
	    int a[n];
	    int i=0,j=0;
	    while(i<n)
	    {
	        a[j]=1;
	        if(s[i]==s[i+1])
	        {
	            a[j]=a[j]+1;
	            i++;
	        }
	        else
	        {
	            j++;
	        }
	    }
	    int k,odd=0,even=0;
	    for(k=0;k<=j;k++)
	    {
	        if(k%2==0)
	        {
	            if(a[k]>1)
	            {
	                even=even+2;
	            }
	            else
	            {
	                even++;
	            }
	        }
	        else
	        {
	            if(a[k]>1)
	            {
	                odd=odd+2;
	            }
	            else
	            {
	                odd++;
	            }
	        }
	    }
	    if(odd<=even)
	    {
	        cout<<odd<<"\n";
	    }
	    else
	    {
	        cout<<even<<"\n";
	    }
	}
	return 0;
}