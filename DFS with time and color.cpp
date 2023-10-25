const int N = 1e5 + 5;
vector<int>adj[N] ;
vector<bool>visited(N);
void dfs(int parent){
   // cout<<parent<<" ";
    visited[parent]=true;
    for(auto child:adj[parent]){
        if(!visited[child]){
            dfs(child);
        }
    }
}
/*
This is the most simple implementation of DFS. It might be useful to also
compute the entry and exit times and vertex color. We will color all vertices
with the color 0.if we haven't visited them, with the color 1 if we visited them
and with the color 2 if we already exited them.
*/
const int N = 1e5 + 5;
vector<int>adj[N] ;
vector<int>color(N,0);
vector<int>time_in(N),time_out(N);
int dfs_timer=0;
void dfs(int parent){
   //cout<<parent<<" ";
    color[parent]=1;
    time_in[parent]=dfs_timer++;
    for(auto child:adj[parent]){
        if(color[child]==0){
            dfs(child);
        }
    }
    color[parent]=2;
    time_out[parent]=dfs_timer++;
}
