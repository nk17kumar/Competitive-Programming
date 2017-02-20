#include "bits/stdc++.h"
using namespace std;

#define sz 10001

template < class T >
struct RMQ{
	T arr[sz];
	T dp[sz][18];
	int logn[sz];
	int p2[20];
	
	void build(T *a,int n){
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
	}

	T query(int l,int r){
		int d = r-l;
		int dx = logn[d];
		if(l==r) return arr[l];
     	return arr[min(dp[l][dx],dp[r-p2[dx]][dx])];
	}
};



int main(int argc, char const *argv[])
{   
	int n; cin >> n;
	int arr[n];
	for(int i=0;i<n;i++) cin >> arr[i];
	RMQ < int > ob;
    ob.build(arr,n);
    int q; cin >> q;
    while(q--){
    	int l,r; cin >> l >> r;
    	cout << ob.query(l,r) << endl;
    }
	return 0;
}

