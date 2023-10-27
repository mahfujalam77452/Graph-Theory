//Note: This program is for vertex starting from 0.
#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
const int N = 1e5 + 5;
const int INF=1000000000;

int32_t main()
{
	IOS;
	int n,m;
	cin>>n>>m;//n->number of vertex,m->number of edge.
	vector<vector<int>>g(n,vector<int>(n,0));
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g[u][v]++;
        g[v][u]++;
    }
    vector<int>deg(n,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            deg[i]+=g[i][j];//computing the degree of each vartex.
        }
    }
    int first=0;
    while(first<n&&deg[first]==0)
                            first++;
    if(first==n){
        cout<<"No Euler path or cycle\n";
        return 0;
    }
    int v1=-1,v2=-1;
    bool bad =false;
    for( int i=0;i<n;i++){
        if(deg[i]&1){
            if(v1==-1)
                  v1=i;
            else if(v2==-1)
                  v2=i;
            else 
                  bad=true;//No Euler path or cycle.
        }
    }
    if(v1!=-1){//If the graph had odd degree.
        g[v1][v2]++;//Add an edge between v1 and v2.
        g[v2][v1]++;//Now it is a Euler cycle instead of Euler path only.
    }
    stack<int>st;
    st.push(first);
    vector<int>res;
    while(!st.empty()){
        int v=st.top();
        int i;
        for( i=0;i<n;i++){
            if(g[v][i])
                 break;
        }
        if(i==n){//if the vectex v has 0 degree..
            res.push_back(v);
            st.pop();
        }
        else{
            //removing the edge.
            --g[v][i];
            --g[i][v];
            st.push(i);
        }
    }
    cout<<endl;
    if(v1!=-1){//If we add an extra edge
       for(int i=0;i+1<res.size();i++){
           if((res[i]==v1&&res[i+1]==v2)||(res[i]==v2&&res[i+1]==v1)){
               //If so. here we add the extra edge.
               vector<int>res2;
               for(int j=i+1;j<res.size();j++)
                                        res2.push_back(res[j]);
               for(int j=1;j<=i;j++)
                                   res2.push_back(res[j]);
               //We do this task because in a Euler path the odd degree's
               //vartex will be the first and last vartex.
               //Start from 1 because the res[0]and res[res.size()-1] was
               //the same element as it was a cycle and first=res[0].
               res=res2;
               break;
           }
       }
        
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(g[i][j])
                  bad=true;//If there is another connected component
                           //with at least 1 edge.
        }
    }
    if(bad)
          cout<<"The graph has no Euler path or circle"<<endl;
    else
        for(int x:res)
                cout<<x<<" ";
        
	return 0;
}



