#include <cmath>
#include <cstdlib>
#include <iostream>

using namespace std;

#define MAXN 500

int graph[MAXN][MAXN];

int main()
{
  srand(time(NULL)) ; 

  cout<<"20"<<endl;

  int cnt = 0;
  int n = 0;
  while(cnt<20)
  {
    int i,j;
    n+=25; 
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
      graph[i][j] = 0;
  }

    for(i=0;i<n/3;i++) 
    {
      for(j=i+1;j<n/3;j++)
      {
          int k = 500;
          int c0 = 0;
          while(k--)
          {
              int r = rand()%2;
              if(r==0)
                c0++;
          }
          if(c0>450 - 16*cnt) 
            graph[i][j] = graph[j][i] = 0;
          else
          {
              graph[i][j] = graph[j][i] = 1;
          }
      }
    
    }
    for(i=n/3;i<(2*n)/3;i++) 
    {
      for(j=i+1;j<(2*n)/3;j++)
      {
          int k = 500;
          int c0 = 0;
          while(k--)
          {
              int r = rand()%2;
              if(r==0)
                c0++;
          }
          if(c0>230 + 16*cnt) 
            graph[i][j] = graph[j][i] = 0;
          else
          {
              graph[i][j] = graph[j][i] = 1;
          }
      }
    
    }
    for(i=(2*n/3);i<(3*n)/3;i++) 
    {
      for(j=i+1;j<(3*n)/3;j++)
      {
          int k = 500;
          int c0 = 0;
          while(k--)
          {
              int r = rand()%2;
              if(r==0)
                c0++;
          }
          if(c0>16*cnt) 
            graph[i][j] = graph[j][i] = 0;
          else
          {
              graph[i][j] = graph[j][i] = 1;
          }
      }
    
    }
    
    int m=0;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(graph[i][j] !=0)
              m++;
        }
    }
    cout<<n<<" "<<m<<endl;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(graph[i][j]!=0)
              cout<<(i+1)<<" "<<(j+1)<<endl;
        
        } 
    }

    cnt++;
  }
}
