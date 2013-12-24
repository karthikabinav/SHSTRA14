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
            
            long long cur_div = i+1;
            while(true)
            {
                if(r<cur_div)
                {
                    cnt^=0;
                    break;
                }
              
                if(r%cur_div == 0)
                {
                    cnt^=(r/cur_div);
                    break;
                
                }
                else
                    r = r-(r/cur_div+1);
            }
        }
        if(cnt!=0)
          printf("YES\n");
        else
          printf("NO\n");
    }
}
