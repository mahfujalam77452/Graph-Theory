/*
There exists a theorem which claims that a graph is bipartite 
if and only if all its cycles have even length. However, 
in practice it's more convenient to use a different formulation
of the definition: a graph is bipartite if and only if 
it is two-colorable.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    bool dfs(int node,bool color,int colored[],vector<int>adj[] ){
        colored[node]=color;
        for(int child:adj[node]){
            //We don't check here the the parent node this node is already
            //different color.
            if(colored[child]==-1){
                if(dfs(child,!color,colored,adj)==false){
                    return false;
                }
            }
            else if(colored[child]==color)//If a visited node has already same color.
                                    return false;
        }
        return true;
    }
public:
	bool isBipartite(int V, vector<int>adj[]){
	  
	    int colored[V];
	    for(int i=0;i<V;i++)colored[i]=-1;
	    for(int i=0;i<V;i++){
	        if(colored[i]==-1){
	            //Checking for each component.
	        if(dfs(i,0,colored,adj)==false)
	                                  return false;
	        }
	    }
	    
	    return true;
	}

};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
