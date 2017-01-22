#include "bits/stdc++.h"
using namespace std;

// right to left greater span
vector <int> stockspan(int* a,int n){
	stack < int > s;
	vector < int > ret;
	ret.push_back(1);
	s.push(0);
    for(int i=1;i<n;i++){
        while(!s.empty() and a[i] > a[s.top()]){
        	s.pop();
        }
        if(!s.empty()){
        	ret.push_back(i - s.top());
        	s.push(i); 
        }else{
        	ret.push_back(i+1);
        	s.push(i);
        }
    }
    return ret;
}

int main(int argc, char const *argv[])
{
     int n; cin >> n;
     int arr[n];
     for(int i=0;i<n;i++) cin >> arr[i];
     for(auto x : stockspan(arr,n)){
     	cout << x << " ";
     }
	return 0;
}
