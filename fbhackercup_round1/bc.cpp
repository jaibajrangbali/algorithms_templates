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

bool isPoss(vll &a, vll &b, ll dist)
{
	ll pt_a = 0;
	ll pt_b = 0;
	ll t_dist = 0;
	ll n = (ll)a.size();
	ll m = (ll)b.size();
	while(pt_a < n && pt_b < m)
	{
		if(a[pt_a] > b[pt_b] + dist || a[pt_a] < b[pt_b] - dist) {
            pt_b++;
        } else if(a[pt_a] >= b[pt_b]) {
            pt_a++;
        } else {
            ll dst = b[pt_b] - a[pt_a];
            ll go_dst = max((dist - 2*dst), (dist - dst)/2);
            while(a[pt_a] <= b[pt_b] + go_dst && pt_a < n) {
                pt_a++;
            } 
            pt_b++;
        }
	}
	return (pt_a == n);
}

void solve(ll testnum)
{
    ll n, m, k, s;
    cin >> n >> m >> k >> s;
    vll p(n), q(m);
    for(ll i=0; i<k; i++) {
    	cin >> p[i];
    }
    ll ap, bp, cp, dp;
    cin >> ap >> bp >> cp >> dp;
    for(ll i=k; i < n; i++) {
    	p[i] = (ap*p[i-2] + bp*p[i-1] + cp)%dp + 1;
    }
    for(ll i=0; i<k; i++) {
    	cin >> q[i];
    }
    cin >> ap >> bp >> cp >> dp;
    for(ll i=k; i < m; i++) {
    	q[i] = (ap*q[i-2] + bp*q[i-1] + cp)%dp + 1;
    }
    sort(all(p));
    sort(all(q));
    vll prev(n), qrev(m);
    for(ll i=0; i<n; i++) {
    	prev[i] = -p[n-1-i];
    }
    for(ll i=0; i<m; i++) {
    	qrev[i] = -q[m-1-i];
    }
    ll mn = 0, mx = (ll)1e18;
    while(mn <= mx) {
    	ll md = (mn + mx)/2;
    	if(isPoss(q, p, md) || isPoss(qrev, prev, md)) {
    		mx = md - 1;
    	} else {
    		mn = md + 1;
    	}
    }
    cout << mn << "\n";
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