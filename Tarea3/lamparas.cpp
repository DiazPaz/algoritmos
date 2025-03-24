// David Díaz Paz y Puente | 650794
// Becca
// Damos nuestra palabra que hemos realizado esta actividad con integridad académica. 

#include <iostream>
#include <string>

using namespace std; 

int main(void)
{
    int m2, casos, cont; 
    string iluminacion; 

    cin >> casos; 
    for(unsigned i = 0; i < casos; i++)
    {
        cin >> m2;
        cin >> iluminacion; 

        cont = 0; 
        for(unsigned j = 0; j < m2; j++)
        {
            if(iluminacion[j] == '+')
            {
                j+=2; 
                cont++;
            }
        }

        cout << cont << endl;
    }

    return 0; 
}