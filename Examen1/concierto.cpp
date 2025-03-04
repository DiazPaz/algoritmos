#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool busquedaBinaria(const vector<int>& costos, int izq, int der, int objetivo) {
    while (izq <= der) {
        int mid = izq + (der - izq) / 2;
        if (costos[mid] == objetivo) {
            return true;
        } else if (costos[mid] < objetivo) {
            izq = mid + 1;
        } else {
            der = mid - 1;
        }
    }
    return false;
}

void resolverCaso(vector<int>& costos, int dineroJuntado) {
    sort(costos.begin(), costos.end());

    int mejorA = 0, mejorB = 0;

    for (int i = 0; i < costos.size(); i++) {
        int complemento = dineroJuntado - costos[i];
        
        // Buscar el complemento en la parte derecha del arreglo
        if (busquedaBinaria(costos, i + 1, costos.size() - 1, complemento)) {
            mejorA = costos[i];
            mejorB = complemento;
        }
    }

    cout << mejorA << " " << mejorB << endl;
}

int main() {
    int casos, numBoletos, costo, dineroJuntado;
    cin >> casos;

    while (casos--) {
        cin >> numBoletos;
        vector<int> costos(numBoletos);

        for (int i = 0; i < numBoletos; i++) {
            cin >> costos[i];
        }

        cin >> dineroJuntado;
        resolverCaso(costos, dineroJuntado);
    }

    return 0;
}
