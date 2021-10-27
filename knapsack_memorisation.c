#include<stdio.h>

int k[100][100];

int max(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}


int knapSack(int n,int wt[],int val[],int W)
{
	if(W<=0 || n==0)
		return 0;
	if(k[n][W]!=0)
		return k[n][W];
	else
	{
		if((W-wt[n-1])>=0)
			k[n][W]= max((val[n-1]+knapSack(n-1,wt,val,W-wt[n-1])),knapSack(n-1,wt,val,W));
		else
			k[n][W]=knapSack(n-1,wt,val,W);
	}
	 return k[n][W];
}

int main()
{
	int n,i,W,j;
	printf("Enter n:\n");
	scanf("%d",&n);
	int wt[n],val[n];
	printf("Enter weights:\n");
	for(i=0;i<n;i++)
		scanf("%d",&wt[i]);
	printf("Enter values:\n");
	for (int i = 0; i < n; i++)
    	scanf("%d",&val[i]);
    printf("Enter knapsack weight:\n");
    scanf("%d",&W);
    printf("Ans=%d\n", knapSack(n,wt,val,W));
}
