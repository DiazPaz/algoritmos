#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

int seleccion(vector<pair<int,int>> gas, int pos, int rad)
{
    
}

// int seleccion(vector<pair<int,int>> gas, int pos, int radMasPos)
// {
//     for(int i = pos; i < gas.size(); i++)
//     {
//         if(gas[i].first+gas[i].second < radMasPos)
//             continue;
//         else if(gas[i].first-gas[i].second > radMasPos)
//             return -1; 
//         else
//             return i;
//     }
//     return 0; 
// }

int main(void)
{
    int L, G, numFinal = 0; 
    int pos, rad; 
    vector<pair<int,int>> gas; 
    // while(true)
    // {
        
    //     // while(G--)
    //     // {
    //     //     cin >> pos >> rad;
    //     //     gas.push_back(make_pair(pos,rad));
    //     // }
    //     // sort(gas.begin(),gas.end());
        
    //     // int pos = 0; 
    //     // int lActual = 0; 
    //     // int cont = 0; 
    //     // int e = 0;
    //     // while(pos != -1 && lActual < L)
    //     // {
    //         //     e = seleccion(gas, e, lActual);
    //         //     lActual = gas[e].first + gas[pos].second;
    //         //     cont++;
    //         // }
    //         // cout << G-cont << endl;
    //     }
        
        numFinal = 0;
        cin >> L >> G;

        if(L == 0 && G == 0)
            return 0; 

        while(G--)
        {
            cin >> pos >> rad;
            gas.push_back(make_pair(pos,rad));
        }
        sort(gas.begin(),gas.end());

        int cont = 0, aux = 0;
        for(int i = 0; i < L; cont++)
        {

            if(cont == 0 && rad >= pos)
            {
                i += (pos + rad);
                aux = cont; 
            }
            else if(gas[cont].first <= gas[aux].first+gas[aux].second && gas[cont].first > gas[aux].first) // si está dentro del área de cobertura de la gas anterior
            {
                if(gas[cont].first+gas[cont].second > gas[aux].first+gas[aux].second)
                {
                    i += gas[cont].first+gas[cont].second - gas[aux].first+gas[aux].second;
                    numFinal++;
                    cont++;
                }
                else if(gas[cont].first+gas[cont].second <= gas[aux].first+gas[aux].second)
                    cont++;
            }
            else if(gas[cont].first > gas[aux].first+gas[aux].second) // si está a la derecha y fuera del área de cobertura de la gas anterior
            {
                if(gas[cont].first-gas[cont].second <= gas[aux].first+gas[aux].second) // si el limite izquierdo es menor o igual al limite derecho del área de cobertura de la gas anterior
                {
                    if(gas[cont].first-gas[cont].second < gas[aux].first+gas[aux].second)
                    {
                        i += (2*gas[cont].first+gas[cont].second - (gas[aux].first+gas[aux].second - gas[cont].first-gas[cont].second));
                        numFinal++;
                        cont++;
                    }
                    else if(gas[cont].first-gas[cont].second == gas[aux].first+gas[aux].second)
                    {
                        i += 2*gas[cont].first+gas[cont].second;
                        cont++;
                    }    
                }
                else
                    cout << -1 << endl;
            }
            
            
        }
        cout << G - numFinal << endl;

    return 0; 
}