#include<stdio.h>
int main()
{
	int a[50];
	int i,size,j,round,temp;
//	int lb=0,ub=size-1,mid,elem;
	printf("enter the size of the list : ");
	scanf("%d",&size);
	printf("enter the list of element \n");
	for(i=0;i<=size-1;i++)
	{
		scanf("%d",&a[i]);
	}
	
	for(round=1;round<size;round++)
	{
		for(j=0;j<=size-round-1;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	//printing the element in increseing order 
	printf("printing the element in increasing order\n");
	for(i=0;i<size;i++)
	{
		printf("%d\t",a[i]);
	}
	//searching the element 
	printf("\n input the number which you want to find :");
	
	int lb=0,ub=size-1,mid,elem;
	scanf("%d",&elem);
	printf("check");
	
	while(ub>=lb)
	{
		mid=(lb+ub)/2;
		if(a[mid]==elem)
		{
			printf("%d is in the list at position of %d",elem,mid+1);
		}
		else 
		{
			if(a[mid]>elem)
			{
		    	ub=mid-1;
			    mid=(lb+ub)/2;
		    }
		    else if(a[mid]<elem)
		    {
			    lb=mid+1;
		    	mid=(lb+ub)/2;
	    	}
		}	
	}
}