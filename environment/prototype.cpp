/*     _    _ _____ _                               
 _ __ | | _/ |___  | | ___   _ _ __ ___   __ _ _ __ 
| '_ \| |/ / |  / /| |/ / | | | '_ ` _ \ / _` | '__|
| | | |   /| | / / |   /| |_| | | | | | | (_| | |   
|_| |_|_|\_\_|/_/  |_|\_\\__,_|_| |_| |_|\__,_|_|   

 #my awesome codes ;)
*/
  
#include "bits/stdc++.h"
using namespace std;
 
// my competitive tools

#define rep(i,a,b)                for(int i=a;i<b;++i)
#define per(i,a,b)                for(int i=a;i>=b;--i)
#define each(it,a)                for(auto it = a.begin();it != a.end();++it)
#define all(a)                    (a.begin(),a.end())
#define fill(a)                   memset(a,0,sizeof(a))
#define arrin(a,size)             for(int i=0;i<size;++i) cin >> a[i];
#define print(x)                  printf("%lld\n",(long long)x);
#define fastinput()               ios_base :: sync_with_stdio(false);
#define rocknroll()               int t; cin >> t; while(t--) 
#define input()                   freopen("input.txt","r",stdin)
#define output()                  freopen("output.txt","w",stdout)
#define inchar                    getchar_unlocked
#define sz(a)                     (int)a.size()
#define pb                        push_back
#define mp                        make_pair
#define ull                       unsigned long long
#define ll                        long long
#define mod                       1000000007
#define inf                       INT_MAX
#define inff                      LLONG_MAX
#define X                         first
#define Y                         second
/*-----------------------------------------------------------------------------------------------------------------------------------------------*/ 
double tick_tock(){ static clock_t oldtick;clock_t newtick=clock();
                  double diff = 1.0*(newtick-oldtick)/CLOCKS_PER_SEC;
                  oldtick = newtick;return diff;
              }
template <typename T> void inPos(T &x)
              {     x=0;register T c=inchar();while(((c<48)||(c>57))&&(c!='-'))c=inchar();
                    bool neg=false;if(c=='-')neg=true;for(;c<48||c>57;c=inchar());
                    for(;c>47&&c<58;c=inchar())x=(x<<3)+(x<<1)+(c&15);if(neg)x=-x;
                }
/*----------------------------------------------------------------------------------------------------------------------------------------------*/


int main(int argc, char const *argv[])
{   
  fastinput();
    rocknroll()
    { 
      

    

    }
  //printf("%lf\n",tick_tock());
  return 0;
}


