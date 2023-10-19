#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
const int N = 1e5 + 5;
const int INF=1000000000;
struct Edge{
   int a,b,cost;
};
vector<Edge>adj;
int n;
int Bellman_Ford(int s,vector<int>&d,vector<int>&p){
    d.assign(N,INF);
    p.assign(N,-1);
    d[s]=0;
    int x;
    for(int i=0;i<n;i++){
      x=-1;
        for(Edge edge:adj){
         
            if(d[edge.a]<INF){
            if(d[edge.a]+edge.cost<d[edge.b]){
                d[edge.b]=d[edge.a]+edge.cost;
                p[edge.b]=edge.a;
               x=edge.a;
            }
        }
    }
       
    }
    
   return x;//if x is -1 there is no negetive cycle otherewish there is
           //a negative edge from x'th node.
}
vector<int> restore_path(int s,int t,vector<int>&p){
    
    vector<int>path;
    for(int v=t;v!=s;v=p[v])
          path.push_back(v);
    path.push_back(s);
    reverse(path.begin(),path.end());
    return path;
}
vector<int> find_negetive_cycle(int x,vector<int>&p){
    int y=x;
    for(int i=0;i<n;i++)
           y=p[y];
    vector<int>path;
    for (int cur=y;;cur=p[cur])
    {
        path.push_back(cur);
        if(cur==y&&path.size()>1)
                              break;
    }
    reverse(path.begin(),path.end());
    for(int i=0;i<path.size();i++)cout<<path[i]<<" ";
    cout<<endl;
    return path;
}

int32_t main()
{
	IOS;
	cin>>n;int m;cin>>m;
	for(int i=0;i<m;i++){
	    int u,v,wt;
	    cin>>u>>v>>wt;
	    Edge E;
	    E.a=u;
	    E.b=v;
	    E.cost=wt;
	    adj.push_back(E);
	}
   
	vector<int>d,p;
	int x=Bellman_Ford(0,d,p);
	if (x==-1){
	for(int i=0;i<n;i++)cout<<d[i]<<" ";
	cout<<endl;
	vector<int>path=restore_path(0,5,p);
	for(int i=0;i<path.size();i++)cout<<path[i]<<" ";
	cout<<endl;
	}
	else{
	   cout<<"There is a negetive cycle :"<<endl;
	   find_negetive_cycle(x,p);
	}
	return 0;
}


