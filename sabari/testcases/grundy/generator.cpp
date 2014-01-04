/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : generator.cpp

* Creation Date : 02-01-2014

* Last Modified : Friday 03 January 2014 07:39:20 PM IST

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

int MOD_FLOOR = 4;

ll get_grundy(ll num, int idx){
    idx = idx%MOD_FLOOR+1;
    while(num >= idx){
        if(num%idx == 0) return num/idx;
        num = num - num/idx -1;
    }
    return 0;
}

int num_files = 7;
int max_cases = 10;

ll max_P[MAXN];

#define MAXE 100000000000000000LL

ll get_num(ll num, int idx) {
    int mod_cnt = idx%MOD_FLOOR + 1;
    ll to_ret = 0;
    int bit_size = 60;  // number of bits needed to represent MAXE
    REP(i, bit_size) if((num & (1LL<<i))) to_ret |= (1LL<<i);
    assert(to_ret^num == 0);
    if(to_ret*mod_cnt > max_P[idx]){return (int)rand()%(max_P[idx]+1);}
    assert(max_P[idx] >= to_ret*mod_cnt);
    return (max_P[idx] - to_ret*mod_cnt);
}

#define MIN_VAL 100000000000000LL
#define DIFF (MAXE-MIN_VAL)

int main() {
    srand(time(NULL));

    FILE* fp;
    int npiles, kprime;
    ll val, xor_val;
    REP(file_idx, num_files){
        stringstream ss;
        ss<<"grundy_in_"<<file_idx;
        fp = fopen(ss.str().c_str(), "w");
        cout<<"Starting "<<file_idx<<" file"<<endl;
        fprintf(fp, "%d\n", max_cases);

        bool iflag;
        REP(cases, max_cases) {
            if(rand()%100 == 50) iflag = true;   // One in hundred the player 1 looses completely
            else iflag = false;
            npiles = rand()%(MAXN-10+1);
            MOD_FLOOR = rand()%10 + 1;
            fprintf(fp, "%d %d\n", npiles, MOD_FLOOR);
            xor_val = 0;
            REP(i, npiles)  max_P[i] = rand()%DIFF + MIN_VAL;
            REP(i, npiles) {
                kprime = rand()%10;
                if(iflag || kprime < 8) val = get_num(xor_val, i);
                else val = rand()%(max_P[i]+1);
                fprintf(fp, "%lld%c", val, (i == npiles-1) ? '\n' : ' ');
                xor_val ^= get_grundy(max_P[i]-val, i);
            }
            REP(i, npiles)  fprintf(fp, "%lld%c", max_P[i], (i == npiles-1) ? '\n' : ' ');
        }
        fclose(fp);
    }
	return 0;
}
