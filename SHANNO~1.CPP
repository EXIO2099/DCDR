#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int n,tcount[15],m,c,flag,i,j,t,mat[10][10],diff[10][3],d,v1,v2,x,y,z,p,f;
char temp[15], str[50], a, st[15];
double cal[10][10];
class Shannon
{
	public:
		void getStr();
		void addStr();
		void sortStr(int );
		void divStr(int , int );
		int min(int , int );
		void store(int , int , int );
		void check(int , int , int );
		void ICT();
};
int Shannon :: min(int v1,int v2)
{
	return ((v1<=v2)?v1:v2);
}
void Shannon :: getStr()
{
	cout<<"\n\n\tInput Stream : ";
	cin>>str;
	n = strlen(str);
	m=0;
	for(i=0;i<n;i++)
	{
		a=str[i];
		c=0;
		for(j=0;j<n;j++)
			if(str[j]==a)
				c++;
		if(m==0)
			addStr();
		else
		{
			flag=0;
			for(t=0;t<strlen(temp);t++)
				if(temp[t]==a)
					flag=1;
			if(flag!=1)
				addStr();
		}
	}
	sortStr(m);
	for(i=0;i<m;i++)
		mat[i][0]=tcount[i];
	y=m;
	z=n;
	divStr(m,1);
	cout<<endl;
	for(i=0;i<y;i++)
	{
		cout<<temp[i];
		for(j=0;j<10;j++)
			if(mat[i][j]!=97)
				cout<<"   "<<mat[i][j]<<"   ";
		cout<<endl;
	}
	ICT();
}
void Shannon :: addStr()
{
	temp[m]=a;
	tcount[m]=c;
	m++;
}
void Shannon :: sortStr(int )
{
	for (i=0;i<m-1;i++)
		if(tcount[i+1]>tcount[i])
		{
			a=temp[i];
			j=tcount[i];
			temp[i]=temp[i+1];
			tcount[i]=tcount[i+1];
			temp[i+1]=a;
			tcount[i+1]=j;
			sortStr(i);
		}
	return;
}
void Shannon :: divStr(int s, int n)
{
	if(s==2)
	{
		store(1,s,n);
		return;
	}
	if(s%2==0)
		t=s/2;
	else
		t=(s-1)/2;
	c=0;
	for(i=0;i<t;i++)
		c+=tcount[i];
	diff[0][0]=c;
	c=0;
	for(i=t;i<s;i++)
		c+=tcount[i];
	diff[0][1]=c;
	if(t!=1)
	{
		c=0;
		for(i=0;i<t-1;i++)
			c+=tcount[i];
		diff[1][0]=c;
		c=0;
		for(i=t-1;i<s;i++)
			c+=tcount[i];
		diff[1][1]=c;
		c=0;
		for(i=0;i<t+1;i++)
			c+=tcount[i];
		diff[2][0]=c;
		c=0;
		for(i=t+1;i<s;i++)
			c+=tcount[i];
		diff[2][1]=c;
	}
	j=0;
	for(i=0;i<3;i++)
		diff[i][2]=diff[i][j]-diff[i][j+1];
	for(i=0;i<3;i++)
		if(diff[i][2]<0)
			diff[i][2]*=(-1);
	d=diff[0][2];
	for(i=1;i<3;i++)
		d=min(d,diff[i][2]);
	for(i=0;i<3;i++)
		if(diff[i][2]==d)
			break;
	for(j=0;j<3;j++);
		for(p=0;p<3;p++)
			diff[j][p]=0;
	if(i==0)
		check(t,n,s);
	else if(i==1)
		check(t-1,n,s);
	else if(i==2)
		check(t+1,n,s);
}
void Shannon :: check(int b, int n, int p)
{
	store(b,p,n);
	if(b==1)
	{
		n+=1;
		if(p>2)
			divStr(p-b,n);
		return;
	}
	else
	{
		n+=1;
		divStr(b,n);
		divStr(p-b,n);
	}

}
void Shannon :: store(int x,int s, int n)
{
	int w,z;
	for(j=0;j<m;j++)
		if(mat[j][n]<0)
		{       w=j;
			for(f=j;f<j+s;f++)
				if(f<x+j)
				{
					mat[f][n]=0;
					if(x==1)
					for(z=n+1;z<10;z++)
						mat[f][z]='a';
				}
				else
					mat[f][n]=1;
			break;
		}
	if(s==2)
		for(j=w;j<s+w;j++)
			for(f=n+1;f<10;f++)
				mat[j][f]='a';
}
void Shannon :: ICT()
{
	int sum=strlen(str);
	i=0;
	float y=0;
	p=0;
		for(j=0;j<m;j++)
		{
			double x =(double)tcount[j]/(double)sum;
			cal[j][i]=(-1)*log10(x)/log10(2);
			cal[j][i+1]=tcount[j]*cal[j][i];
			c=0;
			for(t=1;t<10;t++)
					if(mat[j][t]!=97)
						c+=1;
			cal[j][i+2]=c;
			cal[j][i+3]=tcount[j]*c;
			if(j==m-1)
			{
			   for(z=0;z<m;z++)
			   {
				y+=cal[z][i+1];
				p+=cal[z][i+3];
			   }
			}
		}
	cout<<"\nSymbol|\tCount |\tInfoCount |\tInfoBits |\tSFSize|\tSFBits";
	cout<<"\n===============================================================\n";
	for(i=0;i<m;i++)
	{
		cout<<temp[i]<<" |\t";
		cout<<tcount[i]<<" |\t";
		for(j=0;j<4;j++)
			cout<<cal[i][j]<<" |\t";
		cout<<endl;
	}
	cout<<"--------------------------------------------------------------------";
	cout<<"\n\t\t\t\t"<<y<<"\t\t"<<p;
}
void main(){
	clrscr();
	Shannon s;
	for(i=0;i<10;i++)
		for(j=0;j<10;j++)
			mat[i][j]=-1;
	cout<<"\n\t\t=======SHANNON-FANO ALGORITHM=======";
	s.getStr();
	getch();
}