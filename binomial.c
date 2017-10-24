//Implementation of Binomial Coeff. in C using Dynamic Programming

#include <stdio.h>

void main()
{
	int N,K,tmp;

	printf("Enter n and k :");
	scanf("%d %d",&N,&K);
	
	long int table[N+1][K+1];
	for(int i=0;i<=N;i++)
		for(int j=0;j<=K;j++)
			table[i][j]=-1;


	long int binomial(int n,int k)
	{
		if(k==n || k==0) 
			return 1;
		if(table[n][k]!=-1)
			return table[n][k];
		
		tmp=binomial(n-1,k-1)+binomial(n-1,k);
		table[n][k]=tmp;

		return tmp;
	}


	printf("Binomial coefficient (n,k) = B(%d,%d) = %ld\n",N,K,binomial(N,K));
}
