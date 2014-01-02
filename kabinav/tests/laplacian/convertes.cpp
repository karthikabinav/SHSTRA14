#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    
    cout<<t<<endl;
    
    while(t--){
    int n;
    scanf("%d",&n);

    int m = 0;
    int i,j;
    double mat[505][505];

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            double u;
            scanf("%lf",&u);
            
            mat[i][j] = u;
            if(i<j && u!=0)
              m++; 
        }
    }
    cout<<n<<" "<<m<<endl;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(mat[i][j] != 0)
              cout<<i<<" "<<j<<endl;
        
        }
    
    }    }
}
