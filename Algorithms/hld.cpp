// My solution for TAQTREE at codechef
#include "bits/stdc++.h"
using namespace std;

#define MAXN 100001

int edgeArr[MAXN];
int nodeArr[MAXN];
int depth[MAXN];

// memset it with -1
int par[MAXN][31];        

int subtree[MAXN];
int chainNum[MAXN];
int chainHead[MAXN];
int posChain[MAXN];
int posArr[MAXN];
int tree[3*MAXN];
int pos[MAXN];
vector < pair < int , pair <int,int> > > adj[MAXN];
int n;
// global parameters used in hld
int chain,ptr;

// filling parent,subtree size,depth
int dfs(int cur,int prev){
    depth[cur] = depth[prev] + 1;
    par[cur][0] = prev;
    subtree[cur] = 1;
    for(auto x:adj[cur]){
    	if(x.second.first!=prev)
    		subtree[cur]+=dfs(x.second.first,cur);
    }
    return subtree[cur];
}

// LCA Dp fill
void dp(){
	for(int l=1;l<=16;l++){
        for(int i=1;i<=n;i++){
        	if(par[i][l-1] != -1)
        		par[i][l] = par[par[i][l-1]][l-1];
        }
	}
}

// get Lca
int lca(int u,int v){
	if(u==v) return u;
	if(depth[u]>depth[v]) swap(u,v);
	int diff = depth[v] - depth[u];
    for(int i=0;i<17;i++){
    	if(diff&(1<<i))
    		v = par[v][i];
    }
    if(u==v) return u;
    for(int i=16;i>=0;i--){
    	if(par[u][i] != par[v][i])
    	{
    		u = par[u][i];
    		v = par[v][i];
    	}
    }
    return par[v][0];
}

// Heavy Light Decomposition
// 1)mark chain head
// 2)mark ptr and chainNUm for curNode
// 3)fill edge data at ptr
// 4)find sc - extend the chain
// 5)create chain for other children
void hld(int curNode,int cost,int prev,int idx){
    if(chainHead[chain]==-1) 
    	chainHead[chain] = curNode;
    
    chainNum[curNode] = chain;
    nodeArr[curNode] = ptr;
    pos[idx] = ptr;
    edgeArr[ptr++] = cost; // edge from parent to curnode
    
    int sc = -1,nextCost,maxi=-1; int fidx;
    for(auto x:adj[curNode]){
    	if(x.second.first!=prev and subtree[x.second.first]>maxi){
    		maxi = subtree[x.second.first];
    		nextCost = x.second.second;
    		sc = x.second.first;
    		fidx = x.first;
    	}
    }

    if(sc!=-1) hld(sc,nextCost,curNode,fidx);

    for(auto x:adj[curNode]){
    	if(x.second.first!=prev and x.second.first!=sc){
    		chain++;
    		hld(x.second.first,x.second.second,curNode,x.first);
    	}
    }

}

// same segtree and shit
void build(int nd,int l,int h){
	if(l==h) tree[nd] = edgeArr[l];
	else{
		int mid = (l+h) >> 1;
		build(nd+nd,l,mid);
		build(nd+nd+1,mid+1,h);
		tree[nd] = tree[nd+nd] + tree[nd+nd+1];
	}
}

void update(int nd,int lo,int hi,int idx,int val){
	if(idx<lo or idx>hi) return;
	if(lo==hi) tree[nd] = val;
	else{
	int mid = (lo+hi) >> 1;
	if(idx<=mid) update(nd+nd,lo,mid,idx,val);
	else update(nd+nd+1,mid+1,hi,idx,val);
	tree[nd] = tree[nd+nd] + tree[nd+nd+1];}
}

int qrr(int nd,int lo,int hi,int l,int r){
	if(l>hi or r<lo or lo>hi) return 0;
	if(l <= lo && hi <= r) return tree[nd];
	int mid = (lo+hi)>>1;
	int p1 = qrr(nd+nd,lo,mid,l,r);
	int p2 = qrr(nd+nd+1,mid+1,hi,l,r);
	return p1+p2;
}


// query up the chain
// 1)make both lie in same chain
//   - query till chain head
// 2)when same chain 
//   - do last query
int qChain(int u,int v){
    if(u==v) return 0;
    int uChain = chainNum[u];
    int vChain = chainNum[v];
    int ans = 0;
    while(uChain!=vChain){
    	ans+=qrr(1,0,ptr,nodeArr[chainHead[uChain]],nodeArr[u]);
    	u = chainHead[uChain];
    	u = par[u][0];
    	uChain = chainNum[u];
    	if(nodeArr[u]==0) break;
    }
    ans+=qrr(1,0,ptr,nodeArr[v]+1,nodeArr[u]);
    return ans;
}

// split query u,v
int query(int u,int v){
	int l = lca(u,v);
	return qChain(u,l) +qChain(v,l);
}

int main(int argc, char const *argv[])
{   
	ios_base :: sync_with_stdio(false);
	memset(par,-1,sizeof(par));
	memset(chainHead,-1,sizeof(chainHead));
	ptr=0;chain=1;
	cin >> n;
	int u,v,x;
	for(int i=0;i<n-1;i++){
		cin >> u >> v >> x;
		adj[u].push_back({i+1,{v,x}});
		adj[v].push_back({i+1,{u,x}});
	}
	depth[0] = -1;	subtree[0] = 0;
	dfs(1,0);
	par[1][0] = -1;
	dp();
        hld(1,0,0,0);
	build(1,0,ptr);
	int q,c; cin >> q;
	while(q--){
		cin >> c >> u >> v;
		if(c==2)
		printf("%d\n",query(u,v));
	    else{
	    	update(1,0,ptr,pos[u],v);
	    }
	}
	return 0;
}
