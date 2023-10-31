#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
const int N = 1e5 + 10;
const int INF=1000000;
int n,m;
vector<vector<int>>capacity;
vector<vector<int>>adj;
int bfs(int s,int t,vector<int>&parent){
    fill(parent.begin(),parent.end(),-1);
    parent[s]=-2;
    queue<pair<int,int>>q;
    q.push({s,INF});
    while(!q.empty()){
        int cur=q.front().first;
        int flow=q.front().second;
        q.pop();
        for(int next:adj[cur]){
            if(parent[next]==-1&&capacity[cur][next]){
                parent[next]=cur;
                int new_flow=min(flow,capacity[cur][next]);
                if(next==t)
                       return new_flow;
               q.push({next,new_flow});
            }
        }
    }
    return 0;
}
int maxflow(int s,int t){
    int flow=0;
    vector<int>parent(N+1);
    int new_flow;
   
    while(new_flow=bfs(s,t,parent)){
        
        flow+=new_flow;
        int cur=t;
        while(cur!=s){
            int prev=parent[cur];
            capacity[prev][cur]-=new_flow;
            capacity[cur][prev]+=new_flow;
            cur=prev;
        }
        
    }
    return flow;
}
int32_t main()
{
   int n,m;
   cin>>n>>m;
   capacity.assign(n+1,vector<int>(n+1,0));
   adj.assign(n+1,vector<int>());
   for(int i=0;i<m;i++){
       int u,v,wt;
       cin>>u>>v>>wt;
       adj[u].push_back(v);
       adj[v].push_back(u);
       capacity[u][v]=wt;
   }
  
   cout<<maxflow(0,5)<<endl;
	return 0;
}


