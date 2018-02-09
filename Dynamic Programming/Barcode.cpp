/* with <3
/* by nk17kumar ;)    */
#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector <pii> vpii;
typedef vector <pll> vpll;
typedef vector <ll> vll;
typedef vector <int> vi;

#define _ auto
#define X first
#define Y second
#define pb push_back
#define mp make_pair

const ll mod = 1e9+7;
const int inf = mod;
const ll inff = 1LL<<62;

#define fi() ios_base::sync_with_stdio(0)
#define ou() freopen("out.txt","w",stdout)
#define in() freopen("in.txt","r",stdin)
#define rep(i,a,b) for(int i=a;i<b ;i++)
#define per(i,a,b) for(int i=a;i>=b ;i--)
#define vin(v,n) rep(i,0,n) cin>>v[i];
#define sz(v) (int)v.size()
#define all(v) v.begin(),v.end()

/*global declarations*/

int cst[2][1002];

int m,n,x,y;

char mat[1002][1002];

int dp[1002][2][1002];

int solve(int idx,int clr,int sz) {
	if(idx == n and sz >= x and sz <= y)
		return 0;
	if(idx == n)
		return 1000001;

	int &ret = dp[idx][clr][sz];

	if(ret != 100000001)
		return ret;

	if(sz < y)
		ret = cst[clr][idx] + solve(idx+1,clr,sz+1);

	if(sz >= x) {
		// change
		ret = min(ret,cst[!clr][idx] + solve(idx+1,!clr,1));
	}

	return ret;
}


int main(int argc, char const *argv[]) { fi();
	// in();ou();
	cin >> m >> n >> x >> y;

	for(int i=0;i<m;i++) {
		for(int j=0;j<n;j++)
			cin >> mat[i][j];
	}

	for(int col = 0;col < n;col++) {
    int w = 0;
		for(int r = 0;r<m;r++) {
			if(mat[r][col] == '.')
				w++;
		}
		cst[0][col] = m - w;
		cst[1][col] = w;

	}

	for(int i=0;i<=n+1;i++) {
		for(int j=0;j<=y+1;j++)
		{
			dp[i][0][j] = dp[i][1][j] = 100000001;
		}
	}
	cout << min(solve(0,0,0),solve(0,1,0));
    return 0;
}
