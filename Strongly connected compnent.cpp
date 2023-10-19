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
	        n_component++;
	        dfs2(v);
	        cout<<"The "<<n_component<<" no. connected component is :"<<endl;
	        for(auto a:component)cout<<a<<" ";
	        cout<<endl;
	        component.clear();
	        
	    }
	          
	}
	
	return 0;
}


