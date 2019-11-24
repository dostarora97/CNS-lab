#include <bits/stdc++.h>
using namespace std;

int main()
{
	char play[5][5];
	int k, l;
	vector<char>v;
	string key, plain, tmpplain, ctext="";

	cout<<"Enter the key: ";
	cin>>key;
	cout<<"Enter the plaintext: ";
	cin>>plain;
	tmpplain=plain;
	if(plain.length()%2!=0)
		tmpplain+='x';

	// key loop, dont consider skipping i or j
	for(k=0; k<key.length(); k++)
		if(find(v.begin(),v.end(),key[k])==v.end())
			v.push_back(key[k]);

	//consider i and j
	for(k=0; k < 26; k++)
	{
		char c = 'a' + k;
		if(c == 'i' || c == 'j')
		{
			if(find(v.begin(),v.end(),'i')==v.end() && find(v.begin(),v.end(),'j')==v.end())
				v.push_back(c);
		}
		else if(find(v.begin(),v.end(),c)==v.end())
			v.push_back(c);
	}

	int i=0;
	for(k=0; k<5; k++)
		for(l=0; l<5; l++)
		{
			play[k][l]=v[i];
			i++;
		}

	cout<<"\nPlayfair matrix"<<endl;
	for(k=0; k<5; k++)
	{
		for(l=0; l<5; l++)
			cout<<play[k][l]<<" ";
		cout<<endl;
	}
	cout<<endl;

	for(i=0; i<tmpplain.length(); i+=2)
	{
		int c1, c2, d1, d2, flag=0;
		char n1=tmpplain[i], n2=tmpplain[i+1];
		if(n1==n2)
		{
			flag=1;
			n2='x';
		}		
		for(k=0; k<5; k++)
		{
			for(l=0; l<5; l++)
			{
				if(play[k][l]==n1)
				{
					c1=k;
					c2=l;
				}
				if(play[k][l]==n2)
				{
					d1=k;
					d2=l;
				}
			}			
		}
		if(c1==d1)
		{
			n1 = play[c1][(c2+1)%5];
			n2 = play[d1][(d2+1)%5];
		}		
		else if(c2==d2)
		{
			n1 = play[(c1+1)%5][c2];
			n2 = play[(d1+1)%5][d2];
		}		
		else
		{
			n1 = play[c1][d2];
			n2 = play[d1][c2];
		}
		ctext=ctext+n1+n2;
		if(flag==1)
			ctext=ctext+n1+n2;
	}

	cout<<"The plaintext is: "<<plain<<endl;
	cout<<"The ciphertext is: "<<ctext<<endl;
	return 0;
}
