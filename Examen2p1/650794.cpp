// David Díaz Paz y Puente 650794
//  Doy mi palabra que he realizado esta actividad con integridad académica
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime> 

using namespace std; 

int main(void)
{
    int n; 
    int org, dest; 
    int difD, count = 1; 
    while(cin >> n && n != 0)
    {
        clock_t inicio = clock();  
        vector<pair<int,int>> routes(n);
        vector<int> difDest;
        int aux = 0; 
        for(int i = 0; i < n; i++)
        {
            cin >> org >> dest; 
            routes[i].first = org; 
            routes[i].second = dest; 
        } 

        sort(routes.begin(), routes.end());

        for(int i = 0; i < n; i++)
        {
            difD = routes[i].second;
            auto it = find(difDest.begin(), difDest.end(), difD);
            if(it == difDest.end())
                difDest.push_back(difD);
            for(int j = i+1; j < n; j++)
            {
                if(routes[i].first == routes[j].first && routes[j].second == routes[i].second)
                    aux++;
            }
        }
        if(aux%2 == 0 || difDest.size()%2 == 0)
            cout << "Caso " << count << ": POSIBLE " << difDest.size() << endl;
        else
            cout << "Caso " << count << ": IMPOSIBLE " << endl;

            count++;
            clock_t fin = clock();  // Tiempo final
            double tiempo = double(fin - inicio) / CLOCKS_PER_SEC;
            cout << "Tiempo de ejecucion: " << tiempo << " segundos" << endl;

    }

    return 0; 
}