//In this algorithm if we don't use the whole code where we use
//the used1 array. It will still work correctly but this code improve the 
//time complexity  a little bit.
#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
const int N = 1e5 + 10;
const int INF=1000000000;
int n,m;//Here n is number of vartex at first part.
       //m is number of vartex at second part.
vector<int>mt;
vector<int>used;
vector<vector<int>>adj;
 bool try_kuhn(int v){
        if(used[v])
               return false;
   
        used[v]=true;
        for(int to:adj[v]){
            
            if(mt[to]==-1||try_kuhn(mt[to])){
                
                mt[to]=v;
                return true;
            }
        }
        return false;
        
}
int32_t main()
{
    cin>>n>>m;
    adj.assign(n,vector<int>());
    for(int i=0;i<n;i++){
        int u,v;
        cin>>u>>v;
       adj[u].push_back(v);
    }
     vector<bool>used1(n,false);
	   mt.assign(m,-1);
	   for(int v=0;v<n;v++){
	       for(int to:adj[v]){
	           if(mt[to]==-1){
	               mt[to]=v;
	               used1[v]=true;
	               break;
	           }
	       }
	   }
	   for(int v=0;v<n;v++){
	       if(used1[v])
	               continue;            
	       used.assign(n,false);
	       try_kuhn(v);
	   }
	   int count =0;
	   
	   for(int i=0;i<m;i++){
	   if(mt[i]!=-1){
	       cout<<mt[i]+1<<" "<<i+1<<endl;//If 0 based
	       }
	   }
	return 0;
}


