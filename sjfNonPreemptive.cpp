#include<iostream>
using namespace std;
#include<algorithm>
    int n;
	void show(int x[])
	{
		for(int i=0;i<n;i++)
		{
			cout<<x[i]<<endl;
		}
	}
	void avg(int x[])
	{
		float c=0;
		for(int i=0;i<n;i++)
		{
		  c=c+x[i];
		}
		cout<<c/n<<endl;
	}

main()
{
	cout<<"Enter the no. of processes"<<endl;
	cin>>n;
	int WT[n],TAT[n],BT[n];
	//here WT=wating time,TAT=turn around time,BT=burst time of the process
	cout<<"Enter the Burst time of processes"<<endl;
	for(int i=0;i<n;i++)
	cin>>BT[i];
	sort(BT,BT+n);
	WT[0]=0;
	for(int i=1;i<n;i++)
	{
		int c=0;
		for(int j=i-1;j>=0;j--)
		c=c+BT[j];
		WT[i]=c;
	}
	for(int i=0;i<n;i++)
	TAT[i]=BT[i]+WT[i];
	cout<<"......Burst Time......"<<endl;
	show(BT);
	cout<<"......Waiting Time......"<<endl;
	show(WT);
	cout<<"....Turn Around Time...."<<endl;	
	show(TAT);
	cout<<"Average Waiting Time = ";
	avg(WT);
	cout<<"Average Turn Around Time = ";
	avg(TAT);
}