/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : easy-2.cpp

* Creation Date : 23-12-2013

* Last Modified : Monday 23 December 2013 06:34:14 PM IST

* Created By : npsabari

_._._._._._._._._._._._._._._._._._._._._.*/
#include <iterator>
#include <cctype>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <utility>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <ctime>
#include <climits>
#include <string>

using namespace std;

//Macros
#define dbl double
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair< int, int >
#define psi pair< string, int >
#define vi vector<int>
#define vll vector<ll>

#define abs(x) ((x)<0?-(x):(x))
#define sqr(x) ((x)*(x))

#define MOD 1000000007
#define MAXN 5010
#define MAXBUF 5000000
#define EPS 1e-9
#define NIL 0
#define INF (INT_MAX/2)
#define LLINF (LONG_LONG_MAX/2LL)
#define NEWLINE '\n'

#define SET(A) memset(A, 1,sizeof(A));                     //NOTE: Works only for x = 0 and -1. Only for integers.
#define CLR(A) memset(A, 0,sizeof(A));
#define MEM(A,x) memset(A,x,sizeof(A));
#define CPY(A,B) memcpy(A,B,sizeof(A));

#define SIZE(A) ((int)(A.size()))
#define ALL(x)  x.begin(),x.end()
#define FILL(A,x) fill(ALL(A),x)
#define REP(i,N) for(int i=0;i<(int)(N); ++i)
#define FORab(i,a,b) for(int i=(int)(a);i<=(int)(b); ++i)
#define RFORab(i,a,b) for(int i=(int)(a);i>=(int)(b); --i)
#define FOR1(i,n) FORab(i,1,(n))
#define RFOR1(i,n) RFORab(i,(n),1)
#define FOR(i,n) FORab(i,0,(n)-1)
#define RFOR(i,n) RFORab(i,(n)-1,0)
#define TR(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define SORTV(x) sort(ALL(x))
#define REVV(x) reverse(ALL(x))

#define mp make_pair
#define pb push_back
#define ff first
#define ss second

#define nbits(n) __builtin_popcount(n)                  //NOTE: Works only for int. Write your own function for long long :-/
#define atbit(x,i) (((x)>>(i))&1)
#define FIXMOD(a) (((a)%MOD+MOD)%MOD)

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

// #define debug

char str1[MAXN], str2[MAXN];
int dp[MAXN][MAXN], rev_dp[MAXN][MAXN];

int main() {
    int t;
    int n, m, k;
    int u, v, x, y;
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d", &n, &m, &k);
        scanf("%s%s", str1, str2);
        
        if(k>n || k>m)
        {
            cout<<"-1"<<endl;
            continue;
        
        }
        REP(i, n+2) dp[i][0] = rev_dp[i][0] = rev_dp[i][m+1] = 0;
        REP(j, m+2) dp[0][j] = rev_dp[0][j] = rev_dp[n+1][j] = 0;

        FOR1(i, n) FOR1(j, m)
            dp[i][j] = max(dp[i-1][j-1] + int(str1[i-1] == str2[j-1]), max(dp[i-1][j], dp[i][j-1]));
        RFOR1(i, n) RFOR1(j, m)
            rev_dp[i][j] = max(rev_dp[i+1][j+1] + int(str1[i-1] == str2[j-1]), max(rev_dp[i+1][j], rev_dp[i][j+1]));

#ifdef debug
        int max1_idx, max2_idx;
#endif
        int sol = 0;
        REP(i, n-k+1) REP(j, m-k+1) {
            u = i, v = i+k-1;
            x = j, y = j+k-1;
#ifdef debug
            int tmp_sol = dp[u][x] + rev_dp[v+2][y+2];
            if(tmp_sol > sol){
                max1_idx = i, max2_idx = j;
            }
#endif
            sol = max(sol, dp[u][x] + rev_dp[v+2][y+2]);
        }

#ifdef debug
        cout<<"Maximum is found when removing substring of 1 between ";
        cout<<max1_idx<<","<<(max1_idx+k-1)<<" and substring of 2 between ";
        cout<<max2_idx<<","<<(max2_idx+k-1)<<endl;
#endif
        printf("%d\n", sol);
    }
	return 0;
}
