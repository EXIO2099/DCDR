#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
void main()
{
   clrscr();
   int bb,c,p,s,q,r,n,m=5,i,j,k,bbb;
   char uc[100],a[10],cc[10];
   float b;
   printf("Enter n:");
   scanf("%d",&n);
  for(j=0;j<=n;j++)
  {
    q=j/m;
    r=j%m;

    b=log10(m)/log10(2);
//    printf("\nQ=%d\nR=%d\nb=%f",q,r,b);
    s=floor(b);
    p=((pow(2,s))-m);

    if(p<0)
    {
       s++;
       b=s;
       p=((pow(2,s))-m);
 //      printf("\nP=%d\nB=%d\n\n",p,s);
     }
      bbb=s-1;
    for(i=0;i<q;i++)
    {
	uc[i]='1';
    }
    uc[i]='0';
    uc[++i]=NULL;

    printf("Golomb Code=%s",uc);

    if(r>=p)
    {
       bb=r+b;

      for(c=b-1;c>=0;c--)
      {
      k	=bb >> c;
      if(k & 1)
	printf("1");
      else
      printf("0");
      }
    }
    else
    {
      for(c=s-2;c>=0;c--)
      {
      k	= r >> c;
      if(k & 1)
	printf("1");
      else
      printf("0");
      }
    }
    printf("\n");
  }

getch();
}