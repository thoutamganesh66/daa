#include<stdio.h>
#include<string.h>

int main()
{
	char s1[100],s2[100];
	printf("Enter string 1:\n");
	scanf("%s",&s1);
	printf("Enter string 2:\n");
	scanf("%s",&s2);
	int m = strlen(s1);
	int n = strlen(s2);
	int count=0, appearance = 0;
	int i,j,flag;
	for(i=0;i<m-n+1;i++)
	{
		flag=0;
		count=0;
		for(j=i;j<n+i;j++)
		{
			if(s1[j]==s2[j-i])
				count++;
		}
		if(count == n)
		{	
			flag = 1;
			appearance++;
		}
	}
	if(appearance == 0)
		printf("Not found\n");
	else
		printf("String found %d times\n",appearance );
}