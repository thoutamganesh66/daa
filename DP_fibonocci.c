
// fib using dp - memorization
#include<stdio.h>

int a[100];

int fib(int n)
{
	if((n==0)||(n==1))
	{
		a[n]=n;
		return n;
	}
	else
	{
		if(a[n]==-1)
		{
			a[n]=fib(n-1)+fib(n-2);
			return a[n];
		}
		return a[n];
	}
}

int main()
{
	int n,i;
	printf("Enter n value:\n");
	scanf("%d",&n);
	for(i=0;i<=n;i++)
	{
		a[i]=-1;
	}
	printf("Fib(%d)=%d\n",n,fib(n) );
}
