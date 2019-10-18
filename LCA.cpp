#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef map <ll,ll> mm;
typedef vector <ll> mv;
typedef pair <ll,ll> mp;
typedef set <ll> ms;
typedef queue <ll> mq;
typedef deque <ll> mdq;
typedef stack <ll> mst;
typedef priority_queue <ll> mpq;
typedef priority_queue <ll, vector<ll>, greater<ll> > mmh;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define flush cout.flush();
#define cn continue
void swap(ll &a,ll &b)
{
	ll tmp=a;
	a=b;
	b=tmp;
}
ll atoistring(string s)
{
	stringstream lol(s);
	ll x;
	lol>>x;
	return x;
}
// ll nck(ll N,ll K,ll mod)
// {
// 	if(N<K)
// 	{
// 		return 0;
// 	}
// 	return (((facs[N]*facsinv[N-K])%mod)*facsinv[K])%mod;
// }
ll power(ll x,ll y,ll p)
{
	ll res=1;
	x=x%p;
	while(y>0)
	{
		if(y&1)
		{
			res=(res*x)%p;
		}
		y=y>>1;
		x=(x*x)%p;
	}
	return res;
}
void checkmod(ll &x,ll mod)
{
	if(x>=mod)
	{
		x%=mod;
	}
}
// void checktime()
// {
// 	struct timespec ts;
// 	printf("Running Program\n");
// 	clock_gettime(CLOCK_MONOTONIC_RAW,&ts);
// 	long double st=ts.tv_nsec/(1e9)+ts.tv_sec;
// 	// Call Funcn Here
// 	clock_gettime(CLOCK_MONOTONIC_RAW,&ts);
// 	long double en=ts.tv_nsec/(1e9)+ts.tv_sec;
// 	printf("Program ended\nTime = %Lf\n",en-st);
// }
ll stakk[100005],size=0,ht[100005];
mv adj[100005],ancestors[100005];
void DFS(ll x,ll par,ll height)
{
	stakk[size++]=x;
	ht[x]=height++;
	for(ll i=size-2,l=2;i>=0;i=size-l-1,l*=2)
	{
		ancestors[x].push_back(stakk[i]);
	}
	for(ll i=0;i<adj[x].size();i++)
	{
		if(adj[x][i]!=par)
		{
			DFS(adj[x][i],x,height);
		}
	}
	size--;
}
ll findnth(ll x,ll n)
{
	if(n==0)
	{
		return x;
	}
	ll lol=log2(n);
	lol=pow(2,lol);
	return findnth(ancestors[x][lol-1],n-lol);
}
ll findans(ll x,ll y)
{
	if(x==y)
	{
		return x;
	}
	ll i;
	for(i=min(ancestors[x].size(),ancestors[y].size())-1;i>=0;i--)
	{
		if(ancestors[x][i]!=ancestors[y][i])
		{
			break;
		}
	}
	i++;
	return findans(ancestors[x][i],ancestors[y][i]);
}
ll findancestor1(ll x,ll y)
{
	if(ht[y]>ht[x])
	{
		swap(x,y);
	}
	x=findnth(x,ht[x]-ht[y]);
	return findans(x,y);
}
int main(void)
{
	// fastio
	ll n,root;
	cin>>n>>root;
	ll x,y;
	for(ll i=1;i<n;i++)
	{
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	DFS(root,root,0);
	ll q;
	cin>>q;
	while(q--)
	{
		cin>>x>>y;
		cout<<findancestor1(x,y)<<"\n";
	}
	return 0;
}