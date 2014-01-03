/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : hungarian.cpp

* Creation Date : 02-01-2014

* Last Modified : Friday 03 January 2014 04:10:36 PM IST

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
#define MAXE (MAXN*MAXN) 
#define MAXBUF 5000000
#define EPS 1e-9
#define NIL 0
#define INF (INT_MAX/2)
#define LLINF 100000000000000LL
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

#define MAX MAXN

vector< int > G[MAX];
int N, M, match[MAX], dist[MAX];                
// n : Number of nodes on the left side ; m : on the right side ; e : connections between them
// graph = NIL[0] U G1[G[1...n]] U G2[G[n+1...n+m]]

bool bfs(){
    int i, u, v, len;
    queue<int> pq;
    for( i = 1; i <= N; ++i){
        if( match[i] == NIL)
            dist[i] = 0, pq.push(i);
        else
            dist[i] = INF;
    }
    dist[NIL] = INF;
    while(!pq.empty()){
        u = pq.front();
        pq.pop();
        if( u != NIL ){
            len = G[u].size();
            for( i = 0; i < len; ++i){
                v = G[u][i];
                if( dist[match[v]] == INF)
                    dist[match[v]] = dist[u]+1, pq.push(match[v]);
            }
        }
    }
    return (dist[NIL] != INF);
}

bool dfs(int u){
    int i, v, len;
    if( u != NIL){
        len = G[u].size();
        for( i = 0; i < len; ++i){
            v = G[u][i];
            if(dist[match[v]] == dist[u]+1 && dfs(match[v])){
                match[v] = u;
                match[u] = v;
                return true;
            }
        }
        dist[u] = INF;
        return false;
    }
    return true;
}

int hopcroft_karp(){
    memset(dist, 0, sizeof(dist));
    memset(match, 0, sizeof(match));
    int i, matching = 0;
    while( bfs() )
        for( i = 1; i <= N; ++i)
            if( match[i] == NIL && dfs(i))
                ++matching;
    return matching;
}

ll a_arr[MAXE], b_arr[MAXE], c_arr[MAXE], d_arr[MAXE];
int road_param[MAXN][MAXN];

void construct_graph(int time) {
    int nNode = N+M+1;
    REP(i, nNode) G[i].clear();
    int v;
    REP(i, N) REP(j, N) {
        v = road_param[i][j];
        if(v != -1 && a_arr[v]+b_arr[v]*time >= 0) G[i+1].pb(j+N+1);
    }
}

#define MAXTIME 1000000000

int matches[MAXN];

ll get_cost(int time) {
    ll to_ret = 0;
    int v;
    ll cost;
    REP(i, N) {
        assert(matches[i] >= 0);
        v = road_param[i][matches[i]];
        cost = c_arr[v] + d_arr[v]*time;
        to_ret += (cost > 0 ? cost : 0);
    }
    return to_ret;
}

int main() {
    int T;
    int u, v, co, n, m, K;
    scanf("%d", &T);
    while(T--) {
        MEM(road_param, -1);
        scanf("%d %d %d", &n, &m, &K);
        N = M = n;
        REP(i, m) {
            scanf("%d%d%lld%lld%lld%lld", &u, &v, a_arr+i, b_arr+i, c_arr+i, d_arr+i); 
            road_param[u-1][v-1] = i;
        }

        int hi = MAXTIME;
        int lo = 0;
        int mi; int iter = 35;
        ll cost1;
        
        int sol = INF;

        // binary search
        while(lo <= hi){
            mi = (lo+hi)>>1;
            construct_graph(mi); cost1 = hopcroft_karp();
            if(cost1 == n) {hi = mi-1; sol = min(mi, sol);}
            else lo = mi+1;
        }

        if(sol == INF) {printf("-1\n"); continue;}

        construct_graph(sol);assert(hopcroft_karp() == n);
        REP(i, n) matches[i] = match[i+1] - N-1;
        /* 
        REP(i, n) {
            cout<<"Match for "<<i<<" is "<<matches[i]<<endl;
        }*/

        lo = sol;
        hi = MAXTIME;
        ll maxcost = -1;
        int maxTime = INF;

        // Binary search for cost
        while(lo <= hi){
            mi = (lo+hi)>>1;
            cost1 = get_cost(mi-sol);
            if(cost1 <= K) {
                hi = mi-1; 
                if(maxcost < cost1 || (maxcost == cost1 && maxTime > mi)){ 
                    maxcost = cost1; maxTime = mi;
                }
            }
            else lo = mi+1;
        }
        if(maxcost <= 0) {printf("-1\n"); continue;}

        assert(maxcost != -1 && maxTime != -1 && sol != INF);
        printf("%d %lld %d\n", sol, maxcost, maxTime);
    }
	return 0;
}
