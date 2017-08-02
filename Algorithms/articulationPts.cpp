#include "bits/stdc++.h"
using namespace std;

#define SZ 1001

vector < int > adj[SZ];
bool isAP[SZ];
int clk;
int par[SZ];
int inTime[SZ];
int backEdge[SZ];
bool visited[SZ];

void dfs(int cur) {
	visited[cur] = true;
	inTime[cur] = backEdge[cur] = clk++;
	int child = 0;
	for(auto x : adj[cur]) {
		if(!visited[x]) {
			child++;
			par[x] = cur;
			dfs(x);
			backEdge[cur] = min(backEdge[cur],backEdge[x]);

			if(par[cur] == -1 and child>1)
				isAP[cur] = true;

			if(par[cur] != -1 and backEdge[x] >= inTime[cur])
				isAP[cur] = true;
		}
		else
		{
			if(x != par[cur])
				backEdge[cur] = min(backEdge[cur],inTime[x]);
		}
	}
}

int main(int argc, char const *argv[])
{
	int n,m;
	cin >> n >> m;
	int u,v;
	
	for(int i=0;i<m;i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	par[0] = -1;
	clk = 1;
	dfs(0);

	for(int i=0;i<n;i++)
		if(isAP[i])
			cout << i << " ";
	cout << endl;
	return 0;
}
