#include<stdio.h>

int knapsack(int n,int wt[],int val[],int W)
{
	for(i=0;i<n+1;i++)
		k[0][i]=0;
	for(j=0;j<W+1;j++)
		k[j][0]=0;
	for(i=1;i<n+1;i++)
	{
		for(j=1;j<W+1;j++)
		{	if(wt[i-1]<=j)
				k[i][j]=max((val[i-1]+k[i-1][j-wt[i-1]]),k[i-1][j]);
			else
				k[i][j]=k[i-1][j];
		}
	}
}

int main()
{
	printf("Enter n:\n");
	scanf("%d",&n);
	printf("Enter weights:\n");
	for(i=0;i<n;i++)
		scanf("%d",&wt[i]);
	printf("Enter values\n");
	for(i=0;i<n;i++)
		scanf("%d",&val[i]);
	printf("Enter max weight:\n");
	scanf("%d",&W);
	printf("Ans=%d\n", knapsack(n,wt,val,W));
}