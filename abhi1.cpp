#include<bits/stdc++.h>
using namespace std;
#define fl(i,m,n)  for(int i = int m; i < int n; i ++)
#define flz (i,n)  for(int i = 0 ; i < n; i ++)
typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector <int> vi;
typedef vector<ll> vl;	
const int inf = 1e9 + 7;
const int mod = 1e9 + 7;
const ll longinf = 1LL << 60;



int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r", stdin);
    freopen("output.txt" , "w", stdout);
    #endif
	ll t; cin >> t;
	while(t--)
	{
		ll p,b,f; cin >> b >> p >> f;
		ll h,c; cin >> h >> c;
		ll profit = 0;
		ll bur = b / 2;
		if(h > c)
		{
			if(bur > p)
				profit += h * p + min((bur - p),f) * c;
			else
				profit += h * bur; 
		}
		else
		{
			if(bur > f)
				profit += c * f + min((bur - f),p) * h;
			else
				profit += c * bur; 
		}
		cout << profit << endl;
	}
	return 0;
}