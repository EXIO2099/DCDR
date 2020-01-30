#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{
  clrscr();
  int dec=0,l,j,c,y[100],b[10],i,k=6,m=1,d[100],t[100],n,yb[100],ymax=0,ymin=0,x[100],t1,t2;
  yb[0]=0;
  printf("Enter range of sequence:");
  scanf("%d",&n);
  printf("Enter sequence::");
  for(i=0;i<n;i++)
  {
     scanf("%d",&y[i]);
  }
  clrscr();
  printf("-----------------------------------------------------------------\n Yi--->  ");
  for(i=0;i<n;i++)
  {
     printf("%d\t|\t",y[i]);
  }
  printf("\n-----------------------------------------------------------------\n Yb--->  %d\t|\t",0);
  for(i=1;i<n;i++)
  {
     yb[i]=y[i-1];
     printf("%d\t|\t",yb[i]);
  }
  printf("\n-----------------------------------------------------------------\n Di--->  ");
  for(i=0;i<n;i++)
  {
     d[i]=y[i]-yb[i];
     printf("%d\t|\t",d[i]);
  }
  for(i=0;i<n;i++)
  {
     if(ymax<y[i])
     {
       ymax=y[i];
     }
   }
   printf("\n-----------------------------------------------------------------\n Ti--->  ");
   for(i=0;i<n;i++)
   {
      t1=ymax-yb[i];
      t2=yb[i]-ymin;

      if(t1<t2)
      {
	t[i]=t1;
	printf("%d\t|\t",t[i]);
      }
      else
      {
	t[i]=t2;
	printf("%d\t|\t",t[i]);
      }
   }
   printf("\n-----------------------------------------------------------------\n Xi--->  ");
   for(i=0;i<n;i++)
   {
    if(0<=d[i] && d[i]<=t[i])
    {
     x[i]=2*d[i];
    }
    else if(-t[i]<=d[i] && d[i]<0)
    {
     x[i]=2*abs(d[i])-1;
    }
    else
    {
      x[i]=t[i]+abs(d[i]);
    }
    printf("%d\t|\t",x[i]);
  }
  printf("\n-----------------------------------------------------------------\n\nRice Code->");

for(l=0;l<n;l++)
{
  dec=0;
  for(c=k-1;x[l]>0;c--)
  {
    if(x[l]%2==0)
    {
       b[c]=0;
    }
    else
    {
	b[c]=1;
    }
    x[l]=x[l]/2;
  }

  for(j=c;j>=0;j--)
   {
     b[j]=0;
   }
 // printf("  ");
  for(j=k-m-1,i=0;j>=0;j--,i++)
    {
       dec=dec+(pow(2,i)*b[j]);
    }
   printf("%d",b[k-m]);
   for(i=0;i<dec;i++)
   {
     printf("1");
   }
   printf("0");
   printf("\t");
}
getch();
}

