#include<stdio.h>
#include<conio.h>
#include<string.h>
int i=0,j,k=0,len,tokenint[30],length,f1,f2,phrase,z,a,m_length;
char input[500],tokenc[30][30],s[30];

void main()
{
	clrscr();
	printf("Enter String :");
	gets(input);
	len=strlen(input);
	while(i<len)
	{       s[0]=input[i];
		length=1;
		phrase=0;
		m_length=0;
		for(z=0;z<k;z++)
		{
			for(j=0;j<k;j++)
			{       f2=1;
				for(a=0;a<length;a++)
				{
				     if(s[a]!=tokenc[j][a])
					     {
						f2=0;
						break;
					     }
				}
				if(f2 && m_length<length)
				{
					m_length=length;
					phrase=(j+1);
				}
			}
			length++;
			s[length-1]=input[i+length-1];
		}
		tokenint[k]=phrase;
		printf("%d     ",tokenint[k]);
		for(a=0;a<m_length+1;a++)
			{tokenc[k][a]=s[a];printf("%c",s[a]);}
		printf("\n");
		i=i+m_length+1;k++;
	}
	getch();
}