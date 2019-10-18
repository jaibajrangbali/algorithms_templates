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
struct node
{
	ll cnt,end;
	struct node *zero,*one;
};
string s;
struct node *addtotrie(struct node *root,ll n,ll pos)
{
	if(root==NULL)
	{
		root=new node;
		root->cnt=root->end=0;
		root->one=root->zero=NULL;
	}
	if(pos==n)
	{
		root->end=1;
		root->cnt++;
		return root;
	}
	pos++;
	if(s[pos]=='0')
	{
		root->zero=addtotrie(root->zero,n,pos);
	}
	else
	{
		root->one=addtotrie(root->one,n,pos);
	}
	return root;
}
ll findcnt(struct node *root,ll n,ll pos)
{
	if(root==NULL)
	{
		return 0;
	}
	if(pos==n)
	{
		return (root->end==1? root->cnt:0);
	}
	pos++;
	if(s[pos]=='0')
	{
		return findcnt(root->zero,n,pos);
	}
	else
	{
		return findcnt(root->one,n,pos);
	}
}
int main(void)
{
	// fastio
	ll n;
	cin>>n;
	struct node *root=new node;
	for(ll i=0;i<n;i++)
	{
		cin>>s;
		addtotrie(root,s.size(),0);
	}
	ll q;
	cin>>q;
	while(q--)
	{
		cin>>s;
		cout<<findcnt(root,s.size(),0)<<"\n";
	}
	return 0;
}