#include <iostream> 
#include <vector>

using namespace std; 

int main(void) {
    int cases, coins, n , nivel; 
    unsigned j;
    cin >> cases; 
    for(unsigned i = 0; i < cases; i++)
    {
        n = 1, nivel = 1;
        cin >> coins; 
        for(j = 1; j < coins; j += n)
        {
            n++;
            nivel++;
        }

        if(coins - j)
            cout << nivel - 1 << endl;
        else
            cout << nivel << endl;
    }
    return 0;
}