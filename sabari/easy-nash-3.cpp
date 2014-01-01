/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : easy-nash-3.cpp

* Creation Date : 24-12-2013

* Last Modified : Wednesday 01 January 2014 02:19:04 PM IST

* Created By : npsabari

_._._._._._._._._._._._._._._._._._._._._.*/

#include <iterator>
#include <cctype>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <climits>
#include <limits>
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
#define MAXN 305 
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

/*
 * For each action of a player, find the best response by the other player
 * If a particular action profile is the best response for both the players, then that is nash equilibrium
 */

int n, m;   // n - cardinality of action set for player1, m - for player2
ll pay_off[2][MAXN][MAXN];
bool best_response[2][MAXN][MAXN]; 
// best_response[i][j][k] is true when player i player jth move and other player kth move and both are their correcsponding best responses

ll powe(ll _a, int b, int M){
    ll a = _a%M;
    ll ret = 1LL;
    while(b){
        if(b&1) ret = (a*ret)%M;
        b >>= 1;
        a = (a*a)%M;
    }
    return ret;
}

int main() {
    int t;
    ll a1, a2, b1, b2;
    int M;
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);
        scanf("%lld%lld%lld%lld%d", &a1, &a2, &b1, &b2, &M);

        FOR1(i, n) FOR1(j, m) pay_off[0][i-1][j-1] = powe(a1*i + a2*j, M-2, M);
        FOR1(i, m) FOR1(j, n) pay_off[1][i-1][j-1] = powe(b1*i + b2*j, M-2, M);
        
        REP(i, n) {
            ll maxi = pay_off[0][i][0];
            REP(j, m) maxi = max(pay_off[0][i][j], maxi);
            REP(j, m) best_response[0][i][j] = (maxi == pay_off[0][i][j]);
        }
        REP(i, m) {
            ll maxi = pay_off[1][i][0];
            REP(j, n) maxi = max(pay_off[1][i][j], maxi);
            REP(j, n) best_response[1][i][j] = (maxi == pay_off[1][i][j]);
        }

        bool iflag = false;
        int sol_idx1, sol_idx2;
        REP(i, n) {
            REP(j, m) 
                if(best_response[0][i][j] && best_response[1][j][i]){
                    iflag = true;
                    sol_idx1 = i, sol_idx2 = j;
                    break;
                }
            if(iflag) break;
        }
        if(iflag) printf("%d %d\n", sol_idx1+1, sol_idx2+1);
        else printf("-1\n");
    }
	return 0;
}
