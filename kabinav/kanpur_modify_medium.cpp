/* 
 *  Vertices are numbered from 1 .. n
 *
 */

#include <cstdio>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

#define MAXN 505
#define mp make_pair

vector< int> graph[MAXN];
pair<int,int> degrees[MAXN];

int preSum[MAXN];
int sufSum[MAXN];
int ldegree[MAXN];

/*
 * type 1 - connected component 1
 * type 2 - connected component 2
 * type -1 - degree is 0
 * type 3- error code, print a NO
 */
int type[MAXN];

void dfs(int s,int component)
{
   int i;
   for(i=0;i<graph[s].size();i++)
   {
      if(type[graph[s][i]] == 3)
      {
          type[graph[s][i]] = component;
          dfs(graph[s][i],component);
      }
   }

}

int main()
{
  int t;
  scanf("%d",&t);
  
  while(t--)
  {
    int n,m;
    scanf("%d %d",&n,&m);

    int i;
    for(i=0;i<MAXN;i++)
    {
      graph[i].clear();
      degrees[i] = mp(0,i);
      type[i] = 3;
    }

    for(i=0;i<m;i++)
    {
      int u,v;
      scanf("%d%d",&u,&v);
      
      u--;
      v--;
      graph[u].push_back(v);
      graph[v].push_back(u);

      degrees[u].first++;
      degrees[u].second = u;

      degrees[v].first++;
      degrees[v].second = v;
    }
    
    sort(degrees,degrees+n);
    
    for(i=0;i<n;i++)
    {
        if(degrees[i].first == 0)
          type[degrees[i].second] = -1;
        else
          break;
    }

    dfs(degrees[i].second,1); 
    for(i=0;i<n;i++)
    {
        if(type[degrees[i].second] == 3)
        {
            dfs(degrees[i].second,2);
            break;
        }
    }
    
    for(i=0;i<n;i++)
    {
        if(type[degrees[i].second] == 3)
        {
            cout<<"NO"<<endl;
            break;
        }
    }
    if(i!=n) 
      continue;
    
    for(i=0;i<MAXN;i++)
    {
        preSum[i] = 0;
        sufSum[i] = 0;
        ldegree[i] = 0;
    }
    int tot = 0;
    for(i=0;i<n;i++)
    {
        if(type[degrees[i].second] == 1)
        {
            ldegree[tot] = degrees[i].first;
            tot++;
        }
    }
    
    preSum[0] = ldegree[0];
    for(i=1;i<tot;i++)
      preSum[i] = preSum[i-1] + ldegree[i];

    sufSum[tot-1] = ldegree[tot-1];
    for(i=tot-2;i>=0;i--)
      sufSum[i] = sufSum[i+1] + ldegree[i];
    
    bool br = true;
    for(i=0;i<tot;i++)
    {
        br = false;
        int sub;
        if(i == 0)
          sub = 0;
        else
          sub = preSum[i-1];
        
        if(sufSum[i]-sub == (tot-i)*(tot-i-1)) 
        {
            br = true; 
            break;
        }
    }
    if(!br)
    {
        cout<<"NO"<<endl;
        continue;
    }
    for(i=0;i<MAXN;i++)
    {
        preSum[i] = 0;
        sufSum[i] = 0;
        ldegree[i] = 0;
    }
    tot = 0;
    for(i=0;i<n;i++)
    {
        if(type[degrees[i].second] == 2)
        {
            ldegree[tot] = degrees[i].first;
            tot++;
        }
    }
    preSum[0] = ldegree[0];
    for(i=1;i<tot;i++)
      preSum[i] = preSum[i-1] + ldegree[i];
    sufSum[tot-1] = ldegree[tot-1];
    for(i=tot-2;i>=0;i--)
      sufSum[i] = sufSum[i+1] + ldegree[i];
    
    br = true;
    for(i=0;i<tot;i++)
    {
        br = false;
        int sub;
        if(i == 0)
          sub = 0;
        else
          sub = preSum[i-1];
        
        if(sufSum[i]-sub == (tot-i-1)*(tot-i)) 
        {
          br = true;  
          break;

        }
    }
    if(!br)
    {
        cout<<"NO"<<endl;
        continue;
    }
    cout<<"YES"<<endl;
  }

}
