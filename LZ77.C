#include<stdio.h>
#include<conio.h>
#include<string.h>
int i=0,j,k=0,len,tokenint[30][2],length,m_length,m_index,a;
char input[500],tokenc[30][30];
int match(int x,int y);
void main()
{
	clrscr();
	printf("Enter String :");
	gets(input);
	len=strlen(input);
	while(i<len)
	{       m_length=0;
		m_index=0;
		for(j=0;j<i;j++)
		{
			if(input[i]==input[j])
			{
				length=match(j,i);
				if(m_length<length)
			       {	m_length=length; m_index=j;}
			}
		}
		tokenint[k][1]=m_length;
		tokenint[k][0]=m_index;
		for(a=0;a<m_length+1;a++)
			tokenc[k][a]=input[a+j];
		k++;
		i=(i+m_length+1);
	}
	printf("index\t length\t string\n");
	for(i=0;i<k;i++)
	{
		printf("%d     \t%d \t",tokenint[i][0],tokenint[i][1]);
		for(j=0;j<(tokenint[i][1]+1);j++)
		printf("%c",tokenc[i][j]);
		printf("\n");
	}
	getch();
}
int match(int x,int y)
{
	int count=0;
	while(input[x]==input[y])
	{count++;x++;y++;}

	return(count);
}