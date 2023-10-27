//Implementation of SPFA algorithm using queue.
//It is a faster algorithm for finding shortest path.Even O(M).
//But there can ba some case where the worst time complexity is O(MN).
//NOTE: These code are designed for node starting from 0.
#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
const int N = 1e5 + 5;
const int INF=1000000000;
vector<pair<int,int>>adj[N];
int n;
bool SPFA(int s,vector<int>&d){
    d.assign(N,INF);
    vector<int>count(N,0);
    d[s]=0;
    vector<bool>inqueue(N,false);
    queue<int>q;
    q.push(s);
    inqueue[s]=true;
    while(!q.empty()){
      int v=q.front();
       q.pop();
       inqueue[v]=false;
       for(auto edge:adj[v]){
           int to=edge.first;
           int cost=edge.second;
           if(d[v]+cost<d[to]){
               d[to]=d[v]+cost;
               if(!inqueue[to]){
                   q.push(to);
                   count[to]++;
                   inqueue[to]=true;
                   if(count[to]>n){
                       return false;//negative cycle
                   }
               }
           }
       }
    }
    return true;
}

int32_t main()
{
	IOS;
	cin>>n;int m;cin>>m;
	for(int i=0;i<m;i++){
	    int u,v,wt;
	    cin>>u>>v>>wt;
	    adj[u].push_back({v,wt});
	}
	vector<int>d;
	if(SPFA(0,d)){
	for(int i=0;i<n;i++)cout<<d[i]<<" ";
	cout<<endl;}
	else cout<<"Negative cycle exist !"<<endl;
	
	return 0;
}

