/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : hungarian.cpp

* Creation Date : 02-01-2014

* Last Modified : Thursday 02 January 2014 03:41:42 AM IST

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
#define MAXN 410
#define MAXN 410
#define MAXE (MAXN*MAXN) 
#define MAXBUF 5000000
#define EPS 1e-9
#define NIL 0
#define INF (INT_MAX/2)
#define LLINF 10000000000000LL
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

int MAX_COST = INF;

ll cost[MAXN][MAXN];
int nNode;
int Lmate[MAXN], Rmate[MAXN];
ll uCost[MAXN], vCost[MAXN];
ll dist[MAXN];
int dad[MAXN], seen[MAXN];
int mated;

struct hungarian {
    void construct_dual_sol() {
        REP(i, nNode) {
            uCost[i] = cost[i][0];
            FOR1(j, nNode-1) uCost[i] = min(uCost[i], cost[i][j]);
        }
        REP(j, nNode) {
            vCost[j] = cost[0][j] - uCost[0];
            FOR1(i, nNode-1) vCost[j] = min(vCost[j], cost[i][j] - uCost[i]);
        }
    }

    void construct_primal_sol() {
        MEM(Lmate, -1); MEM(Rmate, -1);
        mated = 0;
        REP(i, nNode) {
            REP(j, nNode) {
                if(Rmate[j] != -1) continue;
                if(cost[i][j] - uCost[i] - vCost[j] == 0) {
                    Lmate[i] = j; Rmate[j] = i; ++mated; break;
                }
            }
        }
    }

    void augment_iter() {
        while(mated < nNode) {
            int s = 0;
            while(Lmate[s] != -1) ++s;
            MEM(dad, -1); CLR(seen);
            REP(i, nNode) dist[i] = cost[s][i] - uCost[s] - vCost[i];

            int j = 0;
            while(true) {
                j = -1;
                REP(k, nNode) {
                    if(seen[k])  continue;
                    if( j == -1 || dist[k] < dist[j] ) j = k;
                }
                seen[j] = 1;

                if(Rmate[j] == -1) break;

                const int i = Rmate[j];
                REP(k, nNode) {
                    if(seen[k]) continue;
                    const ll new_dist = dist[j] + cost[i][k] - uCost[i] - vCost[k];
                    if(dist[k] > new_dist) dist[k] =  new_dist, dad[k] = j;
                }
            }

            REP(k, nNode) {
                if(k == j || !seen[k]) continue;
                const int i = Rmate[k];
                vCost[k] += dist[k] - dist[j];
                uCost[i] -= dist[k] - dist[j];
            }
            uCost[s] += dist[j];

            while(dad[j] >= 0) {
                const int d = dad[j];
                Rmate[j] = Rmate[d];
                Lmate[Rmate[j]] = j;
                j = d;
            }
            Rmate[j] = s;
            Lmate[s] = j;
            ++mated;
        }
    }

    ll get_cost() {
        construct_dual_sol(); construct_primal_sol();
        augment_iter();
        ll ret = 0;
        REP(i, nNode)
            ret += cost[i][Lmate[i]];
        return ret > MAX_COST ? -1 : ret;
    }
};

ll a_arr[MAXE], b_arr[MAXE];
int road_param[MAXN][MAXN];

void construct_graph(int time) {
    REP(i, nNode) REP(j, nNode) cost[i][j] = LLINF;
    int v;
    REP(i, nNode) REP(j, nNode) {
        v = road_param[i][j];
        if(v != -1) cost[i][j] = a_arr[v] + b_arr[v]*time;
    }
}

int main() {
    int T;
    int u, v, co, n, m;
    scanf("%d", &T);
    while(T--) {
        scanf("%d %d %d", &n, &m, &MAX_COST);
        nNode = n;
        REP(i, m) {scanf("%d %d %lld %lld", &u, &v, a_arr+i, b_arr+i); road_param[u-1][v-1] = i;}

        int hi = 1000000;
        int lo = 0;
        int m1, m2; int iter = 25;

        ll maxcost = -1;
        int maxTime = -1;
        hungarian G;
        
        // ternary search
        while(lo < hi && iter--){
            m1 = lo+(hi-lo)/3; m2 = hi-(hi-lo)/3;
            construct_graph(m1); ll cost1 = G.get_cost();
            construct_graph(m2); ll cost2 = G.get_cost();
            if(maxcost < cost1 && cost1 > 0) {maxcost = cost1; maxTime = m1;}
            if(maxcost < cost2 && cost1 > 0) {maxcost = cost2; maxTime = m2;}

            if(cost1 < cost2)
                lo = m1;
            else hi = m2;
        }
        construct_graph(min(lo, hi)); ll cost1 = G.get_cost(); 
        construct_graph(max(lo, hi)); ll cost2 = G.get_cost();
        if(maxcost < cost1 && cost1 > 0) {maxcost = cost1; maxTime = min(lo, hi);}
        if(maxcost < cost2 && cost2 > 0) {maxcost = cost2; maxTime = max(lo, hi);}

        if(maxcost <= 0) printf("%lld %d\n", maxcost, maxTime);
        else printf("-1\n");
    }
	return 0;
}
