#include<stdio.h>

int dp[100][100];

int mcnMemorisation(int a[],int i,int j)
{
	int min,temp,k;
	if(i>=j)
		return 0;
	if(dp[i][j]!=0)
		return dp[i][j];
	min = 99999;
	for(k=i;k<j;k++)
	{
		temp = mcnMemorisation(a,i,k)+mcnMemorisation(a,k+1,j)+(a[i-1]*a[k]*a[j]);
		if(temp<min)
			min = temp;
	}
	dp[i][j]=min;
	return min;
}

int main()
{
	int n,i;
	printf("Enter n:\n");
	scanf("%d",&n);
	printf("Enter values:\n");
	int a[n];
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	int ans=mcnMemorisation(a,1,n-1);
	printf("ans = %d\n",ans );
}
