/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : med-easy-grundy.cpp

* Creation Date : 23-12-2013

* Last Modified : Saturday 04 January 2014 03:40:30 PM IST

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
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <ctime>
#include <climits>
#include <string>
#include <iostream>

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
#define MAXN 10010
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

ll c_i[MAXN], P_i[MAXN], C_i[MAXN], grundy_store[MAXN];
int MOD_FLOOR = 4;

int main() {
    int t, n;
    ll num, prev;
    int cnt;
    ll sol;
    int idx;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &n, &MOD_FLOOR);
        FOR1(i, n) scanf("%lld", c_i+i);
        FOR1(i, n) scanf("%lld", P_i+i);
       // Transforming to good old n-piles game, with removing coins as action
        FOR1(i, n) {
            C_i[i] = P_i[i] - c_i[i];
        }
        
        CLR(grundy_store);

        // Computing XORs
        FOR1(i, n) {
            num = C_i[i];
            idx = (i-1)%MOD_FLOOR+1;
            if(num < idx) continue;
            while(num >= idx) {
                if(num%idx == 0) {grundy_store[i] = num/idx; break;}
                num = num-num/idx-1;
            }
        }
        
        //According the Grundy number theorem, iff grundy = 0, it is a losing position

        FOR1(i, n) grundy_store[i] ^= grundy_store[i-1];
        sort(grundy_store, grundy_store+n+1);

        grundy_store[n+1] = grundy_store[n]+1;

        sol = n*(ll)(n+1)/2; prev = -1; cnt = 0;

        REP(i, n+2) {
            if(prev == grundy_store[i]) cnt++;
            else {sol -= cnt*(ll)(cnt-1)/2; cnt = 1;}
            prev = grundy_store[i];
        }

        // Print number of i, j such that player 1 will win
        printf("%lld\n", sol);
    }
	return 0;
}
