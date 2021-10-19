#include<stdio.h>
#include<math.h>

struct cordinate
{
	int x;
	int y;
};

int main()
{
	struct cordinate p[100];
	double mdist,d;
	int point1,point2,a,b,n,i,j;
	printf("Enter no.of points:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter point %d\n",i+1);
		scanf("%d",&a);
		p[i].x = a;
		scanf("%d",&b);
		p[i].y = b;
	}
	for(i=0;i<n;i++)
	{
		mdist=9999;
		for(j=1;j<n;j++)
		{
			if(j!=i)				
			{
			d=sqrt(pow((p[i].x-p[j].x),2)+pow((p[i].y-p[j].y),2));
			if(d<mdist)
			{
				mdist=d;
				point1 = i;
				point2 = j;
			}
		}
		}
		printf("[p%d , p%d]",point1,point2);
	}
}
