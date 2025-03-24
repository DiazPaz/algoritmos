#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

int main(void)
{
    int servidores, capacidad, costoAdicional; 
    cin >> servidores >> capacidad >> costoAdicional; 
    do
    {
        int procesamientoM, procesamientoV;
        vector<int> matutino;
        vector<int> vespertino;
        for(unsigned i = 0; i < servidores; i++)
        {
            cin >> procesamientoM; 
            matutino.push_back(procesamientoM);
        }
        for(unsigned i = 0; i < servidores; i++)
        {
            cin >> procesamientoV; 
            vespertino.push_back(procesamientoV);
        }
        
        int suma = 0; 
        for(unsigned i = 0; i < servidores; i++)
            if(matutino[i] + vespertino[i] > capacidad)
                suma += (matutino[i] + vespertino[i] - capacidad)*costoAdicional;
        cout << suma << endl;
        cin >> servidores >> capacidad >> costoAdicional; 
    }while(servidores != 0 && capacidad != 0 && costoAdicional != 0);

    return 0;
}