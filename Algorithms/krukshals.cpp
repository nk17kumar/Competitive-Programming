#include "bits/stdc++.h"
using namespace std;

#define X first
#define Y second
const int MAXN = 1e5;
#define piii pair < int,pair < int,int > > 

vector < piii > edges;

int par[MAXN];
int sz[MAXN];

int find(int x) {
    while(x!=par[x]) {
        par[x] = par[par[x]];
        x = par[x];
    }
    return x;
}

void dsUnion(int a,int b) {
    int pa = find(a);
    int pb = find(b);
    if(sz[pa] < sz[pb]) {
        sz[pa]+=sz[pb];
        par[pb] = pa;
    }
    else {
        sz[pb]+=sz[a];
        par[pa]=pb;
    }
}

int krukshal(int n) {

    for(int i=0;i<=n;i++) {
        sz[i] = 1;
        par[i] = i;
    }

    int ret = 0;

    sort(edges.begin(),edges.end());

    for(int i=0;i<edges.size();i++) {
        if(find(edges[i].Y.X) != find(edges[i].Y.Y)) {
            dsUnion(edges[i].Y.X,edges[i].Y.Y);
            ret+=edges[i].X;
        }
    }
    return ret;
}

int main(int argc, char const *argv[])
{
    int n,e,cst;
    int u,v;
    cin >> n >> e;

    for(int i=0;i<e;i++) {
        cin >> u >> v >> cst;
        edges.push_back({cst,{u,v}});
    }

    cout << krukshal(n) << "\n";

    return 0;
}