#include<bits/stdc++.h>
#define max 5
using namespace std;

int s=1,e=5,f=0;
int wait(int s)
{   
	return(--s);
}
int signal(int s)
{
	return(++s);
}

void producer()
{
	while(1)
{
	cout<<"In producer code\n";
	e=wait(e);
	s=wait(s);
	cout<<"Producing item"<<endl;
	s=signal(s);
	f=signal(f);
	break;
	}	
}


void consumer()
{
	while(1)
	{   cout<<"In consumer code\n";
		f=wait(f);
		s=wait(s);
		cout<<"Consuming an item\n"<<endl;
		s=signal(s);
		e=signal(e);
		break;
	}
}

main()
{   int cho;
	while(1)
	{cout<<"1.Producer\n2.Consumer\n3.Exit\n";
	cin>>cho;
	switch(cho)
	{
		case 1: if(s==1 && e!=0)
		{
		producer();
		cout<<"S="<<s<<"\tE="<<e<<"\tF="<<f<<endl;
		}
		else cout<<"Buffer is full\n";
		break;
		
		case 2: if(s==1&& f!=0)
		{
		consumer();
		cout<<"S="<<s<<"\tE="<<e<<"\tF="<<f<<endl;
		}
		else cout<<"Buffer empty\n";
		break;
		
		case 3: exit(0);
		break;
	}
		
		}	

}