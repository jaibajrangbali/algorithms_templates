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
    ll n,k;
    cin >> n >> k;
    vll s(n), x(n), y(n);
    ll a,b,c,d;
    for(ll i=0;i<k;i++) {
    	cin >> s[i];
    }
    cin >> a >> b >> c >> d;
    for(ll i=k;i<n;i++) {
    	s[i] = (s[i-2]*a + s[i-1]*b + c)%d;
    }
    for(ll i=0;i<k;i++) {
    	cin >> x[i];
    }
    cin >> a >> b >> c >> d;
    for(ll i=k;i<n;i++) {
    	x[i] = (x[i-2]*a + x[i-1]*b + c)%d;
    }
    for(ll i=0;i<k;i++) {
    	cin >> y[i];
    }
    cin >> a >> b >> c >> d;
    for(ll i=k;i<n;i++) {
    	y[i] = (y[i-2]*a + y[i-1]*b + c)%d;
    }
    ll totsum = 0, mn = 0, mx = 0;
    for(ll i=0; i<n; i++) {
    	totsum += s[i];
    	mn += x[i];
    	mx += (x[i] + y[i]);
    }
    if(totsum < mn || totsum > mx) {
    	cout << "-1\n";
    	return;
    }
    mn = 0, mx = 0;
    for(ll i=0; i<n; i++) {
    	if(s[i] < x[i]) {
    		mn += (x[i] - s[i]);
    	} else if(s[i] > x[i] + y[i]) {
    		mx += (s[i] - x[i] - y[i]);
    	}
    }
    // cout << mn << " " << mx << "\n";
    cout << max(mn, mx) << "\n";
}

int main()
{
    FAST_IO;
    #ifdef STIO 
      freopen("input.txt" , "r", stdin);
      freopen("output.txt" , "w", stdout);
    #endif
    ll t = 1;
    cin >> t;
    for (ll i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve(i);
    }
}
