#include "bits/stdc++.h"
using namespace std;

#define SZ 1001

int	residualGraph[SZ][SZ];
int flowGraph[SZ][SZ]; 
int parent[SZ],n,m;
bool visited[SZ];

bool bfs(int src,int sink) {
	visited[src] = true;
	queue < int > q;
	q.push(src);
	while(!q.empty()) {
		int curr = q.front();
		if(curr == sink)
			break;
		q.pop();

		for(int i=0;i<n;i++) {
			if(residualGraph[curr][i] and !visited[i]){
				parent[i] = curr;
				visited[i] = true;
				q.push(i);
			}
		}
	}
	return visited[sink];
}


int maxFlow(int src,int sink) {
	
	memset(parent,-1,sizeof(parent));
	memset(visited,false,sizeof(visited));

	int ret = 0,bottleNeck = INT_MAX,
	tSink,sz;
	while(bfs(src,sink)) {
		tSink = sink;
		vector < int > augmentedPath;
		
		while(tSink != -1) {
			augmentedPath.emplace_back(tSink);
			if(tSink != src)
				bottleNeck = min(bottleNeck,residualGraph[parent[tSink]][tSink]);
			tSink = parent[tSink];
		}

		sz = augmentedPath.size();
		
		for(int i=sz-1;i>0;i--) {
			residualGraph[augmentedPath[i]][augmentedPath[i-1]] -= bottleNeck;
			residualGraph[augmentedPath[i-1]][augmentedPath[i]] += bottleNeck;
	}
		
		memset(parent,-1,sizeof(parent));
		memset(visited,false,sizeof(visited));

		ret += bottleNeck;
	}

	return ret;
}

int main(int argc, char const *argv[])
{
	cin >> n >> m;
	memset(residualGraph,0,sizeof(residualGraph));

	int u,v,x;
	for(int i=0;i<m;i++) {
		cin >> u >> v >> x;
		residualGraph[u][v] = x;
	}

	int src,sink;

	parent[src] = -1;
	cin >> src >> sink;

	cout << maxFlow(src,sink) << endl;

	return 0;
}


