#include<stdio.h>
#include<stdbool.h>
#include<math.h>
int main(){

		printf("Give the dimension of the Square matrix => \n");
		int n;
        scanf("%d",&n);
	    float coMatrix[n][n];
		printf("Please Give the values of the coefficient matrix => \n");
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
                scanf("%f",&coMatrix[i][j]);
			}
		} float x[n];float d[n];
		/*bool myBool=true;
		
    	for (int i = 0; i < n; i++){       
        int sum = 0;
        for (int j = 0; j < n; j++)            
            sum += abs(coMatrix[i][j]);       
 
        // removing the diagonal element.
        sum -= abs(coMatrix[i][i]);
 
        // checking if diagonal element is less
        // than sum of non-diagonal element.
        if (abs(coMatrix[i][i]) < sum)
            myBool=false;
        
    }
		
	
	if(myBool==true){*/	
		printf("Give the values of d_i's => ");
		for(int i=0;i<n;i++) {
            scanf("%f",&d[i]);
			
		}
		
		
		float alpha[n];float beta[n];
		float a[n];float b[n];float c[n];
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				if(i==j)
					b[i]=coMatrix[i][j];
			}
		}
		for(int i=1;i<n;i++) {
			for(int j=0;j<n-1;j++) {
				if(j==i-1)
					a[i]=coMatrix[i][j];
			}
		}
		for(int i=0;i<n-1;i++) {
			for(int j=1;j<n;j++) {
				if(j==i+1)
					c[i]=coMatrix[i][j];
			}
		}

		alpha[0]=b[0];beta[0]=((d[0])/(b[0]));
		
		for(int i=1;i<n;i++) {
			alpha[i]=b[i]-((a[i]*c[i-1])/alpha[i-1]);
		}
		for(int i=0;i<n;i++)
			printf("alpha-%d is %f \n",i+1,alpha[i]);


		for(int i=1;i<n;i++) {
			beta[i]=((d[i]-(a[i]*beta[i-1]))/alpha[i]);
		}
		for(int i=0;i<n;i++)
			printf("beta-%d is %f \n",i+1,beta[i]);
		x[n-1]=beta[n-1];
		for(int i=n-2;i>=0;i--) {
			x[i]=beta[i]-((c[i]*x[i+1])/alpha[i]);
		}
		printf(" The required solution is => \n");
		printf("[ ");
		for(int i=0;i<n;i++) {
			printf("%0.3f , ",x[i]);
		}printf(" ]\n");
	/*}else
		printf("\n Given matrix is not diagonally dominant \n");*/
	return 0;


}