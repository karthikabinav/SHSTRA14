#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
  cout<<"10"<<endl;
  int cnt = 0;
  while(cnt<10)
  {
    int n = 1 + cnt;
    cout<<n<<endl;
    int graph[20][20];
    int i,j;
    for(i=0;i<n;i++)
    {
      for(j=0;j<n;j++)
        graph[i][j] = 0;
    }
    int m = 0;
    for(i=0;i<n;i++)  
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
        if(c0>=84*(cnt%5 + 1)) 
          graph[i][j] = graph[j][i] = 0;
        else
        {
          graph[i][j] = graph[j][i] = 1;
          m++;
        }   
      }
    }
    
    {
      m = 0;
      for(i=0;i<n;i++)
      {
          for(j=0;j<n;j++)
          {
              if(graph[i][j] == 1)
                m++; 
          }
      
      }
      cout<<m<<endl;
      
      for(i=0;i<n;i++)
      {
          for(j=0;j<n;j++)
          {
              if(graph[i][j] == 1)
                cout<<i<<" "<<j+n<<endl;
          
          }
      
      }
    
    }
    cnt++;

  }
}
