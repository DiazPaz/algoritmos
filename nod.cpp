#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

int main(void)
{
    vector<int> NOD(1000001, 2);
    NOD[1] = 1; 
    int num;

    for(int i = 2; i <= 50000; i++)
        for(int j = i*2; j < 1000000; j+=i)
            NOD[j]++;

    vector<int> N; 
    N.push_back(1); 
    int ni = 1;

    do 
    {
        ni = ni + NOD[ni];
        N.push_back(ni);
        // cout << ni << endl; 
    }while(ni < 1000001);

    int a, b; 
    cin >> a >> b; 
    vector<int>::iterator it, it2; 
    it = lower_bound(N.begin(), N.end(), a);
    it2 = upper_bound(N.begin(), N.end(), b);
    it2--;

    // cout << *it << " " << *it2 << endl;
    cout << it2-it+1 << endl;

    return 0; 
}