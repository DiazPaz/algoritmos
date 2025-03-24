#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

int main(void)
{
    int cases, length, ants, antsIn; 
    cin >> cases;
    while(cases--)
    {
        vector<int> antV; 
        cin >> length >> ants; 
        for(unsigned i = 0; i < ants; i++)
        {
            cin >> antsIn; 
            antV.push_back(antsIn);
        }

        sort(antV.begin(), antV.end());

        int mid = length/2; 
        int midAnt; 
        for(midAnt = 0; antV[midAnt] <= mid; midAnt++);
        int longest, shortest;
        
        if(antV[midAnt-1] > length - antV[midAnt])
            shortest = antV[midAnt-1]; 
        else
            shortest = length - antV[midAnt];
            
        if(length - antV[0] > antV[antV.size()-1])
            longest = length - antV[0];
        else 
            longest = antV[antV.size()-1];
    
        cout << shortest << " " << longest << endl;             

    }

    return 0;
}