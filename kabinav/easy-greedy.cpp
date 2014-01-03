#include <cstdio>
#include <cmath>
#include <iostream>

#define MAX 1000006
using namespace std;

long long ti[MAX],Ti[MAX],xi[MAX],costi[MAX];
int main()
{
  int t;
  scanf("%d",&t);

  while(t--)
  {
    int n,m;
    scanf("%d %d",&n,&m);

    int i;
    for(i=0;i<n;i++)
    {
      scanf("%lld %lld %lld %lld",&ti[i],&Ti[i],&xi[i],&costi[i]);

    }

    long long cost = 0;
    for(i=0;i<n;i++)
    {
      if(ti[i]+m<=Ti[i])    
      {
        cost+=costi[i];
        continue;
      }
      if(ti[i]<Ti[i])
      {
        long long numR = ceil((m*1.0)/(Ti[i]-ti[i]));
        cost+= min(numR*costi[i],costi[i]+xi[i]*m);
      }
      else
        cost+=costi[i]+xi[i]*m;
    }

    cout<<cost<<endl;
  }
}
