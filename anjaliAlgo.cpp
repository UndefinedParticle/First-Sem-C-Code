#include<stdio.h>
#include <stdlib.h>
int main()
{
    int n,i,j,res;
     printf("enter the value of dimension of matrix\n"); //n is the order of the matrix
    scanf("%d",&n);
    float matrix[n][n],d[n][1],alpha[n],beta[n],x[n];
   
    printf("enter the elements of matrix\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
scanf("%f",&matrix[i][j]);
    }
    printf("--------------------\n");
    printf("checking whether the matrix is diagonally dominant or not------\n");
 for(i=1;i<=n;i++)
    {
        int sum=0;
        for(j=1;j<=n;j++)
        {
             sum+=abs(matrix[i][j]);
        }
        sum-=abs(matrix[i][i]);
         if (abs(matrix[i][i]) < sum)
         {
             res=0;
             break;

         }
         else
         {
             res=1;
         }
    
    }
    if(res==0)
    {
    printf("invalid matrix-----> try again!!\n");
    exit(0);
    }
    else
    printf("valid matrix\n");
    printf("enter the values of d's\n");
    for(i=1;i<=n;i++)
    {
scanf("%f",&d[i][1]);
    }
   
   
			  
		

for(i=1;i<=n;i++)
{
    if(i==1)
    {
        alpha[i]=matrix[i][i];
    
    }
    else
    {
        alpha[i]=matrix[i][i]-((matrix[i][i-1]*matrix[i-1][i])/alpha[i-1]);
    }
}
printf("----------------------\n");
printf("the value of alpha i's is-------\n");
for(i=1;i<=n;i++)
{
    printf("%0.3f\n",alpha[i]);
}
for(i=1;i<=n;i++)
{
    if(i==1)
    {
        beta[i]=d[i][1]/matrix[i][i];
    
    }
    else
    {
        beta[i]=(d[i][1]-(matrix[i][i-1]*beta[i-1]))/alpha[i];
    }
}
printf("----------------------\n");
printf("the value of beta i's is-------\n");
for(i=1;i<=n;i++)
{
    printf("%0.3f\n",beta[i]);
}
for(i=n;i>=1;i--)
{
    if(i==n)
    {
        x[i]=beta[i];
    }
    else{
        x[i]=beta[i]-((matrix[i][i+1]*x[i+1])/alpha[i]);
    }
}
printf("---------------------\n");
printf("solution is -------\n");
for(i=1;i<=n;i++)
{
    printf("%0.3f\n",x[i]);
}
    return 0;
}