/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : easy-1.cpp

* Creation Date : 23-12-2013

* Last Modified : Tuesday 24 December 2013 11:50:05 AM IST

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
#define MAXN 100010
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

#define MAXL 1000000000000000000LL // Check for overflow
#define debug

ll pow(ll a, int k) {
    ll ret = 1;
    ll aa = a;
    while(k) {
        if(k&1) ret *= a;
#ifdef debug
        if(a > MAXL || a < 0) assert(false);
#endif
        k >>= 1; a *= a;
    }
    return ret;
}

bool a_check(ll& num, int& b) {
    ll hi = pow(2, ceil(log2(num)/b)), lo = 2;
    ll m = (hi+lo)>>1;
    int iter = 35;
    ll tmp_pow;
    while(iter-- && lo < hi) {
        m = (lo+hi)>>1;
        tmp_pow = pow(m, b);
        if(tmp_pow == num) return true;
        if(tmp_pow > 0 && tmp_pow < num) lo = m;
        else hi = m;
    }
    return pow(lo, b) == num || pow(hi, b) == num;
}

bool a_b_check(ll& num) {
    int end = log2(num) + 1;
    FORab(b, 2, end) if(a_check(num, b)) return true;
    return false;
}

int main() {
    int t;
    ll n;
    scanf("%d", &t);
    while(t--) {
        scanf("%lld", &n);
        printf("%s\n", a_b_check(n) ? "YES" : "NO");
    }
	return 0;
}
