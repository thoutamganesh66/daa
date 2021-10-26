#include<stdio.h>

int mcn(int a[],int i,int j)
{
	int min,k,temp;
	if(i>=j)
		return 0;
	min = 99999;
	for(k=i;k<j;k++)
	{
		temp = mcn(a,i,k)+mcn(a,k+1,j)+(a[i-1]*a[k]*a[j]);
		if(temp<min)
			min = temp;
	}
	return min;
}

int main()
{
	int n,i;
	printf("Enter n:\n");
	scanf("%d",&n);
	int a[n];
	printf("Enter array values:\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	int ans=mcn(a,1,n-1);
	printf("ans=%d",ans);
}
