#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> order_set; // find_by_order, order_of_key
template <typename T>
using order_multiset = __gnu_pbds::tree<T, __gnu_pbds::null_type, std::less_equal<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;;
//kthElement = *myTree.find_by_order(1), index(zero based) = myTree.order_of_key(8);
//order_multiset<int>st;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
//#define int long long
const int N = 1e4 + 10;
const int M=1e9+7;
int in[N];
vector<int>adj[N];
void topoSort ( int n,  vector<int>& ans){
    priority_queue<int>pq;
    for(int i = 1;i<=n; i++) 
    if( in[i] == 0 )
    pq.push(i);
    while(!pq.empty()){
        int child = pq.top();
        pq.pop();
        ans.push_back(child);
        if (adj[child].size()!= 0)for (int cld : adj[child]){
            in[cld]--;
            if(in[cld] == 0){
                pq.push(cld);
            }
        }
        
    }
}
int32_t main()
{
   
     IOS
     
         for(int i=1;i<N;i++){
             in[i]=0;
             adj[i].clear();
             
         }
         int n,m;
         cin>>n>>m;
         for(int i=0;i<m;i++){
             int a,b;cin>>a>>b;
             adj[a].push_back(b);
             in[b]++;
         }
         vector<int>ans ;
         topoSort(n,ans);
         bool  ok = true;
         for(int i = 1;i<=n;i++) if( in[i] != 0)ok=false;
         if(ok){
             
             for(int i  = 0 ;i< ans.size() ; i++){
                 cout<<ans[i]<<' ';
             }
             cout<<endl;
         }
         else cout<<"Impossible\n";
         
        
    
	return 0;
}



















