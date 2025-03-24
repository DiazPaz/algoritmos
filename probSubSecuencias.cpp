#include <iostream>
#include <string>
using namespace std; 

int main(void)
{
    int pos, n = 10, j = 0, k = 0, m = 1, post, dif, pre, sumaDigitos = 1; 
    string serie = "";
    cin >> pos; 

    while(true)
    {
        pre = m; 

        m += j; 
        j += sumaDigitos;
        k++;
        if(k%n == 0)
        { 
            n*=10; 
            sumaDigitos++;
            j++;
        }
        
        post = m;
        
        // cout << k << " " << j << " " << m << "\t" << pre << " " << post << endl; 
        
        if(pos < post && pos >= pre )
        {
            dif = pos - pre;
            if(dif == 0)
                cout << 1 << endl;
            else if(dif == 1)
                cout << 2 << endl;
            else if(dif >= 10)
                for(int i = 1; i <= dif; i++)
                    serie += to_string(i);      
            else
                for(int i = 1; i <= dif+1; i++)
                    serie += to_string(i);     
            cout << serie.back() << endl; 
            return false;
        }
    }
    
    return 0; 
}