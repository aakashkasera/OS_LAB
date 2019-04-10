#include<iostream>
using namespace std;
int main()
{
	int n;
	cout<<"Enter the number of processes : ";
	cin>>n;
	int r;
	cout<<"Enter the number of resources : ";
	cin>>r;
	int max[n][r],alloc[n][r];
	int available[r];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<r;j++)
		{
			cout<<"Enter the need of resource"<<(j+1)<<" required for execution of process"<<(i+1)<<" : ";
			cin>>max[i][j];
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<r;j++)
		{
			cout<<"Enter the number of already alloted resource"<<(j+1)<<" for procsess"<<(i+1)<<" : ";
			cin>>alloc[i][j];
		}
	}
	for(int i=0;i<r;i++)
	{
		cout<<"Enter the avaliblity of resource"<<(i+1)<<" : ";
		cin>>available[i];
	}
	int counter=n;
	int safe=1;
	int exec;
	int running[n];
	for(int i=0;i<n;i++)running[i]=1;
	while(counter!=0)
	{
		safe=0;
		for(int i=0;i<n;i++)
		{
			if(running[i])
			{
				exec=1;
				for(int j=0;j<r;j++)
				{
					if((max[i][j]-alloc[i][j])>available[j])
					{
						exec=0;
						break;
					}
				}
				if(exec)
				{
					running[i]=0;
					counter--;
					safe=1;
					for(int j=0;j<r;j++)
					{
						available[j]+=alloc[i][j];
					}
					break;
				}
			}
		}
	}
	if(safe==0)
	{
		cout<<"Deadlock\n";
	}
	else
	{
		cout<<"Safe\n";
	}
}