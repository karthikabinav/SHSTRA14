#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
    cout<<"10"<<endl;
    
    int cnt = 0;
    srand(time(NULL));
    while(cnt<10)
    {
        cout<<"100 100"<<endl;
        int i,j;
        for(i=0;i<100;i++)
        {
            for(j=0;j<100;j++)
              cout<<i+j+rand()%10<<" ";
            cout<<endl;
        
        
        }
        
        for(i=0;i<100;i++)
        {
            for(j=0;j<100;j++)
              cout<<i+j+rand()%10<<" ";
            cout<<endl;
        
        
        }
        cnt++;
    }

}
