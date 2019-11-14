#include <bits/stdc++.h>
#include<unordered_set>
using namespace std;

int main()
{
	char play[5][5];
	unordered_set<char> s;
	int k, l;
	vector<char>v;
	string key, plain;
	cout<<"Enter the key"<<endl;
	cin>>key;
	cout<<"Enter the plaintext"<<endl;
	cin>>plain;

	// key loop, dont consider skipping i or j
	for(k=0; k<key.length(); k++)
		if(s.find(key[k])==s.end())
		{
			s.insert(key[k]);
			v.push_back(key[k]);
		}
	//consider i and j
	for(k=0; k < 26; k++)
	{
		char c = 'a' + k;
		if(c == 'i' || c == 'j')
		{
			if(s.find('i')==s.end() && s.find('j')==s.end())
			{
				s.insert(c);
				v.push_back(c);
			}
		}
		else if(s.find(c)==s.end())
		{
			s.insert(c);
			v.push_back(c);
		}
	}
	int i=0;
	for(k=0; k<5; k++)
		for(l=0; l<5; l++)
		{
			play[k][l]=v[i];
			i++;
		}
	cout<<"Playfair matrix"<<endl;
	for(k=0; k<5; k++)
	{
		for(l=0; l<5; l++)
			cout<<play[k][l]<<" ";
		cout<<endl;
	}
	return 0;
}
