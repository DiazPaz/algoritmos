/* 
David Díaz Paz y Puente 650794
Rebeca Laredo González 613587
Damos nuestra palabra que hemos realizado esta actividad con integridad académica.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool myfunction(int i, int j){
    return i > j; 
}

int main(){
    int n, u, d;
    while(cin >> n >> u >> d){ 
        vector<int> matutino;
        vector<int> vespertino;
        for(int i=0; i<n; ++i){
            int mat;
            cin >> mat;
            matutino.push_back(mat);
        }
        for(int i=0; i<n; ++i){
            int vet;
            cin >> vet;
            vespertino.push_back(vet);
        }
        sort(matutino.begin(), matutino.end());
        sort(vespertino.begin(), vespertino.end(), myfunction);
        int costoAdicional=0;
        cout << endl;
        for(int i=0; i<n; ++i){
            int total=matutino[i]+vespertino[i];
            if(total>u){
                costoAdicional+=(total-u)*d;
            }
        }
        cout << costoAdicional;
    }
    return 0;
}