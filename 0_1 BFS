//Implementation of 0-1 BFS algorithm using dequeue.
//It is a faster algorithm for finding shortest path.Even O(M).
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
bool BFS_0_1(int s,vector<int>&d){
    d.assign(N,INF);
    d[s]=0;
    deque<int>q;
    q.push_front(s);
    while(!q.empty()){
      int v=q.front();
       q.pop_front();
       for(auto edge:adj[v]){
           int to=edge.first;
           int cost=edge.second;
           if(d[v]+cost<d[to]){
               d[to]=d[v]+cost;
              if(cost==1){
                  q.push_back(to);
              }
              else {
                  q.push_front(to);
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
	BFS_0_1(0,d);
	for(int i=0;i<n;i++)cout<<d[i]<<" ";
	cout<<endl;
	return 0;
}

