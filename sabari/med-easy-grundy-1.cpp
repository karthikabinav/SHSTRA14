/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : med-easy-grundy.cpp

* Creation Date : 23-12-2013

* Last Modified : Tuesday 24 December 2013 12:52:22 AM IST

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
#define MAXN 1010
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

ll c_i[MAXN], P_i[MAXN], C_i[MAXN];;

ll get_grundy(ll num, int idx){
    if(num < idx) return 0;
    if(num%idx == 0) return num/idx;
    else return get_grundy(num-num/idx-1, idx);
}

int main() {
    int t, n;
    ll grundy;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        FOR1(i, n) scanf("%lld", c_i+i);
        FOR1(i, n) scanf("%lld", P_i+i);
        // Transforming to good old n-piles game, with removing coins as action
        FOR1(i, n) {
            assert(P_i[i] >= c_i[i]);
            C_i[i] = P_i[i] - c_i[i];
        }
        
        // Computing XORs
        grundy = 0;
        FOR1(i, n) grundy ^= get_grundy(C_i[i], i);

        //According the Grundy number theorem, iff grundy = 0, it is a losing position
        printf("%s\n", grundy == 0 ? "NO" : "YES");
    }
	return 0;
}
