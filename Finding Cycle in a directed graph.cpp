#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
//#define int long long
const int N = 1e5 + 10;
const int INF=1000000000;
int n,m;
vector<int>adj[N];
vector<bool>visited(N,false);
vector<bool>recs(N,false);
//It will track the all iteration of dfs before it return .
int starting_point=-1,ending_point=-1;
vector<int>parent(N,-1);
int cnt=0;
bool dfs(int v,int par=-1){
    visited[v]=true;
    recs[v]=true;
    for(int u:adj[v]){
        if(visited[u]&&recs[u]==false)continue;
        else if(visited[u]&&recs[u]==true){
            starting_point=u;
            ending_point=v;
            return true;
        }
        parent[u]=v;
        if(dfs(u,v))return true;
    }
    recs[v]=false;//removing the node from the stack while returning.
    return false;
}
int32_t main()
{
//	IOS;
	cin>>n>>m;
	for(int i=0;i<m;i++){
	    int u,v;
	    cin>>u>>v;
	    adj[u].push_back(v);
	}
	vector<int>path;
	for(int v=1;v<=n;v++){
	    if(!visited[v]&&dfs(v,parent[v])){
	        break;
	    }
	}
	if(starting_point==-1)cout<<"IMPOSSIBLE"<<endl;
	else{
	    path.push_back(starting_point);
	    for(int v=ending_point;v!=starting_point;v=parent[v])path.push_back(v);
	    path.push_back(starting_point);
	    reverse(path.begin(),path.end());
	    cout<<path.size()<<endl;
	    for(int i:path)cout<<i<<" ";
	    cout<<endl;
	}
 
	return 0;
}
