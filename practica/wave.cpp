#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; 

int main(void)
{
    int N, Q, raiz, x;
    cin >> N >> Q;

    vector<int> raices(N);
    for(unsigned i = 0; i < N; i++)
    {
        cin >> raiz; 
        raices.push_back(raiz);
    }

    sort(raices.begin(), raices.end());

    for (int i = 0; i < Q; i++) {
        int x;
        cin >> x;

        // Binary search to find the position of x among the roots
        auto it = lower_bound(raices.begin(), raices.end(), x);

        if (it != raices.end() && *it == x) {
            cout << "0" << endl;
        } else {
            // Number of roots greater than x
            int greater_count = raices.end() - it;
            // Determine the sign based on the count of greater roots
            cout << (greater_count % 2 == 0 ? "POSITIVE" : "NEGATIVE") << endl;
        }
    }

    // fUERZA bRUTA
    // int a, x, Q, N, mult = 1;
    // vector<int> As;
    // vector<int> Xs;
    // vector<int> res;
    
    // cin >> N >> Q; 

    // for(unsigned i = 0; i < N; i++)
    // {
    //     cin >> a;
    //     As.push_back(a);
    // }

    // for(unsigned i = 0; i < Q; i++)
    // {
    //     cin >> x;
    //     Xs.push_back(x);
    // }    

    // const unsigned xSize = Xs.size(), aSize = As.size();

    // for(unsigned i = 0; i < xSize; i++)
    // {
    //     for(unsigned j = 0; j < aSize; j++)
    //     {
    //         mult *= (Xs[i] - As[j]);
    //     }
    //     res.push_back(mult);
    //     mult = 1;
    // }
    
    // for(int i : res)
    // {
    //     if(i > 0)
    //         cout << "POSITIVO" << endl;
    //     else if(i < 0)
    //         cout << "NEGATIVO" << endl;
    //     else
    //         cout << 0 << endl;
    // }

    return 0;
}