#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int main()
{
    srand(time(NULL));
    cout<<"10000"<<endl;
    int cnt = 0;
    while(cnt<10000)
    {
        if(cnt%2 == 0)
          cout<<(rand()+1)*20001LL<<endl;  
        else
          cout<<min((long long)pow(11,cnt%7+1),(long long)pow(101,cnt%5+1))<<endl;
        cnt++;
    }    

}
