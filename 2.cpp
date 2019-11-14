#include <bits/stdc++.h>
using namespace std;

int main() {
	int i, b_size, o_rate, n, temp, cur_b=0;
	vector<int>p;
	cout<<"Enter bucket size: ";
	cin>>b_size;
	cout<<"Enter output rate: ";
	cin>>o_rate;
	cout<<"Enter number of packets: ";
	cin>>n;
	cout<<"Enter the packets: ";
	for(i=0; i<n; i++)
	{
		cin>>temp;
		p.push_back(temp);
	}
	for(i=0; i<n; i++)
	{
		if(p[i]+cur_b<=b_size+o_rate)
		{
			cur_b=cur_b+p[i];
			cout<<"Packet "<<i<<" transmitted! ";
		}
		else
			cout<<"Packet "<<i<<" discarded! ";
		cur_b=cur_b-o_rate;
		if(cur_b<0)
			cur_b=0;
		cout<<"Bucket status "<<cur_b<<"/"<<b_size<<endl;
	}
	return 0;
}