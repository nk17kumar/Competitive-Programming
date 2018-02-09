// problem : Martian
// dynamic programming

#include "bits/stdc++.h"
using namespace std;

int A[501][501];
int B[501][501];
int row[501][501];
int col[501][501];
int dp[501][501];

int rowsum(int r,int c) {
    return row[r][c];
}

int colsum(int r,int c) {
    return col[r][c];
}

int main(int argc, char const *argv[]) {
    ios_base :: sync_with_stdio(false);
    while(true) {
        int n,m;
        cin >> n >> m;
        if(n+m==0)
            break;
        memset(row,0,sizeof(row));
        memset(col,0,sizeof(col));
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                cin >> A[i][j];
                row[i][j]+=row[i][j-1] + A[i][j];
            }
        }
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                cin >> B[i][j];
                col[i][j]+=col[i-1][j] + B[i][j];
            }
        }
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                dp[i][j] = max(dp[i-1][j]+rowsum(i,j),dp[i][j-1]+colsum(i,j));
            }
        }
        cout << dp[n][m] << "\n";
    }
    return 0;
}
