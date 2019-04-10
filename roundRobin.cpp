#include<iostream>
#define max 100
using namespace std;
class RoundRobin{
	public:
		int n,q,i;
		float bt[max],tat[max],wt[max],rbt[max],t=0.0;
		bool done=true;
		void getdata(){
			cout<<"Enter number of processes = ";
			cin>>n;
			cout<<"Enter Quanta = ";
			cin>>q;
			cout<<"Enter Burst time of processes\n";
			for(i=0;i<n;i++){
				cin>>bt[i];
				rbt[i]=bt[i];
			}
		}
		void cal_time(){
			while(true){
				done=true;
				for(i=0;i<n;i++){
					if(rbt[i]>0){
						done=false;
						if(rbt[i]>q){
							t+=q;
							rbt[i]-=q;
						}
						else{
							t+=rbt[i];
							rbt[i]=0;
							wt[i]=t-bt[i];
							tat[i]=t; //or bt[i]+wt[i];
						}
					}
				}
				
				if(done==true)
				break;
			}	
		}
		void display(){
			cout<<"Turn around time of the processes\n";
			for(i=0;i<n;i++)
				cout<<"Process "<<i+1<<" = "<<tat[i]<<endl;
			cout<<"\nWaiting time of the processes\n";
			for(i=0;i<n;i++)
				cout<<"Process "<<i+1<<" = "<<wt[i]<<endl;	
		}
};
int main(){
	RoundRobin obj;
	obj.getdata();
	obj.cal_time();
	obj.display();
	return 0;
}