#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
vector<int>adj[100];
int n;
vector<bool>used(100,false);//for track a vartex is visited or not visited.
vector<int>dist(100),parent(100);
void bfs(int s){//source vertex
    //cout<<s<<endl;
    used[s]=true;
    queue<int>q;
    q.push(s);
    parent[s]=-1;
    dist[s]=0;
    while(!q.empty())
    {
        int par=q.front();
        q.pop();
        for(auto child:adj[par]){
            if(!used[child]){
              // cout<<child<<endl;
                q.push(child);
                used[child]=true;
                dist[child]=dist[par]+1;//distant of child
                parent[child]=par;//storing parent of child.
            }
        }
    }
}
void printing_path(int n){//A sortest  path  from source node to node n.  
    if(used[n]==false){
        cout<<"There is no path "<<endl;
    }
    else{
        vector<int>path;
        for(int v=n;v!=-1;v=parent[v]){
            path.push_back(v);
        }
        reverse(path.begin(),path.end());
        for(int v:path){
            cout<<v<<" ";
        }
    }
}
int32_t main()
{
	IOS;
	int n;
	cin>>n;
	for(int i=0;i<n-1;i++){
	    int u,v;
	    cin>>u>>v;
	    adj[u].push_back(v);
	    adj[v].push_back(u);
	}
	bfs(1);
	printing_path(11);
	return 0;
}

