#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<string.h>

void main()
{
int a,b=0,c,d,cnt[50],i,len;
float prob[50],entropy=0;
char s[100],r[50];
clrscr();
printf("enter the string:");
gets(s);
len=strlen(s);
printf("Lengh of the string:%d\n",len);

for(a=0;s[a]!='\0';a++)
{
	if(a==0)
	{
		r[a]=s[a];
		r[a+1]='\0';
		continue;
	}
	for(i=0;i<a;i++)
	{
	  if(r[i]==s[a])
	  {
	    b=1;
	    break;
	  }
	}
	if(b==0)
	{
	  c=strlen(r);
	  r[c]=s[a];
	  r[c+1]='\0';
	}
}


c=strlen(r);
r[c]='\0';
b=0;
for(i=0;r[i]!='\0';i++)
{
	for(a=0;s[a]!='\0';a++)
	{
	  if(r[i]==s[a])
	  b++;
	}
	cnt[i]=b;
	b=0;
}
for(i=0;r[i]!='\0';i++)
{
	printf("value of %c is %d\n",r[i],cnt[i]);
	prob[i]=cnt[i]/len;
}
d=strlen(r);
for(i=0;i<d;i++)
{
	printf("prob of %c is %f\n",r[i],prob[i]);
}
for(i=0;i<d;i++)
{
entropy+=(prob[i]*log10(prob[i]))/log10(2);
}
entropy*=-1;
printf("entropy=%f\n",entropy);
getch();
}
