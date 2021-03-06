/*
 * Second smallest eigen value of the Laplacian is 0 iff graph is disconnected
 */ 

#include <cstdio>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

#define MAXN 1005
#define eps 0.000000001

vector<int> graph[MAXN];
bool visited[MAXN];

bool biPartite(int n)
{
  int color[MAXN];
  int i;
  for(i=0;i<n;i++)
    color[i] = 0;
  
  bool change = true;
  int k = 0;
  while(k<n){
    change = false;
    stack<int> dfs;
    
    while(color[k]!=0 && k<n)
      k++;

    change = true;
    color[k] = 1;
    dfs.push(k);
    
    bool bp = true;
    int cmpSize = 0;
    while(!dfs.empty() && bp)
    {
      int top = dfs.top();
      cmpSize++;
      dfs.pop();

      int j;
      for(j=0;j<graph[top].size() && bp;j++)
      {
        if(color[graph[top][j]] == 0)
        {
          if(color[top] == 1)
            color[graph[top][j]] = 2;
          else
            color[graph[top][j]] = 1;
          dfs.push(graph[top][j]);
        }
        else
        {
          if(color[top] == color[graph[top][j]])      
            bp = false;

        }
      }
    }
    if(bp && cmpSize >1)
      return true;
  }
  return false;
}

bool oneComponent(int n)
{
  stack<int> dfs;
  if(graph[0].size() == 0)
    return false;

  dfs.push(graph[0][0]);
  visited[graph[0][0]] = true;
  while(!dfs.empty())
  {
    int top = dfs.top();
    dfs.pop();
    int i;
    for(i=0;i<(int)graph[top].size();i++)
    {
      if(!visited[graph[top][i]])        
      {
        visited[graph[top][i]] = true;
        dfs.push(graph[top][i]);
      }
    }
  }
  int i;
  for(i=0;i<n;i++)
  {
    if(!visited[i])
      return false;
  }
  return true;
}

int main()
{
  int t;
  scanf("%d",&t);

  while(t--)
  {
    int n,m;
    scanf("%d %d",&n,&m);

    int i,j;
    
    for(i=0;i<MAXN;i++)
    {
      graph[i].clear();
      visited[i] = false;
    }
    
    for(i=0;i<m;i++)
    {
        int u,v;
        scanf("%d %d",&u,&v);
        graph[u].push_back(v);
        graph[v].push_back(u);

    }
    /*
     * Note input to the code is a graph in the form of adjacency list
     * Generate a normalized laplacian. It is defined as D^-0.5 L D^ -0.5
     * visually:
     * i==j and deg_i \neq 0  => mat[i][j] = 1
     * if i adjacent to j mat[i][j] = -1/sqrt(deg_i*deg_j)
     * o/w  mat[i][j] = 0
     */
    
    if(oneComponent(n))
      cout<<"NO"<<endl;
    else
    {
      if(biPartite(n))
        cout<<"YES"<<endl;
      else
        cout<<"NO"<<endl;
    }
  }
}
