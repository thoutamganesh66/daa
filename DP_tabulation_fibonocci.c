// fibonocci using DP-Tabulation

#include<stdio.h>

int a[100];

int fib(int n)
{
	int i;
	if(n<0)
		return -1;
	a[0]=0,a[1]=1;
	for(i=2;i<=n;i++)
	{
		a[i]=a[i-2]+a[i-1];
	}
	return a[n];
}

int main()
{
	int n;
	printf("Enter n:\n");
	scanf("%d",&n);
	printf("Fib(%d)=%d\n",n,fib(n) );
}