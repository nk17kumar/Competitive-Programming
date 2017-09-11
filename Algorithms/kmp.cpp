#include "bits/stdc++.h"
using namespace std;

int lps[100001];

void constructLps(string &s) {
    int l = s.length();
    lps[0] = 0;
    int len = 0;
    int i=1;
    while(i<l) {
        if(s[i] == s[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if(len == 0) {
               lps[i] = len;
                i++;
            }
            else {
                len = lps[len-1];
            }
        }
    }
}

// abababcdd
// bab
// 001

vector < int > match(string &pat,string &txt) {
    int i=0,j=0; 
    constructLps(pat);
    int l = txt.length();
    int m = pat.length();
    vector < int > endPoint;
    while(i < l) {

        if(txt[i] == pat[j]) {
            i++;j++;
        }

        if(j == m) {
            endPoint.push_back(i-1);
            j = lps[j-1];
        }

        if(txt[i] != pat[j]){
            if(j!=0)
                j = lps[j-1];
            else
                i++;
        }
    }
    return endPoint;
}

int main(int argc, char const *argv[])
{
    string pat = "ababc";
    string txt = "abcababcabababc";
    for(auto x : match(pat,txt)) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}