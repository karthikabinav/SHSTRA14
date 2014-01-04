#include <cstdio>

#define NIL 0
 
vector< int > G[MAX];
int n, m, match[MAX], dist[MAX];
// n: number of nodes on left side, nodes are numbered 1 to n
// m: number of nodes on right side, nodes are numbered n+1 to n+m
// G = NIL[0] ∪ G1[G[1---n]] ∪ G2[G[n+1---n+m]]
 
bool bfs() {
    int i, u, v, len;
    queue< int > Q;
    for(i=1; i<=n; i++) {
        if(match[i]==NIL) {
            dist[i] = 0;
            Q.push(i);
        }
        else dist[i] = INF;
    }
    dist[NIL] = INF;
    while(!Q.empty()) {
        u = Q.front(); Q.pop();
        if(u!=NIL) {
            len = G[u].size();
            for(i=0; i<len; i++) {
                v = G[u][i];
                if(dist[match[v]]==INF) {
                    dist[match[v]] = dist[u] + 1;
                    Q.push(match[v]);
                }
            }
        }
    }
    return (dist[NIL]!=INF);
}
 
bool dfs(int u) {
    int i, v, len;
    if(u!=NIL) {
        len = G[u].size();
        for(i=0; i<len; i++) {
            v = G[u][i];
            if(dist[match[v]]==dist[u]+1) {
                if(dfs(match[v])) {
                    match[v] = u;
                    match[u] = v;
                    return true;
                }
            }
        }
        dist[u] = INF;
        return false;
    }
    return true;
}
 
int hopcroft_karp() {
    int matching = 0, i;
    // match[] is assumed NIL for all vertex in G
    while(bfs())
        for(i=1; i<=n; i++)
            if(match[i]==NIL && dfs(i))
                matching++;
    return matching;
}

long long ai[MAXM],bi[MAXM],ci[MAXM],di[MAXM];

int main()
{
    int t;
    scanf("%d",&t);

    while(t--)
    {
      int n,m,k;
      scanf("%d %d %d",&n,&m,&k);
      
      int i;
      for(i=0;i<m;i++)
      {
          int u,v;  
          scanf("%d %d %lld %lld %lld %lld",&u,&v,&ai[i],&bi[i],&ci[i])

      }

    }
  
    int p,i;
    scanf("%d%d%d",&n,&m,&p);

    for(i=0;i<p;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        v = v+n;
        G[u].push_back(v);
    }
    printf("%d\n",hopcroft_karp());



}

