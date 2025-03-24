#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std; 

int factorial(int n)
{
    if(n == 1 || n == 0)
        return n; 
    return n*factorial(n-1);
}

int MCD(int a, int b)
{
    if(b == 0)
        return a; 
    return MCD(b, a%b);
}

int fibonacci(int n)
{


}

int main(void)
{


    return 0;
}