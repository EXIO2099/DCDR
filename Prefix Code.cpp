#include<iostream.h>
#include<string.h>
#include<conio.h>
#include<math.h>
char s1[20],s2[20]; int i,j,k,l,m,n,flag=0;
class Prefix{
	public:	void getInput();
};
void Prefix :: getInput(){
	cout<<"\n\tInput 1 : "	; cin.getline(s1,20);
	cout<<"\n\tInput 2 : "; cin.getline(s2,20);
	if(strlen(s1) < strlen(s2))
		for (i=0,j=0;i<strlen(s2);i++)
			if(s2[i]==s1[j]){j++; if(j==strlen(s1)){ flag=1; break;}
				else continue;}	
			if(flag==1) cout<<"\n\t\t\'"<<s1<<"\'"<<" is prefix of "<<"\'"<<s2<<"\'\n\n";	
	else if(strlen(s2)<strlen(s1)){
		for (i=0,j=0;i<strlen(s1);i++)
			if(s1[i]==s2[j]){j++; if(j==strlen(s2)){ flag=1; break;}
				else continue;}	
			if(flag==1) cout<<"\n\t\t\'"<<s2<<"\'"<<" is prefix of "<<"\'"<<s1<<"\'\n\n";
			else	cout<<"\n\t\tPrefix Property Satisfied\n\n";
	}
	else	cout<<"\n\t\tPrefix Property Satisfied\n\n";
}
int main(){
	Prefix p;
	cout<<"\n\t\t=======CHECK FOR PREFIX CODE=======";
	p.getInput();
	return 0;
	getch();
}