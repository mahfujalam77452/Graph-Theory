#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
const int N = 1e5 + 5;
const int INF=1000000000;
int n;
vector<int>adj[N];
vector<int>visited;
vector<int>parent;
int cycle_start,cycle_end;
bool dfs(int v,int par){
    visited[v]=true;
    for(int u:adj[v]){
        if(u==par)
              continue;
        else if(visited[u]){
            cycle_end=v;
            cycle_start=u;
            return true;
        }
        parent[u]=v;
        if(dfs(u,v))
               return true;
    }
    return false;
}
void find_cycle(){
    visited.assign(n,false);
    parent.assign(n,-1);
    cycle_start=-1;
    for(int v=0;v<n;v++)
              if(!visited[v]&&dfs(v,parent[v]))
                                          break;
    if(cycle_start==-1)
                 cout<<"Acyclic"<<endl;
    else {
        vector<int>cycle;
        cycle.push_back(cycle_start);
        for(int v=cycle_end;v!=cycle_start;v=parent[v])
                                    cycle.push_back(v);
        cycle.push_back(cycle_start);
        cout<<"Cycle Found : ";
        for(int v:cycle)
                    cout<<v<<" ";
        cout<<endl;
    }
}
int32_t main()
{
	int m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
	    int u,v;
	    cin>>u>>v;
	    u--;v--;
	    adj[u].push_back(v);
	    adj[v].push_back(u);
	}
	find_cycle();
	return 0;
}



