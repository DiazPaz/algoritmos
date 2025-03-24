#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std; 

int tablero[8][8] = {0};

bool amenaza(int c, int f)
{
    // revisar fila
    for(int i = c-1; i >= 0; c--)
        if(tablero[f][i] == 1)
            return true; 
    // revisar diagonal superior
    for(int i = c-1, int j = f-1; i >= 0 && j >= 0; i--, j--)
        if(tablero[j][i] == 1)
            return true; 
    // revisar diagonal inferior
    for(int i = c-1, int j = f+1; i >= 0 && j <= 7; i--, j++)
        if(tablero[j][i] == 1)
            return true; 
    return false;
}

void reinas(int c)
{
    if(c > 7 )
    {
        for(int i = 0; i < 8; i++)
        {
            for(int j = 0; j < 8; j++)
            {
                cout << tablero[i][j];
            }
            cout << endl; 
        }
    }
}


int main(void)
{
    reinas(0);

    return 0; 
}