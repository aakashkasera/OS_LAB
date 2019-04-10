#include<iostream>
using namespace std;
int main()
{
	int n;
	cout<<"Enter the number of memory blocks : ";
	cin>>n;
	int a[n],size[n],hole[n],h,address[n];
	for(int i=0;i<n;i++)
	{
		hole[i]=0;
		address[i]=0;
	}
	for(int i=0;i<n;i++)
	{
		cout<<"Enter the size of block "<<(i+1)<<": ";
		cin>>size[i];
		address[i+1]=address[i]+size[i];
		cout<<"Enter 1 if this block is a hole else press any other number: ";
		cin>>h;
		if(h==1)hole[i]=1;
	}
	int np;
	cout<<"Enter the number of processes to be excecuted: ";
	cin>>np;
	int process[np];
	for(int i=0;i<np;i++)
	{
		cout<<"Enter the size of process "<<(i+1)<<" : ";
		cin>>process[i];
	}
	int alloted[np];
	for(int i=0;i<np;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(!hole[j])continue;
			if(size[j]<process[i])continue;
			alloted[i]=address[j];
			size[j]=size[j]-process[i];
			address[j]=address[j]+process[i];
			break;
		}
	}
	for(int i=0;i<np;i++)
	{
		cout<<"Process"<<(i+1)<<" is alloted "<<alloted[i]<<" adderss.\n";
	}
	return 0;
}