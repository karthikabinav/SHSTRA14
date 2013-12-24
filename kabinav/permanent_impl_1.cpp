#include <cstdio>

#define MAX 15
#define mod 1000000000 //RG mod

long long permanent(int mat[MAX][MAX],int n)
{
    int sub = 0;
    int i,j;
    
    long long ans = 0;
    while(sub<(1LL<<n))
    {
      int modS = 0;
      for(i=0;i<n;i++)
      {
          if((1LL<<i)&sub)
            modS++;
      }
      
      long long outPro=1;
      for(i=0;i<n;i++)
      {
          int inSum = 0;
          for(j=0;j<n;j++)
          {
            
              if((1LL<<j)&sub)
              {
                  inSum+=mat[i][j];
              }
          }
          outPro = (outPro*inSum);
      }
      if(modS%2 == 0)
        ans = (ans + outPro);
      else
        ans = (ans - outPro);
      sub++;    
    }
    if(n%2 == 0)
      return ans;
    return (-1*ans);
}

//Input vertices numbered from 0 to n-1 on the LHS and n to 2*n-1 on RHS
int main()
{
    int t;
    scanf("%d",&t);

    while(t--)
    {
        int n,m; 
        scanf("%d %d",&n,&m);
        
        int mat[MAX][MAX];
        int i,j;
        for(i=0;i<n;i++)
        {
           for(j=0;j<n;j++)
           {
              mat[i][j] = 0; 
           }
        }

        for(i=0;i<m;i++)
        {
            int u,v;
            scanf("%d %d",&u,&v);
            mat[u][v-n] = 1;
        }
        
        printf("%lld\n",permanent(mat,n)%mod);
    }
}
