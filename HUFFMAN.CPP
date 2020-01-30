#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int n,tcount[20],m,c,flag,i,j,t,mat[10][10],d,v1,v2,x,y,z,p,f,left[20],right[20],ct[10];
char temp[20], str[50], a, st[20];
double cal[10][10];
class Huffman
{
	public:
		void getStr();
	private:
		void addStr();
		void sortStr(int );
		void makeTree(int );
		int min(int , int );
		void getBits();
		void count(int index, int cnt, int flag);
		void ICT();
};
int Huffman :: min(int v1,int v2)
{
	return ((v1<=v2)?v1:v2);
}
void Huffman :: getStr()
{
	cout<<"\n\n\tInput : ";
	cin.getline(str,50);
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
		y=m;
	z=n;
	for(i=0;i<m;i++)
		mat[i][0]=tcount[i];
	for(i=0;i<2*m-1;i++)
		if(tcount[i]==0)
			tcount[i]=-1;
	strcpy(st,temp);
	makeTree(2*m-1);
		getBits();

}
void Huffman :: addStr()
{
	temp[m]=a;
	tcount[m]=c;
	m++;
}
void Huffman :: sortStr(int )
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
void Huffman :: makeTree(int s)
{
	int x=0,in = -1,mn,y=0;
	for(i=0;i<s;i++)
		if(tcount[i]!=0 && tcount[i]!=-1)
		{
			mn=tcount[i];
			break;
		}
	while(x<2)
	{
		for(i=0;i<s;i++)
		{
			if(in>-1 && i==in)
			{
				i++;
				if(i==y)
					i++;
				if(tcount[i]>0)
					mn=min(mn,tcount[i]);
			}
			else
			{
				if(i==y)
					i++;
				if(tcount[i]>0)
					mn=min(mn,tcount[i]);
			}
		}
		for(i=0;i<s;i++)
		{
			if(tcount[i]==mn)
			{
					if(i==in)
					i++;
				else
				{
					in=i;
					tcount[i]=0;
					goto l;
				}
			}
		}
		l:
		if(x==0)
		{
		      for(i=0;i<s;i++)
		      {
			if(tcount[i]==-1)
			{
				left[i]=in;
				tcount[i]=mn;
				y=i;
				mn=1000;
				break;
			}
		      }
		}
		else if (x==1)
		{
			for(i=0;i<s;i++)
				if(y!=0)
				{
					right[y]=in;
					break;
				}
			if(left[y]!=-1)
				tcount[y]=tcount[y]+mn;
		}
		x++;
	}
	y=0;
	for(i=0;i<s-1;i++)
		if(tcount[i]!=0)
		{
			y=1;
			break;
		}

	if(y==0)
		return;
	else
		makeTree(s);
}
void Huffman :: ICT()
{
	int sum=strlen(str);
	i=0;
	float y=0;
	p=0;
	for(j=0;j<m;j++)
	{

		double x =(double)ct[j]/(double)sum;
		cal[j][i]= (-1)*log10(x)/log10(2);
		cal[j][i+1]=mat[j][0]*cal[j][i];
		cal[j][i+2]=ct[j];
		cal[j][i+3]=ct[j]*mat[j][0];
	}
			for(z=0;z<m;z++)
			   {
				y+=cal[z][i+1];
				p+=cal[z][i+3];
			   }


		cout<<"\nSymbol|\tCount |\tInfoCount |\tInfoBits |\tSFSize|\tSFBits";

	cout<<"\n===============================================================\n";
	for(i=0;i<m;i++)
	{
		cout<<st[i]<<" |\t";
		cout<<mat[i][0]<<" |\t";
		for(j=0;j<4;j++)
			cout<<cal[i][j]<<" |\t";
		cout<<endl;
	}
	cout<<"--------------------------------------------------------------------";
	cout<<"\n\t\t\t\t"<<y<<"\t\t"<<p;


}


void Huffman :: getBits()
	{
	for(i=0;i<m;i++)
		ct[i]=1;
	for(i=m;i<2*m-1;i++)
		ct[i]=0;

	count(left[2*m-2],ct[2*m-2],0);
	count(right[2*m-2],ct[2*m-2],0);

	for(i=m;i<2*m-1;i++){
		if(left[i]<m)
			ct[left[i]]+=ct[i];
		if(right[i]<m)
			ct[right[i]]+=ct[i];}
	ICT();
}
void Huffman :: count(int index, int cnt,int flag)
{
	if(left[index]>=m){
		ct[index]++;
		ct[index]+=cnt;
		count(left[index],ct[index],1);
	}
	if(right[index]>=m){
		if(left[index]<m){ct[index]++; ct[index]+=cnt;}
		count(right[index],ct[index],1);
	}
	if(left[index]<m && right[index]<m)
		{ct[index]++; ct[index]+=cnt;}
}
int main()
{
	clrscr();
	Huffman h;
	cout<<"\n\t\t=======HUFFMAN ALGORITHM=======";	h.getStr();
	getch();
	return (0);
}