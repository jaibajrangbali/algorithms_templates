#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define INF 1e18
std::vector< vector<long long int>  >  g;
std::vector<vector<long long int>> w;
std::vector<bool> vis;
std::vector<long long int> mst;
std::vector<long long int> dis;
void addedge(long long int a,long long int b,long long int we){
	g[a].pb(b);
	g[b].pb(a);
	w[a].pb(we);
	w[b].pb(we);
}

void dij(long long int src){
	dis[src]=0;
	priority_queue<pair<long long int,long long int>> pq;
	pq.push(make_pair(0,src));
	while(!pq.empty()){
		long long int u=pq.top().second; 
		long long int d=pq.top().first;
		pq.pop();
		if(vis[u]) continue;
		vis[u]=true;

		auto j=w[u].begin();
		for(auto i = g[u].begin() ;i!=g[u].end() ; i++,j++)
		{	
			long long int we=*j;  
			long long int v=*i;   
			if(dis[v] > we && vis[v] == false)
			{
				dis[v]=we;
				pq.push(make_pair(-dis[v],v));
			}
		}
	}
}

int main(){
	long long int n,e,thr;
	cin >>n >> e;
	g.assign(n+1,vector<long long int>());
	w.assign(n+1,vector<long long int>());
	vis.assign(n+1,false);
	dis.assign(n+1,INF);
	mst.assign(n+1,-1);

	long long int a,b,we;
	for(long long int i=0;i< e;i++){
		cin >> a >> b >> we;
		addedge(a,b,we);
	}
	dij(1);
	long long int sum=0;long long int fl=0;
	for(long long int i=1;i<=n;i++)
		{sum+=dis[i];
		//cout << dis[i] <<" ";	
		if(dis[i]==INF)fl=1;
		}
	cout << sum<<endl;	
	// if(fl==1)cout << "-1\n";
	// else {
	// 	long long int count =0;
	// 	sort(dis.begin()+1,dis.end());

	// 	for(long long int i=n;i>1;i--)
	// 		{	cout << dis[i]<< " ";
	// 			if(sum>thr)count++,sum=sum-dis[i]+1;
	// 		}
	// 		//cout << sum << ":sum";
	// 	if(sum>thr)cout << "-1\n";	
	// 	else cout << count << "\n";
	// }		
	//	out << dis[i] << " ";}
	//	cout << endl;
	
}