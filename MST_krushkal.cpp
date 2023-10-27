#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int parent[N];
int size[N];
void make_set(int node){
       parent[node]=node;
       size[node]=1;
}
int find_parent(int node){
  if(parent[node]==node)
             return parent[node];
   return parent[node]=find_parent(parent[node]);
}
void Union_set(int u,int v){
        int a=find_parent(u);
        int b=find_parent(v);
  if(a!=b){
      if(size[a]<size[b])
                  swap(a,b);
      parent[b]=a;
      size[a]+=size[b];
   }
}
int main()
{
     int n,a;
     cin>>n>>a;
     vector<pair<int,pair<int ,int>>>adj;
     for(int i=0;i<a;i++){
          int u,v,w;
          cin>>u>>v>>w;
          adj.push_back({w,{u,v}});
     }
    sort(adj.begin(),adj.end());
    for(int i=1;i<=n;i++)
                 make_set(i);
    int total_cost=0;
   for(auto &it:adj){
      int wt=it.first;
      int u=it.second.first;
      int v=it.second.second;
      if(find_parent(u)==find_parent(v))
                    continue;
      Union_set(u,v);
      total_cost+=wt;
      cout<<u<<" "<<v<<" "<<wt<<endl;
  }
   cout<<total_cost<<endl;

   return 0;
}
