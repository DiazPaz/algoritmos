#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

int factorial(int n)
{
    if(n == 0 || n == 1)
        return 1;

    return n*factorial(n-1);
}

int main(void)
{
    int cases, N, H, pos; 
    while(cin >> cases)
    {
        cout << endl;
        cin >> N >> H;
        
        vector<int> binario(N,0);

        int sizeOutput = factorial(N)/(factorial(N-H)*factorial(H));

        for(unsigned i = 0; i < sizeOutput; i++)
        {
            
        }

    }  
    return 0; 
}