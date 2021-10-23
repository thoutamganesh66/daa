#include<stdio.h>

struct point
{
	int x;
	int y;
};

int main()
{
	struct point p[100];
	int n;
	printf("Enter n:\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter point %d\n", i);
		scanf("%d%d",&p[i].x,&p[i].y);
	}
	quicksort(p,0,n,0);
	short_distance=closest(p,0,n);
	printf("min distance=%f\n", short_distance);
}

float closest(struct point p[],int start,int end)
{
	if((end-start)<=3)
	{
		bruteForce(p,start,end);
	}
	else
	{
		mid=(start+end)/2;
		dl=closest(p,start,mid);
		dr=closest(p,mid,end);
		d=min(dl,dr);
		struct point strip[100];
		j=0;
		for(i=start;i<end;i++)
		{
			if(absdiff(p[i].x-p[mid].x)<=d)
			{
				strip[j]=p[i];
				j++;
			}
		}
		df=min(d,strmin(strip,0,j-1,d));
		return df;
	}
}
int strmin(struct point strip[],int start,int end,int d)
{
	quicksort(strip,start,end,1);
	for(i=start,i<end;i++)
	{
		for(j=i+1;j<end;j++)
		{
			if((strip[j].y-strip[i].y)<d)
			{
				ds=distance(strip[i],strip[j]);
				if(ds<d)
					d=ds;
			}
		}
	}
	return d;
}

void swap(struct point point[],int a,int b){
	struct point temp;
	temp=point[a];
	point[a]=point[b];
	point[b]=temp;
}

float distance(struct point a,struct point b){
	return sqrt((b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y));
}

float minimum(float a,float b){
	if(a<b){
		return a;
	}
	return b; 
}

float bruteForce(struct point p[],int left,int right){
	if((right-left)==2){
		return distance(p[left],p[left+1]);
	}
	float a,b,c;
	a=distance(p[left],p[left+1]);
	b=distance(p[left+1],p[left+2]);
	c=distance(p[left],p[left+2]);
	return minimum(a,minimum(b,c));
}

float absdiff(float a){
	if(a<0){
		return a*-1;
	}
	return a;
}

void quicksort(struct point p[],int start,int end,int decider)
{
	if((right-left)<=1)
	{
		return;
	}
	int pivot=left;
	int yellow = pivot+1;
	for(green=pivot+1;green<right;green++)
	{
		if(decider==0)
		{
			if(p[green].x<p[pivot].x)
			{
				swap(p,green,yellow);
				yellow++;
			}
		}
		else
		{
			if(p[green].y<p[pivot].y)
			{
				swap(p,green,yellow);
				yellow++;
			}
		}
	}
	yellow--;
	swap(p,pivot,yellow);
	quicksort(p,left,pivot,decider);
	quicksort(p,pivot+1,right,decider);
}