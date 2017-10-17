#include "bits/stdc++.h"
using namespace std;

const int sz = 1e5+1;

vector < int > adj[sz];
vector < int > ctree[sz];

bool marked[sz];
int subtree[sz];

int dfs(int cur,int prev) {
    subtree[cur] = 1;
    for(auto x : adj[cur]) {
        if(x!=prev and !marked[x])
            subtree[cur]+=dfs(x,cur);
    }
    return subtree[cur];
}

int getCentroid(int cur,int prev,int sz) {
    for(auto x : adj[cur]) {
        if(x==prev or marked[x]) continue;
        if(subtree[x] > sz/2)
            return getCentroid(x,cur,sz);
        else if(sz&1 and subtree[x]==sz/2)
            return getCentroid(x,cur,sz);
    }
    return cur; 
}

void decompose(int cur,int sz) {
    dfs(cur,0);
    int tcen,cen = getCentroid(cur,0,sz);
    marked[cen] = true;
    for(auto x : adj[cen]) {
        if(marked[x]) continue;
        dfs(x,0);
        tcen = getCentroid(x,cur,subtree[x]);
        marked[tcen] = true;
        decompose(tcen,subtree[x]);
        ctree[cen].push_back(tcen);
        ctree[tcen].push_back(cen);
    }
}

int main(int argc, char const *argv[])
{
    int n; cin >> n;
    int u,v;
    for(int i=0;i<n-1;i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    decompose(1,n);

    for(int i=1;i<=n;i++) {
        for(auto x : adj[i])
            cout << x << " ";
        cout << endl;
    }
    return 0;
}
