#include <iostream>
#include <cstdlib>

#define MAX 1000000
using namespace std;

int main()
{
    int t;
    t = 10;
    cout<<t<<endl;

    srand(time(NULL));
    while(t--)
    {
      int n = 10000; 
      int a = rand()%1000 + 1;  
      int d =  rand()%MAX + 1;
      
      cout<<n<<" "<<a<<" "<<d<<endl;
      int i;
      int prev = 0;
      for(i=0;i<n;i++)
      {
          prev = prev + 1 + min(rand()%(i+1) +1,MAX/3 - prev - 1 - (n-i));
          cout<<prev<<" "<<10*i+7<<endl;
      }
    
    }

}
