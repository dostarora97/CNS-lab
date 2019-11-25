#include <bits/stdc++.h>
using namespace std;

int main()
{
    char play[5][5];
    vector<char> v;

    string key, pt, temp_pt, ct="";

    cout<<"Enter Key : ";
    cin>>key;
    cout<<"Enter Plain Text : ";
    cin>>pt;
    temp_pt = pt;

    if(pt.length()%2 != 0)
    {
        pt = pt + 'x';
        // cout<<"Added a \'x\' to the string\n";
        // cout<<pt<<endl;
    }

    for(int i=0; i<key.length(); i++)
    {
        if(find(v.begin(), v.end(), key[i]) == v.end())
        {
            v.push_back(key[i]);
        }
    }

    for(int i=0; i<26; i++)
    {
        char c = 'a' + i;
        if(c=='i' || c =='j')
        {
            if(find(v.begin(), v.end(), c)==v.end() && find(v.begin(), v.end(), c)==v.end())
            {
                v.push_back(c);
            }
        }
        else
        {
            if(find(v.begin(), v.end(), c) == v.end())
            {
                v.push_back(c);
            }
        }
    }

    int k = 0;
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            play[i][j] = v[k];
            k++;
        }
    }

    cout<<"Playfair Matrix"<<endl;
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            cout<<play[i][j]<<" ";
        }
        cout<<"\n";
    }

    for(int i=0; i<pt.length(); i=i+2)
    {
        int flag;
        flag = 0;

        char pt_c1 = pt[i];
        char pt_c2 = pt[i+1];
        // cout<<"pt_c1 : "<<pt_c1<<", pt_c2 : "<<pt_c2<<endl;

        if(pt_c1 == pt_c2)
        {
            flag = 1;
            pt_c2 = 'x';
            // cout<<"pt_c2 = x :=> pt_c2 : "<<pt_c2<<endl;
        }

        int r1, c1, r2, c2;
        for(int j=0; j<5; j++)
        {
            for(int k=0; k<5; k++)
            {
                if(play[j][k] == pt_c1)
                {
                    r1 = j;
                    c1 = k; 
                }
                if(play[j][k] == pt_c2)
                {
                    r2 = j;
                    c2 = k;
                }
            }
        }
        // cout<<"pt_c1 : r1 "<<r1<<", c2 "<<c1<<endl;
        // cout<<"pt_c2 : r2 "<<r2<<", c2 "<<c2<<endl;

        char ct_c1, ct_c2;
        if(r1 == r2)
        {
            ct_c1 = play[r1][(c1+1)%5];
            ct_c2 = play[r2][(c2+1)%5];
            // cout<<"r1==r2 : ct_c1 = "<<ct_c1<<", ct_c2 "<<ct_c2<<endl;
        }
        else 
        {
            if(c1==c2)
            {
                ct_c1 = play[(r1+1)%5][c1];
                ct_c2 = play[(r2+1)%5][c2];
                // cout<<"c1==c2 : ct_c1 = "<<ct_c1<<", ct_c2 "<<ct_c2<<endl;
            }
            else
            {
                ct_c1 = play[r1][c2];
                ct_c2 = play[r2][c1];
                // cout<<"ELSE : ct_c1 = "<<ct_c1<<", ct_c2 "<<ct_c2<<endl;
            }
        }
        ct = ct + ct_c1 + ct_c2;
        if(flag == 1)
        {
            ct = ct + ct_c1 + ct_c2;
        }
        // cout<<endl;        
    }

    cout<<"Plain Text : "<<temp_pt<<endl;
    cout<<"Cipher Text : "<<ct<<endl;

    return 0;
}