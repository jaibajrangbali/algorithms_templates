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
#define OC freopen("input.txt" , "r", stdin); freopen("output.txt" , "w", stdout) 
#define MOD (ll)1e9+7; //change it for other mods
#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
        //*******************************************************
//Some Functions

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

void solve()
{
    //solve
}

int main()
{
    FAST_IO;
    #ifndef ONLINE_JUDGE 
      OC;
    #endif
    ll t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}