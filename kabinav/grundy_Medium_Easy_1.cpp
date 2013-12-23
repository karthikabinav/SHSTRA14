#include <cstdio>

#define MAX 1000

int main()
{
    int t;
    scanf("%d",&t);

    while(t--)
    {
        long long cnt = 0;
        int n;
        scanf("%d",&n);
       
        long long c_i[MAX],P_i[MAX];

        int i;
        for(i=0;i<n;i++)
          scanf("%lld",&c_i[i]);
        for(i=0;i<n;i++)
          scanf("%lld",&P_i[i]);
        for(i=0;i<n;i++)
          c_i[i]=P_i[i]-c_i[i];

        for(i=0;i<n;i++)
        {
            long long r;
            r = c_i[i];

            while(true)
            {
                if(r == 1)
                {
                    cnt^=0;
                    break;
                }
                if(r==2)
                {
                    cnt^=0;
                    break;
                }
                if(r%3 == 0)
                {
                    cnt^=(r/3);
                    break;
                
                }
                else
                    r = r-((r/3)+1);
            }
        }
        if(cnt!=0)
          printf("YES\n");
        else
          printf("NO\n");
    
    
    
    
    }
}
