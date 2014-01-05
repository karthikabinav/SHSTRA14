#include <cstdio>
#include <algorithm>
#include <cmath>

#define eps 0
using namespace std;

#define MAX 100005

double ti[MAX],vi[MAX];
double ans[MAX];

int main()
{
    
    int t;
    scanf("%d",&t);
    while(t--)
    {
    int n,a,d;
    scanf("%d %d %d",&n,&a,&d);
    
    int i;
    for(i=0;i<n;i++)
      scanf("%lf %lf",&ti[i],&vi[i]);
    
    i=0;
    if(d-pow(vi[i],2)/(2*a) + eps > 0)
      ans[0] = ti[i]+vi[i]/a + (d-pow(vi[i],2)/(2*a))/vi[i];
    else
      ans[0] = ti[i]+sqrt((2.0*d)/a);
    
    for(i=1;i<n;i++)
    {
        if(d-pow(vi[i],2)/(2*a) + eps > 0)
          ans[i] = ti[i]+vi[i]/a + (d-pow(vi[i],2)/(2*a))/vi[i];
       else
        ans[i] = ti[i]+sqrt((2.0*d)/a);

       ans[i] = max(ans[i-1],ans[i]);
    }
    
    for(i=0;i<n;i++)
    {
        printf("%0.9lf\n",ans[i]);
    }
    }
}
