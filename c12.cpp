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
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int a[n+10];
		for(int i = 0 ; i < n; i ++)
		{
			cin >> a[i];
		}
		int ans = 0;
		for(int i = 0 ; i < n;i ++)
		{
			if(a[i] % 3 == 0 && a[i] != 0)
			{
				ans ++;
				//cout << "i :"<< i << endl;
				a[i] = 0;
				continue;
			}
		}
		for(int i = 0 ; i < n - 1 ;i ++)
		{
			for(int j = i + 1 ; j < n; j ++)
			{
				if((a[i] + a[j] )% 3 == 0 && a[i] != 0 && a[j] != 0 && a[i] != 3 && a[j] != 3)
				{
					//cout << "j:" << j << endl;
					ans ++;					
					a[i] = 0;a[j] = 0;
					continue;
				}
			}
		}
		for(int i = 0 ; i < n;i ++)
		{
			for(int j = i + 1 ; j < n; j ++)
			{				
				for(int k = j + 1; k < n; k ++)
				{
					if((a[i] + a[j] + a[k]) % 3 == 0 && a[i] != 0 && a[k] !=0  && a[j] != 0 && a[i] != 3 && a[k] !=3  && a[j] != 3)
					{
						//cout <<  i << " j: " << j << " k:" << k << endl;
						ans ++;
						a[i] = 0;a[j] = 0;a[k] = 0;
						continue;						
					}
				}

			}
		}
		cout << ans << endl;
	}
	return 0;
}