#include<iostream.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
int n,m,c,flag,i,j,t,diff[10][3],x;
char temp[15], str[50], a,st[15];
double tcount[15],low[15],high[15],com[15][3],decom[15][4],num,b[15];
class Arithmetic{
	public:
		void getStr();
	private:
		void addStr();
		void sortStr(int );
		void compress();
		void decompress();
		void print(int);
};
void Arithmetic :: getStr(){
	cout<<"\nInput : ";
	cin.getline(str,15);
	n=strlen(str);
	m=0;
	for(i=0;i<n;i++){
		a=str[i];c=0;
		for(j=0;j<n;j++){if(str[j]==a)c++;}
		if(m==0)addStr();
		else{
			flag=0;
			for(t=0;t<strlen(temp);t++)
				if(temp[t]==a)
					flag=1;
			if(flag!=1)
				addStr();
		}
	}
	sortStr(m);
	for(i=0;i<m;i++){tcount[i]/=n; high[i]=low[i]+tcount[i];low[i+1]=high[i];}
	cout<<"\n\t=============PROBABILITY TABLE==============\n";
	cout<<"\tCharacter||\tProbability||\tLow||\tHigh||";
	for(i=0;i<m;i++)
		cout<<"\n\t\t"<<temp[i]<<"|\t"<<tcount[i]<<"|\t\t"<<low[i]<<"|\t"<<high[i]<<"|";
	compress();
	decompress();
	while(1){
		cout<<endl<<"\n\t\tCompression................[1]";
		cout<<endl<<"\t\tDecompression..............[2]"<<endl<<"\t\tChoice : ";
		cin>>c;
		switch(c)
		{
			case 1:
				print(c);break;
			case 2:
				print(c);break;
			default:
				exit(0);
		}
	}
}
void Arithmetic :: addStr(){
	temp[m]=a;tcount[m]=c;m++;
}
void Arithmetic :: sortStr(int ){
	for (i=0;i<m-1;i++)
		if(temp[i]>temp[i+1]){	a=temp[i];j=tcount[i];
			temp[i]=temp[i+1];tcount[i]=tcount[i+1];
			temp[i+1]=a;tcount[i+1]=j;sortStr(i);}
}
void Arithmetic :: compress(){
	double l=0.00,h=1.00;
	int y;
	for(i=0,j=0;i<n;i++) {
		for(x=0;x<m;x++)
			if(temp[x]==str[i]){break;}
		com[i][j]=l+(h-l)*low[x];com[i][j+1]=l+(h-l)*high[x];
		l=com[i][j];h=com[i][j+1];}
	num=com[n-1][0];
}
void Arithmetic :: decompress(){
	i=0,j=0;
	while(i<n)
	for(x=0;x<m;x++)
		if(num>=low[x] && num<high[x] && num!=high[x])
		{
			st[i]=temp[x];
			decom[i][j]=low[x];
			decom[i][j+1]=high[x];b[i]=num;
			num-=low[x];
			num/=(high[x]-low[x]); i++;}
}
void Arithmetic :: print(int c){
	if(c==1){
		cout<<"\n\t=============COMPRESSION TABLE==============\n";
		cout<<"\tNew Character||\tLow||\tHigh||";
		for(i=0,j=0;i<n;i++){cout<<"\n\t\t"<<str[i]<<"|       "<<com[i][j]<<"|       "<<com[i][j+1]<<"|";}}
	if(c==2){
		cout<<"\n\t=============DECOMPRESSION TABLE==============\n";
		cout<<"\tNumber||\tSymbol||\tLow||\tHigh||";
		for(i=0,j=0;i<n;i++)
			cout<<endl<<b[i]<<"|\t"<<st[i]<<"|\t"<<decom[i][j]<<"|\t"<<decom[i][j+1]<<"|";
	}
}
void main(){
	clrscr();Arithmetic ar;
	cout<<"\n\t\t======= ARITHMETIC CODING =======";
	ar.getStr();getch();
}