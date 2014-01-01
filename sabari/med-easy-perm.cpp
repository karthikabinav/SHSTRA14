/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : med-easy-perm.cpp

* Creation Date : 24-12-2013

* Last Modified : Thursday 02 January 2014 01:20:21 AM IST

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

#define MOD 1000000003
#define MAXN 18 
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

#define MASK (1LL<<MAXN)

int adj[MAXN][MAXN];    // Vertices are 0-indexed wrt each partite
int n;  // Each partite has n vertices

ll store[MASK];

// uses Ryser's formula for finding permanent of a matrix
ll get_count() {
    ll tmp, sum;
    int bit_cnt;
    REP(sub_idx, (1LL<<n)){
        store[sub_idx] = 1;
        REP(i, n){
            sum = 0;
            REP(j, n) if(sub_idx & (1LL<<j)) sum = FIXMOD(sum+adj[i][j]);
            store[sub_idx] = FIXMOD(store[sub_idx]*sum); 
        }

        bit_cnt = 0;
        tmp = sub_idx;
        while(tmp) {bit_cnt += (tmp&1); tmp >>= 1;}
        if(bit_cnt&1) store[sub_idx] = FIXMOD(store[sub_idx]*(-1));
    }
    ll sol = 0;
    REP(sub_idx, (1LL<<n)) sol = FIXMOD(sol+store[sub_idx]);
    if(n&1) sol = FIXMOD(sol*(-1));
    return sol;
}

int main() {
    int t, m, u, v;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &n, &m);
        CLR(adj);
        REP(i, m) {scanf("%d%d", &u, &v); adj[u][v-n] = 1;}
        printf("%lld\n", get_count());
    }
	return 0;
}
