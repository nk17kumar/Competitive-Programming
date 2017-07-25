#include "bits/stdc++.h"
using namespace std;

typedef vector < int > vec;

vec getSpanMaxi(vec &v) {
	vec span(v.size(),1);
	stack < int > s;
	s.push(0);
	for(int i=1;i<v.size();i++) {
		while(!s.empty() && v[i] >= v[s.top()]) {
			s.pop();
		}
		if(!s.empty())
			span[i] = i - s.top();
		else
			span[i] = i+1;
		s.push(i);
	}
	return span;
}

vec getSpanMini(vec &v) {
    vec span(v.size(),1);
	stack < int > s;
	s.push(0);
	for(int i=1;i<v.size();i++) {
		while(!s.empty() && v[i] <= v[s.top()]) {
			s.pop();
		}
		if(!s.empty())
			span[i] = i - s.top();
		else
			span[i] = i+1;
		s.push(i);
	}
	return span;	
}

int main(int argc, char const *argv[])
{
	int n; cin >> n;
	vec a(n,0);
	for(int i=0;i<n;i++) {
		cin >> a[i];
	}
	vec span = getSpanMaxi(a);
	for(auto val : span) {
		cout << val << " ";
	}
	cout << endl;

	span = getSpanMini(a);
	for(auto val : span) {
		cout << val << " ";
	}
	cout << endl;

	return 0;
}