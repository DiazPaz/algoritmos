#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool myfunction(pair<int, int> programador1, pair<int, int> programador2){ 
    return programador1.second > programador2.second; 
}

int main(){
    int N;
    while(cin >> N && N!=0){
        int tiempo=0, tiempoTotal=0;
        vector<pair<int, int> > programadores;
        for (int i=0; i<N; i++){
            int I, T;
            cin >> I >> T;
            programadores.push_back(make_pair(I, T));
        }
        sort(programadores.begin(), programadores.end(), myfunction);
        for(int i=0; i<N; i++){
            tiempo+=programadores[i].first;
            if(tiempo+programadores[i].second>tiempoTotal){
                tiempoTotal=tiempo+programadores[i].second;
            }
        }
        cout << endl;
        cout << tiempoTotal;
    }
    return 0;
}