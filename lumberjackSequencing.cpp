#include <iostream>
using namespace std;

int main(void)
{
    int N, barbas[10]; 
    cin >> N; 

    for(size_t i = 0; i < N; i++)
    {
        for(size_t j = 0; j < 10; j++)
            cin >> barbas[j];

        int b; 
        if(barbas[0] < barbas[1])
        {
            // ascendente
            for(b = 1; b < 9; b++)
                if(barbas[b] > barbas[b+1])
                    break;
            if(b == 9)
                cout << "Ordered\n";
            else 
                cout << "Unordered\n";
        }
        else
        {
            // descendente
            for(b = 1; b < 9; b++)
                if(barbas[b] < barbas[b+1])
                    break;
            if(b == 9)
                cout << "Ordered\n";
            else 
                cout << "Unordered\n";
        }
    }


    return 0; 
}