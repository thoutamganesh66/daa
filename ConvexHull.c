#include<stdio.h>

struct point
{
	int x;
	int y;
};

int main()
{
	int i,j,k,u,v,a,b,c,d,e,f,n,flag1,flag2;
	struct point p[100];
	printf("Enter no.of points\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
  	{
  		printf("Enter point %d\n", i);
  		scanf("%d",&u);
  		scanf("%d",&v);
  		p[i].x=u;
  		p[i].y=v;
	}
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			flag1 =0;
			flag2 =0;
			a=p[i].y-p[j].y;
			b=p[j].x-p[i].x;
			c=((p[j].x)*p[i].y)-((p[i].x)*p[j].y);
			for(k=0;k<n;k++)
			{
				if(k!=i && k!=j)
				{
					d=a*p[k].x;
					e=b*p[k].y;
					f=d+e;
					if(f>=c)
						flag1=1;
					if(f<c)
						flag2=1;
				}
			}
			if((flag1==1 && flag2==0) || (flag1==0 && flag2==1))
				printf("%d,%d\n",i,j );
		}
	}
}
