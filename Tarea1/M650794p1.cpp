// David Díaz Paz y Puente | 650794
// Doy mi palabra que he realizado esta actividad con integridad académica. 

#include <iostream>
using namespace std; 

int main(void)
{
    string input1, input2;
    int digito1, digito2, suma, acarreos, acarreado;
    bool bandera = true; 

    do
    {
        cin >> input1 >> input2;

        if (input1 == "0" && input2 == "0") 
        {
            bandera = false;
        }
        else 
        {
            acarreado = 0, acarreos = 0;
            int i = input1.length() - 1, j = input2.length() - 1;

            while (i >= 0 || j >= 0) {
                digito1 = (i >= 0) ? input1[i] - '0' : 0;
                digito2 = (j >= 0) ? input2[j] - '0' : 0;
                suma = digito1 + digito2 + acarreado;

                if (suma >= 10) {
                    acarreado = 1;
                    acarreos++;
                } else {
                    acarreado = 0;
                }
                i--;
                j--;
            }

            if (acarreos > 0)
                cout << acarreos << " acarreos" << endl;
            else
                cout << "Sin acarreos" << endl;
        }

    }while(bandera);

    return 0; 
}