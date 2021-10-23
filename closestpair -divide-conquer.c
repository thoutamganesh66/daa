#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct point{
	float x;
	float y;
};
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

float threeminimum(struct point p[],int left,int right){
	if((right-left)==2){
		return distance(p[left],p[left+1]);
	}
	float a,b,c;
	a=distance(p[left],p[left+1]);
	b=distance(p[left+1],p[left+2]);
	c=distance(p[left],p[left+2]);
	return minimum(a,minimum(b,c));
}

float mod(float a){
	if(a<0){
		return a*-1;
	}
	return a;
}
void sort(struct point point[],int left,int right,int decider){
	if((right-left)<=1){
		return ;
	}
	int pivot=left;
	int yellow=pivot+1;
	for(int green=pivot+1;green<right;green++){
		if(decider==0){
			if(point[green].x<point[pivot].x){
				swap(point,green,yellow);
				yellow++;
			}
		}
		else{
			if(point[green].y<point[pivot].y){
				swap(point,green,yellow);
				yellow++;
			}
		}
	}
	yellow--;
	swap(point,pivot,yellow);
	sort(point,left,pivot,decider);
	sort(point,pivot+1,right,decider);
}
float closestpair(struct point p[],int left, int right){
	if((right-left)<=3){
		return threeminimum(p,left,right);
	}
	int mid=(left+right)/2;
	float min_left,min_right,min,total_min;
	min_left=closestpair(p,left,mid);
	min_right=closestpair(p,mid,right);
	min=minimum(min_left,min_right);
	struct point strip[100];
	int strip_len=0;
	for(int i=left;i<right;i++){
		if(mod(p[i].x-p[mid].x)<=min){
			strip[strip_len]=p[i];
			strip_len++;
		}
	}
	sort(strip,0,strip_len,1);
	int k;
	for(int i=0;i<strip_len-1;i++){
		for(int j=i+1;j<strip_len;j++){
			if(mod(strip[i].y-strip[j].y)>min){
				break;
			}
			min=minimum(min,distance(strip[i],strip[j]));
		}
	}
	return min;
}
void main(){
	int n;
	float shortest_distance;
	printf("enter number of elements:");
	scanf("%d",&n);
	struct point p[n];
	for(int i=0;i<n;i++){
		printf("Enter the %d element x and y coordinate:",i);
		scanf("%f%f",&p[i].x,&p[i].y);
	}
	sort(p,0,n,0);
	shortest_distance=closestpair(p,0,n);
	printf("shortest distance=%f",shortest_distance);
}
