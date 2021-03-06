#include <cstdio>
#include <cmath>


long long power(long long a, long long b)
{
    if(b == 0)
      return 1;
    if(b == 1)
      return a;
    if(b%2 == 0)
    {
        long long ans = power(a,b/2);
        return ans*ans;
    
    }
    long long ans = power(a,b/2);
    return ans*ans*a;
}

int main()
{
    int t;
    scanf("%d",&t);

    while(t--)
    {
        long long n;
        scanf("%lld",&n);
        
        long long i;
        bool found = false;
        for(i=2;i<=(long long)(ceil(log2(n))+0.5) && !found;i++)
        {
            long long l = 2;
            long long r = (1LL<<((long long)(ceil(log2(n)/i)+0.5)));
            long long mid = (l+r)/2;
            
            while(l<=r)
            {
                long long ans = power(mid,i);
                if(ans<0) // Special fix for overflow
                {
                    r = mid-1;
                    mid = (l+r)/2;
                    continue;
                }
                if(ans == n)
                {
                    printf("YES\n");
                   // printf("%lld %lld\n",mid,i);
                    found = true;
                    break;
                
                }
                else if(ans<n)
                  l = mid+1;
                else
                  r = mid-1;
                mid = (l+r)/2;
            }
        }
        if(!found)
          printf("NO\n");
    }
}
