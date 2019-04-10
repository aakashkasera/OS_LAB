#include<iostream>
#define max 10
using namespace std;
class Priority
{
	public:
		int n,pr[max],bs[max];
		float arr[max];
		void getdata()
		{
			cout<<"Enter the number of process"<<endl;
			cin>>n;
			cout<<"Enter the burst time"<<endl;
			for(int i=0;i<n;i++)
			{
				cout<<"PROCESS "<<i+1<<": ";
				cin>>bs[i];
			}
			cout<<"Enter the priority"<<endl;
			for(int i=0;i<n;i++)
			{
				cout<<"PROCESS "<<i+1<<": ";
				cin>>pr[i];
			}
			cout<<"Enter the arrival time"<<endl;
			for(int i=0;i<n;i++)
			{
				cout<<"PROCESS "<<i+1<<": ";
				cin>>arr[i];
			}
			
		
		}
		void calculation()
		{
			int temp;
			 for (int i=0;i<n;i++) 
			 {
      			for (int j=i+1;j<n;j++) 
				{
         			if (pr[i]>pr[j])
					{
            			temp = pr[j];
            			pr[j] =pr[i];
            			pr[i] = temp;
 
            			temp = bs[j];
            			bs[j] = bs[i];
            			bs[i] = temp;
            			
            			
					}
				}
			}
			float ct=0.0,tat=0.0,wt=0.0,avgtat=0.0,avgwt=0.0;
			for(int i=0;i<=n-1;i++)
			{
				if(ct>arr[i])
				{
					ct=ct+bs[i];
					tat=ct-arr[i];
					wt=tat-bs[i];
					cout<<"PROCESS  "<<i+1<<" "<<endl;
					cout<<"Turn around time "<<tat<<" "<<"Waiting time "<<wt<<endl;
					avgtat=tat+avgtat;
					avgwt=wt+avgwt;
				}
				else
				{
					ct=0.0;
					ct=arr[i]+bs[i];
					tat=ct-arr[i];
					wt=tat-bs[i];
					cout<<"PROCESS  "<<i+1<<" "<<endl;
					cout<<"Turn around time "<<tat<<" "<<"Waiting time"<<wt<<endl;
					avgtat=tat+avgtat;
					avgwt=wt+avgwt;
				}
			}
			avgtat=avgtat/n;
			avgwt=avgwt/n;
			cout<<"AVERAGE TAT "<<avgtat<<endl;
			cout<<"AVERAGE WT "<<avgwt<<endl;
		}
		
};
int main()
{
	Priority obj;
	obj.getdata();
	obj.calculation();
	cout<<"TAT:Turn around time,WT:Waiting time "<<endl; 

	return 0;
}