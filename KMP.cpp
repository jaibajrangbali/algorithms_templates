#include<bits/stdc++.h>
using namespace std;

vector<int> KMP(char *str, char *srch)/// it returns vector containing match indices of given string in long string(string in which we have to find) 
{
	int l = strlen(str);
	int m = strlen(srch);
	////////////////////////Making Prefix Array(lps) 
	int lps[100005];
	lps[0] = 0;
	int j = 0;
	for (int i = 1; i < m; ++i)
	{
		if(srch[i] == srch[j])
		{
			j++;
			lps[i] = j;
		}
		else
		{
			while(1)
			{
				if(j != 0)
					j = lps[j-1];
				else
					break;
				if(srch[j] == srch[i])
				{
					j++;
					break;
				}
			}
			lps[i] = j;
		}
	}
/*	/////////////////////ending making lps
	\\\\\\\\\\\\\\\\\\\	Starting search for indices in str matching srch */
	vector<int> matches;
	j = 0;
	int i = 0;
	while(i < l) 
	{ 
        if (srch[j] == str[i]) 
        { 
            j++; 
            i++; 
        } 
        if (j == m) { 
        	matches.push_back(i-j);
            j = lps[j - 1]; 
        } 
        else if (i < l && srch[j] != str[i]) 
        { 
            if (j != 0) 
                j = lps[j - 1]; 
            else
                i++; 
        } 
    } 
	return matches;
	//// returned vector containing matches 
}
int main(void)
{
	char str[100005], srch[100005];
	cin>>srch;
	cin>>str;
	vector<int> match = KMP(str, srch);// way to execute KMP
	
	//cout<<match.size()<<"\n";
	if(match.size() == 0)
		cout<<"no match found";
	for (int i = 0; i < match.size(); ++i)
	{
		cout<<match[i]<<" ";
	}
	cout<<"\n";
	return 0;
}