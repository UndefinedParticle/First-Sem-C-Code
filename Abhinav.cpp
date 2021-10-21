#include<stdio.h>


int main()
{
    int n;
    float CM[n][n],a[n],b[n];
    float c[n],d[n],x[n];
    float alpha[n],beta[n];

    printf("To find the solutions of a Tridiagonal system using Thomas Algorithm: ");
    printf("\n _________________________ \n");
    printf("\n Enter the value of dimension(n) of the square matrix:  ");
    scanf("%d",&n);


		printf("\n Enter the values of Coefficient matrix(row-wise): \n ");

		for(int i=0;i<n;i++)
            {
              for(int j=0;j<n;j++)
               {

                scanf("%f",&CM[i][j]);

			   }

		     }


		printf("\n Enter the values of d_i's: ");

		for(int i=0;i<n;i++) {

            scanf("%f",&d[i]);



		}


		for(int i=0;i<n;i++) {

			for(int j=0;j<n;j++) {

				if(i==j)

					b[i]= CM[i][j];

			}

		}

		for(int i=1;i<n;i++) {

			for(int j=0;j<n-1;j++) {

				if(j==i-1)

					a[i]=CM[i][j];

			}

		}

		for(int i=0;i<n-1;i++) {

			for(int j=1;j<n;j++) {

				if(j==i+1)

					c[i]= CM[i][j];

			}

		}

		alpha[0]=b[0];beta[0]=((d[0])/(b[0]));



		for( int i=1;i<n;i++) {

			alpha[i]=b[i]-((a[i]*c[i-1])/alpha[i-1]);

		}

		for( int i=1;i<n;i++) {

			beta[i]=((d[i]-(a[i]*beta[i-1]))/alpha[i]);

		}

		x[n-1]=beta[n-1];

		for(int i=n-2;i>=0;i--) {

			x[i]=beta[i]-((c[i]*x[i+1])/alpha[i]);

		}

		printf(" \n The Solution to our Tridiagonal System is : \n ");

		printf("[ ");

		for( int i=0;i<n-1;i++) {

			printf("%0.6f,",x[i]);

		}printf(" %f . ]",x[n-1]);

return 0;





}