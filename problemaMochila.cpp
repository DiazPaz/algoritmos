#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool myfunction(pair<int, int> i, pair<int, int> j)
{
    // menor que, para más grande al final
    return((double)i.first/i.second < (double)j.first/j.second);
}

int seleccion(vector<pair<int,int>> &objetos, vector<int> &usado)
{
    for(int i = objetos.size()-1; i >= 0; i--)
        if(usado[i] == 0)
            return i; 
    return -1;
}

int main() {
    vector<pair<int,int>> objetos;
    //                      precio,peso
    objetos.push_back(make_pair(20,10));
    objetos.push_back(make_pair(30,20));
    objetos.push_back(make_pair(66,30));
    objetos.push_back(make_pair(40,40));
    objetos.push_back(make_pair(60,50));
    sort(objetos.begin(),objetos.end(), myfunction);
    
    vector<int> usado(5,0); // 0 no usado, 1 usado, 2 descartado
    int capacidad = 100, ganancia = 0; 

    while(capacidad && find(usado.begin(), usado.end(),0) != usado.end())
    {
        int elemento = seleccion(objetos,usado);
        if(objetos[elemento].second<=capacidad) //Es factible ?
        {
            usado[elemento]=1;
            ganancia+=objetos[elemento].first;
            capacidad-=objetos[elemento].second;
        }
        else
            usado[elemento]=2; 
    }

    cout << "Ganancia: " << ganancia << endl; 
    for(int i = 0; i < usado.size(); i++)
    {
        if(usado[i] == 1)
            cout << "Se mete el objeto de valor " << objetos[i].first << endl; 
    }

    return 0; 
}