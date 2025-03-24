// David Díaz Paz y Puente | 650794
// Doy mi palabra que he realizado esta actividad con integridad académica.
#include <iostream>

using namespace std;

int main() {
    int P, A, B, C;
    
    while (cin >> P >> A >> B >> C) {
        if (P == 0 && A == 0 && B == 0 && C == 0) break;

        int total_degrees = 0;

        total_degrees += 720 + (((P - A + 40) % 40) + 40) * 9 + 360 + (((B - A + 40) % 40) + ((B - C + 40) % 40)) * 9;

        cout << total_degrees << endl;
    }

    return 0;
}
