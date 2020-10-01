#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector <ll> mv;

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
