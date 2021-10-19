#include<stdio.h>
#include<math.h>

struct pair
{
	int x;
	int y;
};

int main()
{
	struct pair p[100];
	int n,i,j,a,b,mdist,ind1,ind2;
	double d;
	printf("Enter no.of points:\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter point %d\n", i);
		scanf("%d",&a);
		p[i].x=a;
		scanf("%d",&b);
		p[i].y=b;
	}
	mdist = 99999;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			d = sqrt(pow((p[i].x-p[j].x),2)+pow(p[i].y-p[j].y,2));
			if(d<mdist)
			{
				mdist = d;
				ind1 = i;
				ind2 = j;
			}
		}
	}
	printf("Closest pair is point %d,point %d\n",ind1,ind2);
}
