#include <cstdio>
#include <iostream>
#include <string>

#define MAX 5005

using namespace std;

/*
 * Input format:
 * t - number of test cases
 *
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
       cin>>a>>b;
      
       int k;
       scanf("%d",&k);
        
       if(k>a.length() || k>b.length())
       {
          printf("0\n");
          continue;
       }
        int i,j;
        for(i=0;i<a.length();i++)
        {
            fdp[i][0] = 0;
            rdp[i][b.length()+1] = 0;
        }
        for(i=0;i<b.length();i++)
        {
            fdp[0][i] = 0;
            rdp[a.length()+1][i] = 0;
        }
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
        for(i=1;i<a.length()-k;i++) 
        {
            for(j=1;j<b.length()-k;j++)
            {
                ans = max(ans,fdp[i][j]+rdp[i+k+1][j+k+1]);
            }
        }
        printf("%d\n",ans);

    }
}
