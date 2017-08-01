#include "bits/stdc++.h"
using namespace std;

class Utility {

	static vector < string > splitString(string &s,char c) {
		vector < string > ret;
		int l = s.length();
		string tmp = "";
		for(int i=0;i<l;i++) {
			if(s[i] == c){
				ret.push_back(tmp);
				tmp = "";
			}
			else
				tmp.push_back(s[i]);
		}
		ret.push_back(tmp);
		return ret;
	}

	static int toInteger(string &s) {
		int ret = 0;
		int l = s.length();
		for(int i=0;i<l;i++) {
			ret = ret*10 + (s[i]-'0');
		}
		return ret;
	}

};

