#include <bits/stdc++.h>
#include<unordered_map>
#include<vector>
#include<stack>
void toposort(int node,stack<int>&st,unordered_map<int,list<int>>&adj,vector<bool>&vis)
{
    vis[node]=true;
    for(auto child:adj[node]){
        if(!vis[child])toposort(child,st,adj,vis);
    }
    st.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    unordered_map<int,list<int>>adj;
    for(int i=0;i<e;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
    }
    vector<int>ans;
    stack<int>st;
    vector<bool>vis(v,0);
    for(int i=0;i<v;i++){
        if(!vis[i])toposort(i,st,adj,vis);
    }
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}
