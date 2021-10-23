#include<stdio.h>

int matrix[25][25],cost=0,cities,visited[10];

int tsp(int c)
{
	int i,nearest_city=999;
	int minimum=999,temp;
	for(i=0;i<cities;i++)
	{
		if((matrix[c][i]!=0) && (visited[i]==0))
		{
			if(matrix[c][i]<minimum)
			{
				minimum=matrix[c][i];
			}
			nearest_city=i;
		}
	}
	if(minimum!=999)
	{
		cost = cost+minimum;
	}
	return nearest_city;
}

void minimum_cost(int city)
{
	int nearest_city;
	visited[city]=1;
	printf("%d", city+1);
	nearest_city = tsp(city);
	if(nearest_city == 999)
 {
 nearest_city = 0;
 printf("%d", nearest_city + 1);
 cost = cost + matrix[city][nearest_city];
 return;
 }
	minimum_cost(nearest_city);
}

int main()
{
	int i,j;
	printf("Enter no.of cities\n");
	scanf("%d",&cities);
	printf("Enter cost matrix \n");
	for(i=0;i<cities;i++)
	{
		printf("Enter row %d costs\n",i);
		for(j=0;j<cities;j++)
		{
			scanf("%d",&matrix[i][j]);
		}
		visited[i]=0;
	}
	printf("Entered cost matrix is:\n");
	for(i=0;i<cities;i++)
	{
		printf("\n");
		for(j=0;j<cities;j++)
		{
			printf("%d ", matrix[i][j]);
		}
	}
	printf("The minimum path is:\n");
	minimum_cost(0);
	printf("It's minimum cost is : %d\n",cost );
}
