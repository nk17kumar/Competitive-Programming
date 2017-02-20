#include "bits/stdc++.h"
using namespace std;

vector < int > adj[100001];
vector < int > euler;
vector < int > arr;
int pos[100001];
int level[100001];
int ptr,n,m;
#define sz 100001

template < class T >
struct RMQ{
    T arr[sz];
    T dp[sz][18];
    int logn[sz];
    int p2[20];
    
    void build(std::vector<int> &a,int n){
        // initialization
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++)
            {
                arr[i] = a[i];
                if(i) 
                dp[i-1][0] = (arr[i]>arr[i-1])?i-1:i;
            }
        p2[0] = 1;
        
        // precompute
        for(int i=1;i<18;i++) p2[i] = p2[i-1]*2;
        int val = 1,ptr=0;
        for(int i=1;i<sz;i++){
            logn[i] = ptr-1;
            if (val==i){
                val*=2;
                logn[i] = ptr;
                ptr++;
            }
        }

        // building dp
        for(int l=1;l<18;l++)
        for(int i=0;i<n;i++)
         if(dp[i][l-1]!=-1 and dp[i+p2[l-1]][l-1]!=-1)
            dp[i][l] = (arr[dp[i][l-1]]>arr[dp[i+p2[l-1]][l-1]])
                        ?dp[i+p2[l-1]][l-1] : dp[i][l-1];  
         else
            break; 
    }

    T query(int l,int r){
        int d = r-l;
        int dx = logn[d];
        if(l==r) return l;
        if(arr[dp[l][dx]] > arr[dp[r-p2[dx]][dx]])
        	return dp[r-p2[dx]][dx];
        else
        	return dp[l][dx];
    }
};

RMQ < int > lca;

void dfs(int cur,int prev,int dep){
	if(pos[cur]==-1) pos[cur] = ptr;
	level[cur] = dep;
	euler.push_back(cur);
	ptr++;
	for(auto x:adj[cur]){
		if(x!=prev){
			dfs(x,cur,dep+1);
	        euler.push_back(cur);
	        ptr++;
	    }
	}
}

void makeArray(){
   for(auto x : euler)
   	arr.push_back(level[x]);
   lca.build(arr,arr.size());
}

int LCA(int u,int v){
	if(u==v) return u;
	if(pos[u]>pos[v]) swap(u,v);
	return euler[lca.query(pos[u],pos[v])];
}

void input(){
	cin >> n; int x,v;
	for(int i=0;i<=n;i++) adj[i].clear();
	for(int i=1;i<=n;i++){
		cin >> x;
		while(x--){
			cin >> v;
			adj[i].push_back(v);
			adj[v].push_back(i);
		}
	}
}


int main(int argc, char const *argv[])
{   
	ios_base :: sync_with_stdio(false);
	int t,tt=1; cin >> t;
	while(t--){
	input();
	for(int i=0;i<=n;i++) pos[i] = -1;
	ptr = 0;
	euler.clear(); arr.clear();
	dfs(1,0,0);
	makeArray();
    int q; cin >> q;
    printf("Case %d:\n",tt);
    while(q--){
    	int u,v;
    	cin >> u >> v;
    	printf("%d\n",LCA(u,v));
    }tt++;
 }

	return 0;
}