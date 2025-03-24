/* 
David Díaz Paz y Puente 650794
Rebeca Laredo González 613587
Damos nuestra palabra que hemos realizado esta actividad con integridad académica.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

bool myfunction(int i, int j){ return i > j; }

int main(void)
{
    int loops, duracion, suma = 0, canciones = 0; 
    cin >> loops; 
    do
    {
        vector<int> duraciones; 
        for(int i = 0; i < loops; i++)
        {
            cin >> duracion; 
            duraciones.push_back(duracion);
        }
        
        sort(duraciones.begin(), duraciones.end(), myfunction);
        
        canciones = 0;
        int mayor = duraciones[0];
        for(int i = 1; i < loops; i++)
        {  
            if(mayor - duraciones[i] >= 0)
            {
                mayor -= duraciones[i];
                canciones++;
            }
        }
        
        cout << canciones+1 << endl;        
        cin >> loops;  

    }while(loops != 0);
    
    return 0;
}   