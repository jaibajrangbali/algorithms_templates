// C++ program to demonstrate various function of unordered_set
#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_set<string> stringSet;
    unordered_set<string> search;
    string s; // declaring set for storing string data-type
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        stringSet.insert(s);
    } // inserting various string, same string will be stored once in set
    int q;
    cin >> q;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        //wherever ? replace it by nothing or something
        int in[3] = {'?', '?', '?'}, o = 0;
        for (int j = 0; j < s.length; j++)
            if (s[j] == '?')
                in[o++] = j;
        for (int k = 0; k < 6; k++)
            ;
    }

    string key = "slow";

    //	 find returns end iterator if key is not found,
    // else it returns iterator to that key
    if (stringSet.find(key) == stringSet.end())
        cout << key << " not found\n\n";
    else
        cout << "Found " << key << endl
             << endl;

    key = "c++";
    if (stringSet.find(key) == stringSet.end())
        cout << key << " not found\n";
    else
        cout << "Found " << key << endl;

    // now iterating over whole set and printing its
    // content
    cout << "\nAll elements : ";
    unordered_set<string>::iterator itr;
    for (itr = stringSet.begin(); itr != stringSet.end(); itr++)
        cout << (*itr) << endl;
}

