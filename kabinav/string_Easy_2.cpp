#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>

#define MAX 5005

using namespace std;

/*
 * Input format:
 * t - number of test cases
 * Two integers n,m sizes of the two strings n and m
 * Each case has two strings and integer which is value of k
 *
 */

int fdp[MAX][MAX],rdp[MAX][MAX];
int main()
{
    int t;
    scanf("%d",&t);

    while(t--)
    {
       string a,b;
        int n,m;
        int k;
        scanf("%d %d %d",&n,&m,&k);

       cin>>a>>b;
        
       if(k>a.length() || k>b.length())
       {
          printf("-1\n");
          continue;
       }
        int i,j;
        memset(fdp,0,sizeof(fdp));
        memset(rdp,0,sizeof(rdp));
        for(i=1;i<=a.length();i++)
        {
            for(j=1;j<=b.length();j++)
            {
                if(a[i-1] == b[j-1])
                  fdp[i][j] = fdp[i-1][j-1] + 1;
                else
                  fdp[i][j] = max(fdp[i-1][j],fdp[i][j-1]);
            }
        }
        for(i=a.length();i>0;i--)
        {
            for(j=b.length();j>0;j--)
            {
                if(a[i-1] == b[j-1])
                  rdp[i][j] = rdp[i+1][j+1] + 1;
                else
                  rdp[i][j] = max(rdp[i+1][j],rdp[i][j+1]);
            }
        }
        int ans = 0;
        for(i=1;i<=a.length()-k+1;i++) 
        {
            for(j=1;j<=b.length()-k+1;j++)
            {
                ans = max(ans,fdp[i-1][j-1]+rdp[i+k][j+k]);
            }
        }
        printf("%d\n",ans);

    }
}
