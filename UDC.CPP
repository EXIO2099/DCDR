#include<iostream.h>
#include<string.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>

int n,i,j=0,m,x,flag=0,p=0,count=0;
char pre[10],s1[5][5],dan[5][5],temp[5];

class Unique
{
	public: void getInput();
	private: void check(int n, char pre[]);
	void getDangling(int p, int i, int x, char pre[]);
};

void Unique ::getInput()
{
	cout<<"\n\n\tNo of codewords(Max 5) : ";
	cin>>n;
	cout<<endl;
	for(i=0;i<n;i++)
	{
	  cout<<"\t\t";
	  cin>>s1[i];
	}
	strcpy(pre,s1[0]);
	check(n,pre);
}

void Unique :: check(int n, char pre[])
{
	x=0;while(x<n)
	{
	  if(strlen(pre) < strlen(s1[x]))
	  for (i=0,j=0;i<strlen(s1[x]);i++)

	  if(s1[x][i]==pre[j])
	  { j++;
	      if(j==strlen(pre))
		{
		   flag=1;
		   getDangling(0,i,x,pre);
		   }
		   else continue;
		   }
		     else break;
		      x++;
		      if(flag==1)
		       break;
		       }
		       }

void Unique::getDangling(int p, int i, int x, char pre[])
{
	int u,z,q,y; z=count;

	for(u=i+1,q=0;u<strlen(s1[x]);u++,q++)
	{
	   dan[z][q]=s1[x][u];
	}

	if(z!=0)
	{
	   for(u=0;u<z;u++)
	   {
	     if(!(strcmp(dan[z],dan[u])))
	     {
	       cout<<"\n\tUniquely Decodable Code Identified...";
	       getch();
	       exit(0);
	     }
	   }

	  for(u=0;u<n;u++)
	  {
	     for(int j=0;j<=z;j++)
	     if(!(strcmp(s1[u],dan[j])))
	     {
	       cout<<"\n\tNot Uniquely decodable code...";
	       getch();
	       exit(0);
	     }
	   }

		strcpy(pre,dan[z]);
		flag=0;
		count++;
		check(n,pre);
		}
	    else
	    {
	    strcpy(pre,dan[z]);
	    flag=0;
	    count++;
	    check(n,pre);
	    }
	    }

int main()
{
   clrscr();
   Unique u;
   cout<<"\n\t\t======= UNIQUELY DECODABLE CODE =======";
   u.getInput();
   getch();
   return 0;

}