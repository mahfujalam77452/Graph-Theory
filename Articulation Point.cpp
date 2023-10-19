//Note that: This code is design starting with Root 0. 
#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
const int N = 1e5 + 5;
int n;
vector<int>adj[N];
vector<int>tin,low;
int timer;
vector<bool>visited;
void is_Articulation_point(int u){
    cout<<u<<" is a Articulation point"<<endl;
}
void dfs(int v,int p=-1){
    visited[v]=true;
    tin[v]=low[v]=timer++;
    int children=0;
    for(auto &to:adj[v]){
        if(to==p)continue;
        if(visited[to]){
            low[v]=min(low[v],tin[to]);
        }
        else{
            
            dfs(to,v);
            low[v]=min(low[v],low[to]);
            if(low[to]>=tin[v]&&p!=-1){
                is_Articulation_point(v);
            }
            children++;
        }
    }
    if(p==-1&&children>1){
        is_Articulation_point(v);
    }
    
}
void find_Bridge(){
    visited.assign(n,false);//node starting with 0
    tin.assign(n,-1);//node starting with 0
    low.assign(n,-1);//node starting with 0
    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(i);
        }
    }
}
int32_t main()
{
	IOS;
    cin>>n;int m;cin>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    find_Bridge();
	return 0;
}

