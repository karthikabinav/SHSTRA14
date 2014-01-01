#include <cstdlib>
#include <iostream>

#define nine 1000000000
#define five 100000

using namespace std;

int main()
{
    cout<<"75"<<endl;
    
    int cnt = 0;
    srand(time(NULL));
    while(cnt<75)
    {
        cout<<"299 300"<<endl;
        cout<<rand()%nine + 1 << " "<<rand()%nine + 1 <<" "<< rand()%nine + 1 
          <<" "<< rand()%nine + 1 <<" "<< rand()%five + 1<<endl;
      
      
        cnt++;
    }

}
