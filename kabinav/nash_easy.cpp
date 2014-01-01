#include <cstdio>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

#define MAX 305

bool compare(pair<int,int> a, pair<int,int> b)
{
    if(a.first<b.first)
      return true;
    if(a.first>b.first)
      return false;
    else
      return a.second<b.second;
}

long long powe(long long a, long long b, long long m)
{
    a = a%m;
    if(b == 0)
      return 1;
    if(b== 1)
      return a;
    if(b%2 == 0)
    {
        long long ans = powe(a,b/2,m);
        return (ans*ans)%m;
    }
    long long ans = powe(a,b/2,m);
    ans = (ans*ans)%m;
    return (ans*a)%m;
}


int main()
{
    int t;
    scanf("%d",&t);

    while(t--)
    {
        int n,m; //Action set size of player 1 and action set size of player 2
        scanf("%d %d",&n,&m);
        
        long long a1,a2,b1,b2,M;
        scanf("%lld %lld %lld %lld %lld",&a1,&a2,&b1,&b2,&M);

        long long payoff[MAX][MAX][2];
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
              payoff[i][j][0] = powe(a1*(i+1) + a2*(j+1), M-2, M);
        }

        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
              payoff[i][j][1] = powe(b1*(j+1) + b2*(i+1),M-2,M);
        
        }
        
        for(j=0;j<m;j++)
        {
          long long  maxi = payoff[0][j][0];
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
          long long  maxi = payoff[i][0][1];
          for(j=0;j<m;j++)
          {
              if(payoff[i][j][1]>maxi) 
                maxi = payoff[i][j][1];
          }
          for(j=0;j<m;j++)
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
        for(i=0;i<Nash.size();i++)
          cout<<Nash[i].first<<" "<<Nash[i].second<<endl;
        /*if(Nash.size() == 0)
          printf("-1\n");
        else
          printf("%d %d\n",Nash[0].first+1,Nash[0].second+1);*/
    }
}
