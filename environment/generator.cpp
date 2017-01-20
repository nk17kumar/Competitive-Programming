#include "bits/stdc++.h"
using namespace std;

int main(int argc, char const *argv[])
{   
	freopen("input.txt","w",stdout);
	int t = 100;
	cout << t << endl;
	while(t--){
		int n = random();
		cout << n << endl;
		int x;
		for(int i=0;i<n;i++){
			x = random();
			cout << x << " ";
		}
	}
	return 0;
}