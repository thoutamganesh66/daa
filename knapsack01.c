#include<stdio.h>

int max(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}

int knapSack(int n,int wt[],int val[],int W)
{
	if(n==0 || W<=0)
		return 0;
	else
	{
		if((W-wt[n-1])>=0)
			return max((val[n-1]+knapSack(n-1,wt,val,W-wt[n-1])),knapSack(n-1,wt,val,W));
		else
			return knapSack(n-1,wt,val,W);
	}
}

int main()
{
	int n,i,W;
	printf("Enter n:\n");
	scanf("%d",&n);
	int wt[n],val[n];
	printf("Enter weights:\n");
	for(i=0;i<n;i++)
		scanf("%d",&wt[i]);
	printf("Enter values:\n");
	for(i=0;i<n;i++)
		scanf("%d",&val[i]);
	printf("Enter maximum weight of knapsack:\n");
	scanf("%d",&W);
	printf("Ans=%d\n", knapSack(n,wt,val,W));
}
