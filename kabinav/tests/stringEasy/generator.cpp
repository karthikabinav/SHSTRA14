#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    cout<<"20"<<endl; 
    srand(time(NULL));

    char apl[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    int cnt =0;
    while(cnt<20)
    {
       cout<<"250 250 "<<rand()%251<<endl;     
       
       int i;
       for(i=0;i<250;i++)
         cout<<apl[rand()%26];
       cout<<endl;
       for(i=0;i<250;i++)
         cout<<apl[rand()%26];
       cout<<endl;
      cnt++; 
    }
}
