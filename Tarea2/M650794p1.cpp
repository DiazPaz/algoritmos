// David Díaz Paz y Puente | 650794
// Doy mi palabra que he realizado esta actividad con integridad académica.
#include <iostream>
#include <vector>
using namespace std;

bool unirTubos(int tuboFinal, vector<int>& tubos) {
    vector<bool> unionesPosibles(tuboFinal + 1, false);
    unionesPosibles[0] = true; 
    
    for(int tubo : tubos) 
        for(int i = tuboFinal; i >= tubo; i--) 
            if(unionesPosibles[i - tubo]) 
                unionesPosibles[i] = true;

    return unionesPosibles[tuboFinal];
}

int main(void) {
    int casos;
    cin >> casos; 
    
    vector<string> resultados;
    
    for(unsigned i = 0; i < casos; i++)
    {    
        int tuboFinal, tuboInventario;
        cin >> tuboFinal >> tuboInventario;
        
        vector<int> tubos(tuboInventario);
        for(int i = 0; i < tuboInventario; ++i) 
            cin >> tubos[i];
        
        if(unirTubos(tuboFinal, tubos))
            resultados.push_back("SI");
        else 
            resultados.push_back("NO");
    }
    
    for(const string& resultado : resultados)
        cout << resultado << endl;
    
    return 0;
}