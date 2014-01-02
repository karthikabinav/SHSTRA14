#include <cmath>
#include <cstdlib>
#include <iostream>

using namespace std;

#define MAXN 500


int graph[MAXN][MAXN];
double laplacian[MAXN][MAXN];
int deg[MAXN];

int main()
{
  srand(time(NULL)) ; 

  cout<<"20"<<endl;

  int cnt = 0;
  while(cnt<20)
  {
    int i,j;
    int n = 300 - cnt;
    
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
      graph[i][j] = 0;
  }

    //generating random 2 parition graphs
    for(i=0;i<n/2;i++) 
    {
      for(j=i+1;j<n/2;j++)
      {
          int k = 500;
          int c0 = 0;
          while(k--)
          {
              int r = rand()%2;
              if(r==0)
                c0++;
          }
          if(c0>400 - 16*cnt) 
            graph[i][j] = graph[j][i] = 0;
          else
          {
              graph[i][j] = graph[j][i] = 1;
              deg[i]++;
              deg[j]++;
          }
      }
    
    }
    for(i=n/2;i<n;i++) 
    {
      for(j=i+1;j<n;j++)
      {
          int k = 500;
          int c0 = 0;
          while(k--)
          {
              int r = rand()%2;
              if(r==0)
                c0++;
          }
          if(c0>100 + 16*cnt) 
            graph[i][j] = graph[j][i] = 0;
          else
          {
              graph[i][j] = graph[j][i] = 1;
              deg[i]++;
              deg[j]++;
          }
      }
    
    }


            //Generate the Laplacian
    int m=0;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            /*if(i==j)
            {
                if(deg[i]==0)
                  laplacian[i][j] = 0;
                else
                  laplacian[i][j] = 1;
            
            }
            else if(graph[i][j] == 0)
              laplacian[i][j] = 0;
            else
              laplacian[i][j] = -1/sqrt(deg[i]*deg[j]);*/
            if(graph[i][j] !=0)
              m++;
        }
    }
    cout<<n<<" "<<m<<endl;
    // Output the Laplacian
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(graph[i][j]!=0)
              cout<<i<<" "<<j<<endl;
        
        } 
    }

    cnt++;
  }
}
