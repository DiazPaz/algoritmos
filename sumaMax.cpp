#include <iostream>
#include <algorithm>
#include <climits> // Para usar INT_MIN
using namespace std;

// Encuentra la máxima suma cruzando el medio
int maxCrossingSum(int arr[], int l, int m, int r) {
    int left_sum = INT_MIN, right_sum = INT_MIN, sum = 0;
    
    // Máxima suma del lado izquierdo
    for (int i = m; i >= l; i--) {
        sum += arr[i];
        left_sum = max(left_sum, sum);
    }
    
    sum = 0;
    // Máxima suma del lado derecho
    for (int i = m + 1; i <= r; i++) {
        sum += arr[i];
        right_sum = max(right_sum, sum);
    }
    
    return left_sum + right_sum; // Mejor suma que cruza el medio
}

// Función recursiva para encontrar la máxima suma de subarreglo
int maxSubarraySum(int arr[], int l, int r) {
    if (l == r) return arr[l]; // Caso base: un solo elemento

    int m = (l + r) / 2;
    
    int left_max = maxSubarraySum(arr, l, m); // Mejor suma en la izquierda
    int right_max = maxSubarraySum(arr, m + 1, r); // Mejor suma en la derecha
    int cross_max = maxCrossingSum(arr, l, m, r); // Mejor suma cruzando el medio
    
    return max({left_max, right_max, cross_max}); // Mejor de los tres casos
}

int main() {
    int arr[] = {2, -4, 1, 9, -6, 7, -3};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int max_sum = maxSubarraySum(arr, 0, n - 1);
    
    cout << "Máxima suma de subarreglo: " << max_sum << endl;
    return 0;
}
