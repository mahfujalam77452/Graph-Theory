#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
const int N = 1e5 + 5;
const int INF=1000000000;
vector<int>adj[N],rev_adj[N];
vector<bool>used;
vector<int>order,component;
vector<int>adj_scc[N];
vector<int>roots(N,0);
vector<int>root_nodes;
void dfs1(int s){
    used[s]=true;
    for(auto child:adj[s])
             if(!used[child])
                        dfs1(child);
    order.push_back(s);
}
void dfs2(int s){
    used[s]=true;
    component.push_back(s);
    for(auto child:rev_adj[s])
                if(!used[child])
                       dfs2(child);
}
int32_t main()
{
	IOS;
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
	    int u,v;
	    cin>>u>>v;
	    adj[u].push_back(v);
	    rev_adj[v].push_back(u);
	}
	used.assign(n,false);
	for(int v=0;v<n;v++)
	         if(!used[v])
	               dfs1(v);
	reverse(order.begin(),order.end());
	used.assign(n,false);
	int n_component=0;
	for(auto v:order){
	    if (!used[v]){
	        dfs2(v);
	        int root=component.front();
	        for(auto v:component)roots[v]=root;
	        root_nodes.push_back(root);
	        component.clear();
	    }
	}
	for(int v=0;v<n;v++){
	   for(auto u:adj[v]){
	    int   root_u=roots[u];
	   int root_v=roots[v];
	   if(root_v!=root_u)
	              adj_scc[root_v].push_back(root_u);
	   }
	}
	for(int i=0;i<root_nodes.size();i++)cout<<root_nodes[i]<<" ";
	cout<<endl;
	/*
	we have selected the root of each component as the first node
	in its list. This node will represent its entire SCC in the 
	condensation graph. roots[v] indicates the root node for the SCC
	to which node v belongs. root_nodes is the list of all root nodes
	(one per component) in the condensation graph.

    adj_scc is the adjacency list of the root_nodes.
    We can now traverse on adj_scc as our condensation graph, 
    using only those nodes which belong to root_nodes.
	*/
	
	return 0;
}


