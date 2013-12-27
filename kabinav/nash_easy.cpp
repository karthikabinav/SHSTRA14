#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

#define MAX 100

bool compare(pair<int,int> a, pair<int,int> b)
{
    if(a.first<b.first)
      return true;
    if(a.first>b.first)
      return false;
    else
      return a.second<b.second;
}

int main()
{
    int t;
    scanf("%d",&t);

    while(t--)
    {
        int n,m; //Action set size of player 1 and action set size of player 2
        scanf("%d %d",&n,&m);
        
        int payoff[MAX][MAX][2];
        bool bestResponse[MAX][MAX][2];
        
        int i,j;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                bestResponse[i][j][0] = bestResponse[i][j][1] = false;
            }
        }

        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
                scanf("%d",&payoff[i][j][0]);
        }
        
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
                scanf("%d",&payoff[i][j][1]);
        }
        
        for(j=0;j<m;j++)
        {
          int maxi = payoff[0][j][0];
          for(i=0;i<n;i++)
          {
              if(payoff[i][j][0]>maxi) 
                maxi = payoff[i][j][0];
          }
          for(i=0;i<n;i++)
          {
              if(payoff[i][j][0] == maxi)
                bestResponse[i][j][0] = true;
          }
       }
       
        for(i=0;i<n;i++)
        {
          int maxi = payoff[i][0][1];
          for(j=0;j<m;j++)
          {
              if(payoff[i][j][1]>maxi) 
                maxi = payoff[i][j][1];
          }
          for(j=0;j<n;j++)
          {
              if(payoff[i][j][1] == maxi)
                bestResponse[i][j][1] = true;
          }
       }
       
        vector< pair<int,int> > Nash;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(bestResponse[i][j][0] && bestResponse[i][j][1])
                {
                    Nash.push_back(make_pair(i,j));
                }
            }
        }
        sort(Nash.begin(),Nash.end(),compare);
        if(Nash.size() == 0)
          printf("-1\n");
        else
          printf("%d %d\n",payoff[Nash[0].first][Nash[0].second][0],payoff[Nash[0].first][Nash[0].second][1]);
    }
}
