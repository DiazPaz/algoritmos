// David Díaz Paz y Puente | 650794
// Doy mi palabra que he realizado esta actividad con integridad académica. 

#include <iostream>
#include <string>
using namespace std; 

int stringToInt(string input)
{
    int term = 0;
    for(unsigned i = 0; i < input.length(); i++)
    {
        if(islower(input[i]))
            term = term + int(input[i])-96;
        else if(isupper(input[i]))  
            term = term + int(input[i])-64;
    }
    return term;
}

int sumDigits(int initVal)
{
    int sum = 0; 
    if(initVal < 10)
        return initVal; 

    while(initVal != 0)
    {
        int last = initVal%10;
        sum += last; 
        initVal /= 10; 
    }
    return sumDigits(sum);
}

int main(void)
{
    int casos, num1, num2;
    double div1, div2;
    string input1, input2;

    cin >> casos;
    cin.ignore();

    for(unsigned i = 0; i < casos; i++)
    {
        
        getline(cin, input1);
        getline(cin, input2); 

        if(!(input1.length() <= 50 && input2.length() <= 50))
            break;

        num1 = stringToInt(input1);
        num2 = stringToInt(input2);
        
        div1 = sumDigits(num1);
        div2 = sumDigits(num2);

        if(div2 > div1)
            cout << (div1 / div2)*100 << endl;
        else
            cout << (div2 / div1)*100 << endl;
    }

    return 0; 
}
