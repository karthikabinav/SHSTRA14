/*
 * Second smallest eigen value of the Laplacian is 0 iff graph is disconnected
 */ 

#include <cstdio>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

#define MAXN 1005


vector<int> graph[MAXN];
bool visited[MAXN];

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
        int n;
        scanf("%d",&n);
        
        int mat[MAXN][MAXN];
        int i,j;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
              scanf("%d",&mat[i][j]);
        }
        
        for(i=0;i<MAXN;i++)
        {
            graph[i].clear();
            visited[i] = false;
        }

        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(i==j)
                  continue;
                else if(mat[i][j] == -1)
                  graph[i].push_back(j);
            }
        }
        if(oneComponent(n))
          cout<<"NO"<<endl;
        else
          cout<<"YES"<<endl;

    }
}
