#include<bits/stdc++.h>
using namespace std;
main()
{
	int pro,i,no,store=0,m=0;
	cout<<"Enter number of process"<<endl;
	cin>>pro;
	cout<<"Enter the position";
    int pos[pro+1];
	for(i=1;i<=pro;i++)
      cin>>pos[i];
	cout<<"Enter first position"<<endl;
	cin>>pos[0];
	for(i=0;i<pro;i++)
	 store+=abs(pos[i+1]-pos[i]);
	cout<<store<<endl;
}