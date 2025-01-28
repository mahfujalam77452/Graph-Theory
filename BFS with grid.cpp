#define valid(tx,ty) tx>=0 and tx<row and ty>=0 and ty<col and cell[tx][ty]!=-1 and vis[tx][ty]==0
int fx[]={1,-1,0,0};//direction array ;
int fy[]={0,0,1,-1};//it is used here while we are able to move in 4 direction.
//for 8 direction we can use this direction array.
/*
int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
*/
int cell[100][100];//if Cell[x][y]==-1 .this means this cell is bolcked.
int dist[100][100];
bool visi[100][100];
int raw,col;

void bfs(int sx,int sy){//source vertext (x,y);
memset(visi,0,sizeof(visi));

    visi[sx][sy]=1;
    dist[sx][sy]=0;
    queue<pair<int,int>>q;
    q.push({sx,sy});
    while(!q.empty())
    {
        auto t=q.front();
        q.pop();
        for(int i=0;i<4;i++){//this code will fun till 8 if were use 8 direction.
            int tx=t.first+fx[i];
            int ty=t.second+fy[i];
            if(valid(tx,ty)){
                visi[tx][ty]=1;
                dist[tx][ty]=dist[t.first][t.second]+1;
                q.push({tx,ty});
            }
        }
    }
}
