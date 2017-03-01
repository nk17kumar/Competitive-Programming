#include "bits/stdc++.h"
using namespace std;
 
int spf[1000001];
bool prime[1000001];
vector <int> fac;
 
void sieve(){
  spf[1]=1;
  for(int i=2;i<=1000000;i++) {
     prime[i]= true;
     spf[i] = i;}
 
  for(int i=4;i<=1000000;i+=2) {
     spf[i] = 2;
     prime[i] = false;
  } 
 
  for(int i=3;i*i<=1000000;i++){
     if(prime[i]){
        for(int j=i*i;j<=1000000;j+=i)
          if(spf[j]==j)
          {
            spf[j] = i;
            prime[j] = false;
          }
     }
  }
}
 
void getfac(int x){
  fac.clear(); int st;
    while(x!=1){
       st = spf[x];
       fac.push_back(st);
       while(x%st == 0){
          x=x/st;
       }
    }
}