#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
const int N = 1e5 + 5;
int n;
vector<int>adj[N];
vector<bool>used(N,0);
vector<int>component;
void dfs(int node){
    used[node]=true;
    component.push_back(node);
    for(auto &a:adj[node]){
        if(!used[a]){
            dfs(a);
        }
    }
}
void find_component(){
    for(int i=1;i<=n;i++){
        if(!used[i]){
            component.clear();
            dfs(i);
            cout<<component.size()<<endl;
            for(auto &a:component)cout<<a<<' ';
            cout<<endl;
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
	find_component();
	return 0;
}
/*
Deeply recursive functions are in general bad.
Every single recursive call will require a little bit of memory in the stack, 
and per default programs only have a limited amount of stack space.
So when you do a recursive DFS over a connected graph with millions of nodes,
you might run into stack overflows.It is always possible to translate a recursive program into an iterative program, 
by manually maintaining a stack data structure.
Also you can use bfs for this algorithm.
*/
