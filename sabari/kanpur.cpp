/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : kanpur-med.cpp

* Creation Date : 03-01-2014

* Last Modified : Friday 03 January 2014 08:13:23 PM IST

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
#define MAXN 510
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

int N, M;
vi adj[MAXN];
int comp[MAXN];
pii degree_lst[MAXN];

int cumsum[MAXN], revcumsum[MAXN], store[MAXN];

/*
 * type 1 - complete subgraph1
 * type 2 - complete subgraph2
 * type 3 - inverted complete subgraph
 * type -1 - None
 */

bool check_components(int co) {
    CLR(cumsum); CLR(revcumsum); CLR(store);

    int cnt = 0;
    REP(i, N) if( comp[degree_lst[i].ss] == co) {store[cnt] = degree_lst[i].ff; cnt++;}

    if(cnt == 0) return true;  // empty component is perfectly fine

    cumsum[0] = store[0];
    FOR1(i, cnt-1) cumsum[i] = cumsum[i-1] + store[i];
    revcumsum[cnt-1] = store[cnt-1];
    RFOR(i, cnt-1) revcumsum[i] = revcumsum[i+1] + store[i];

    int tmp;
    REP(i, cnt) {
        tmp = (i == 0 ? 0 : cumsum[i-1]);
        // checking whether this component can be split into two partitions
        if(revcumsum[i]-tmp == (cnt-i)*(cnt-i-1)) return true;
    }
    return false;
}

void bfs(int node, int co){
    queue<int> pq;
    comp[node] = co;
    pq.push(node);
    int u;
    while(!pq.empty()){
        u = pq.front();
        pq.pop();
        REP(i, adj[u].size()) {
            if(comp[adj[u][i]] == -1){
                comp[adj[u][i]] = co;
                pq.push(adj[u][i]);
            }
        }
    }
}

int main() {
    int c;
    int u, v;
    scanf("%d", &c);
    while(c--) {
        MEM(comp, -1);
        scanf("%d%d", &N, &M);
        REP(i, MAXN) {adj[i].clear(); degree_lst[i] = mp(0,i);} 
        REP(i, M) {
            scanf("%d%d", &u, &v); u--; v--;
            adj[u].pb(v); adj[v].pb(u);
            degree_lst[u].ff++;
            degree_lst[v].ff++;
        }
        sort(degree_lst, degree_lst+N);
        /*
        REP(i, N){
            cout<<"Node "<<degree_lst[i].ss<<" degree "<<degree_lst[i].ff<<endl;
        }
        */

        // Make components
        v = 0;
        REP(i, N) {
            if(degree_lst[i].ff == 0) comp[degree_lst[i].ss] = 3;
            else break;
            v++;
        }
        if(v < N) {
            bfs(degree_lst[v].ss, 1);
            REP(i, N) {
                if(comp[degree_lst[i].ss] == -1){
                    bfs(degree_lst[i].ss, 2);
                    break;
                }
            }
        }

        bool iflag = false;
        REP(i, N) {
            if(comp[degree_lst[i].ss] == -1){
                iflag = true;
                break;
            }
        }
        if(iflag) {
            printf("NO\n");
            continue;
        }

        if(check_components(1) && check_components(2)) printf("YES\n");
        else printf("NO\n");
    }
	return 0;
}
