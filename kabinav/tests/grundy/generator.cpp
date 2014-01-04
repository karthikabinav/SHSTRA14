#include <iostream>
#include <cstdlib>
#include <algorithm>

#define MAX 10000
using namespace std;

long long ci[100005],pi[100005];
int main()
{

    int t;
    t = 10;
    
    cout<<t<<endl;
    
    

    while(t--)
    {
        int n = rand()%10000+1;
        int k = rand()%10 + 1;
    
        long long c = (rand()*90706003LL)%MAX + 1;
        long long p = (rand()*12345678LL)%MAX + 1; 
       int i; 
        for(i=0;i<n;i++){
          ci[i] = min(c,p);
          pi[i] = max(c,p);
        }    

        cout<<n<<" "<<k<<endl;
        next_permutation(ci,ci+n);
        next_permutation(ci,ci+n);
        next_permutation(pi,pi+n);
        next_permutation(pi,pi+n);
       
        for(i=0;i<n;i++)
        {
            long long oci = ci[i];
           ci[i] = min(ci[i],pi[i]);
           pi[i] = max(oci,pi[i]);
        }
        if(t!=0){
        for(i=0;i<n;i++)
        {
            if(i!=n-1)
              cout<<ci[i]<<" ";
            else
              cout<<ci[i]<<endl;
        
        }
        
        for(i=0;i<n;i++)
        {
            if(i!=n-1)
              cout<<pi[i]<<" ";
            else
              cout<<pi[i]<<endl;
        
        }
        }
        else
        {
            for(i=0;i<n;i++)
            {
                if(i!=n-1)
                  cout<<ci[i]<<" ";
                else
                cout<<ci[i]<<endl;

            
            }
            for(i=0;i<n;i++)
            {
                if(i!=n-1)
                  cout<<ci[i]<<" ";
                else
                cout<<ci[i]<<endl;
            }
        }
    }


}
