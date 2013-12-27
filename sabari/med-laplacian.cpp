/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : med-laplacian.cpp

* Creation Date : 27-12-2013

* Last Modified : Friday 27 December 2013 03:20:55 PM IST

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

vi adj[MAXN];
int vis[MAXN];
int label[MAXN];
int n, m;

/*
 * Properties: 
 * Second smallest eigen value of laplacian matrix is 0 iff the graph in dis-connected
 * Cardinality of 0 eigen values == No. of connected components
 * Smallest eigen value is always 0
 * Largest eigen value is 2 iff there is a connected component which is a non-trivial bipartite 
 *  and also the original graph is disconnected
 */

int check() {
    REP(i, n) if(!vis[i]) return i;
    return -1;
}

int get_init_node(int color) {
    REP(i, n) if(vis[i] == color) return i;
}

bool check_bipartite(int color) {
    MEM(label, -1); 

    int u, v;
    queue<int> pq;

    int src = get_init_node(color);
    label[src] = 1;
    pq.push(src);

    while(!pq.empty()) {
        u = pq.front();
        pq.pop();
        REP(i, adj[u].size()){
            v = adj[u][i];
            if(vis[v] != color) continue;
            if(label[v] == -1){
                label[v] = 1 - label[u];
                pq.push(v);
            } else if(label[v] == label[u]) return false;
        }
    }
    return true;
}

pair<bool, int> connected() {
    CLR(vis);
    queue<int> pq;
    int u, color = 0, ret, v;

    while(true) {
        ret = check();
        if(ret == -1) break;
        color++;
        vis[ret] = color;
        pq.push(ret);
        while(!pq.empty()) {
            u = pq.front();
            pq.pop();
            REP(i, adj[u].size()){
                v = adj[u][i];
                if(!vis[v]){
                    pq.push(v);
                    vis[v] = color;
                }
            }
        }
    }
    return mp(color != 1, color);
}

int main() {
    int t;
    int u, v;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &n, &m);
        REP(i, n) adj[i].clear();
        REP(i, m) {
            scanf("%d %d", &u, &v);
            adj[u].pb(v); adj[v].pb(u);
        }
        pair<bool, int> sol = connected();
        if(!sol.ff) {
            printf("NO\n");
            continue;
        }
        
        bool iflag = false;
        FOR1(i, sol.ss) {
            cout<<"checking "<<i<<endl;
            if(check_bipartite(i)){
                iflag = true;
                break;
            }
        }
        printf("%s\n", iflag ? "YES" : "NO");
    }
	return 0;
}
