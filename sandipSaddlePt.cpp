#include<stdio.h>
void saddle_point(int a[][30],int N)
{
	int max,k,i,j,p,min;
	for(i=0;i<N;i++)
	{
		p=0;
		min=a[i][0];
		for(j=0;j<N;j++)
		{
			if(min>a[i][j])
			{
				min=a[i][j];
				p=j;
				
			}
		}
		max=a[i][p];
		for(k=0;k<N;k++)
		{
			if(max<a[k][p])
			{
				max=a[k][p];
				
			}
	    }
		if(max==min)
		{
			printf("%d is saddle point",max);
		}
		
	}
	//if(max==min)
	    //printf("%d is saddle point",max);
}
int main()
{
	int a[30][30];
	int i,j,N;
	printf("enter the matrix size : ");
	scanf("%d",&N);
	printf("enter the matrix element :\n");
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			scanf("%d",&a[i][j]);
		}
		printf("\n");
	}
	printf("writting all element in matrix form :\n");
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			printf("%d \t",a[i][j]);
			
		}
		printf("\n");
	}
	saddle_point(a,N);
}