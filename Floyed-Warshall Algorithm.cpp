#include<bits/stdc++.h>
using namespace std;
const int INF=1e9+10;
const int N=10000;
int dist[N][N];
int Next[N][N]={0};//This 2D array is for retriving shortest path.
void Find_path(int u,int v){
    //Function for printing the sortest path between u and v.
    if(Next[u][v]==-1){
        cout<<"No path exist!"<<endl;
    }
     vector<int>path;
     path.push_back(u);
     while(u!=v){
         u=Next[u][v];
         path .push_back(u);
     }
     for(int i=0;i<path.size();i++)
                          cout<<path[i]<<" ";
     cout<<endl;
 }
int main()
{
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
        {
            if(i==j)dist[i][j]=0;
            else dist[i][j]=INF;
        }
    }
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        dist[u][v]=wt;
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
        {
            //storing the initial next sortest element of each vertex.
            if(dist[i][j]==INF)Next[i][j]=-1;
            else Next[i][j]=j;
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
               if(dist[i][k]!=INF&&dist[k][j]!=INF){
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                    Next[i][j]=Next[i][k];
               }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(dist[i][j]==INF)cout<<"I ";
            else cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    Find_path(1,3);//Printing the sortest path between the node 1 and 3.
    }
    return 0;
}
//If the cost is real number/ floting point.
/*
    if (d[i][k] + d[k][j] < d[i][j] - EPS)//here EPS is the error.
                                        //Which is eccepted for this problem.
    d[i][j] = d[i][k] + d[k][j]; 
*/
