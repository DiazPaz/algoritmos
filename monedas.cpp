#include <iostream>
#include <vector>
using namespace std; 

int seleccion(vector<int> &monedas, int cantidad)
{
    int i; 
    for(i = monedas.size()-1; monedas[i] > cantidad; i--);
    return i;
}

int main(void)
{
    vector<int> monedas = {1,2,5,10,20};
    vector<int> S(5,0);
    int cantidad;   
    cin >> cantidad; 

    while(cantidad > 0)
    {
        int elemento = seleccion(monedas, cantidad);
        S[elemento]++;
        cantidad -= monedas[elemento];
    }

    for(int i = S.size(); i >= 0; i--)
    {
        if(S[i] > 0)
            cout << "Dar " << S[i] << " de " << monedas[i] << endl;
    }

    return 0;
}