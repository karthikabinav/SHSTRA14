#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX 500005

long long c_i[MAX],P_i[MAX];
long long cumxor[MAX];

int main()
{
    int t;
    scanf("%d",&t);

    while(t--)
    {
        long long cnt = 0;
        int n;
        int K;
        scanf("%d %d",&n,&K);
       
        
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
            
            long long cur_div = i%K+1;
            cnt = 0;
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
            if(i==0)
              cumxor[i] = cnt;
            else
              cumxor[i] = cumxor[i-1]^cnt;
        }
        
        sort(cumxor,cumxor+n);
       
        //for(i=0;i<n;i++)
        //  cout<<cumxor[i]<<endl;
        long long  ans = 0;
        for(i=0;i<n;i++)
        {
            if(cumxor[i] == 0)
              ans++;
            else
              break;
        }
        long long prev = cumxor[0];
        i = 0;
        while(i<n)
        {
            long long  tcnt = 0;
            while(cumxor[i] == prev && i<n)
            {
                tcnt++;
                i++;
            }
            ans+=(tcnt*(tcnt-1))/2; 
            if(i<n)
              prev = cumxor[i];
        }

       printf("%lld\n",((long long)n*(n+1))/2-ans);
    }
}
