#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;

//****************************************************                
#define lp(var,start,end) for (ll var = start; var <end ; ++var)
#define rlp(var,start,end) for(ll var = start; var>=end ; var--)
#define pb push_back
#define mp make_pair
#define pf push_front
#define ff first
#define ss second
#define vll vector<ll>
#define pll pair<ll,ll> 
#define vpll vector<pll>
#define all(X) X.begin(),X.end()
#define endl "\n" //comment it for interactive questions
#define trace1(a) cerr << #a << ": " << a << endl;
#define trace2(a,b) cerr << #a << ": " << a << " " << #b << ": " << b << endl;
#define trace3(a,b,c) cerr << #a << ": " << a << " " << #b << ": " << b << " " << #c << ": " << c << endl;
#define trace4(a,b,c,d) cerr << #a << ": " << a << " " << #b << ": " << b << " " << #c << ": " << c << #d << ": " << d << endl;
#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
        //*******************************************************
//Some Functions

const ll MOD = (ll)1e9+7; //change it for other mods

ll powmod(ll a,ll b)
{
   ll res = 1;
   while(b > 0) {
      if(b & 1) res = (res * a) % MOD;
      a = (a*a)%MOD;
      b = b >> 1; 
  }
  return res % MOD;
}

void solve(ll testnum)
{
    ll n;
    cin >> n;
    vll a(n);
    ll mn = 10000001, mx = -10000001;
    for(ll i = 0; i < n; i++) {
    	cin >> a[i];
    	mn = min(mn, a[i]);
    	mx = max(mx, a[i]);
    }
    ll cnt0 = 0, cnt1 = 0, cnt2 = 0;
    for(ll i = 0; i < n; i++) {
    	if(a[i] == mn) {
    		cnt0++;
    	} else if(a[i] == mx) {
    		cnt2++;
    	} else {
    		cnt1++;
    	}
    }
    if(mn == mx || mx == mn + 1) {
    	cout << n << "\n";
    	for(ll i = 0; i < n; i++) {
    		cout << a[i] << " ";
    	}
    	cout << "\n";
    	return;
    }
    ll diff = max(min(cnt0, cnt2)*2, (cnt1/2)*2);
    ll ans = n - diff;
    cout << ans << "\n";
    if(diff == min(cnt0, cnt2)*2) {
    	cnt0 -= diff/2;
    	cnt2 -= diff/2;
    	cnt1 += diff;
    } else {
    	cnt1 -= diff;
    	cnt0 += diff/2;
    	cnt2 += diff/2;
    }
    for(ll i = 0; i < cnt0; i++) {
    	cout << mn << " ";
    }
    for(ll i = 0; i < cnt1; i++) {
    	cout << mn + 1 << " ";
    }
    for(ll i = 0; i < cnt2; i++) {
    	cout << mn + 2 << " ";
    }
    cout << "\n";
}

int main()
{
    FAST_IO;
    #ifdef STIO 
      freopen("input.txt" , "r", stdin);
      freopen("output.txt" , "w", stdout);
    #endif
    ll t = 1;
    // cin >> t;
    for (ll i = 1; i <= t; i++) {
        // cout << "Case #" << i << ": ";
        solve(i);
    }
}