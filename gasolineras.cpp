#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int seleccion(vector<pair<int, int>> &E, int eact, int lactual)
{
    if (eact >= E.size())
        return -9;
    int imax = eact;
    for (int i = eact; i < E.size(); i++)
    {
        if (E[i].first - E[i].second <= lactual)                           // Si la estacion cubre hasta donde vamos
            if (E[i].first + E[i].second > E[imax].first + E[imax].second) // Vemos si cubre más.
                imax = i;
    }
    if (E[imax].first - E[imax].second <= lactual) // Si la elegida cubre hasta donde vamos
        return imax;
    else
        return -9;
}

int main()
{
    int L, G, x, r;
    while (true)
    {
        cin >> L >> G;
        if (L == 0 && G == 0)
            return 0;
        vector<pair<int, int>> E;
        for (int i = 0; i < G; i++)
        {
            cin >> x >> r;
            E.push_back(make_pair(x, r));
        }
        sort(E.begin(), E.end());
        int lactual = 0;
        int cont = 0;
        int e = -1;
        while (e != -9 && lactual < L)
        {
            e = seleccion(E, e + 1, lactual);
            // cout<<"Se toma "<<e<<endl;
            if (e == -9)
                continue;
            lactual = E[e].first + E[e].second;
            // cout<<"vamos en "<<lactual<<endl;
            cont++;
        }
        if (e == -9)
            cout << "-1" << endl;
        else
            cout << G - cont << endl;
    }
}