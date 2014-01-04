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
        cout<<cnt+2<<endl;  
        cnt++;
    }    

}
