#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int S[9][9];
int R[9][9];

int contador;

bool posible(int n, int fil, int col)
{
   for (int x = 0; x < 9; x++)
   {
      if (S[fil][x] == n)
         return false;
      if (S[x][col] == n)
         return false;
   }
   int Cc = (col / 3) * 3;
   int Cf = (fil / 3) * 3;
   for (int f = Cf; f < Cf + 3; f++)
      for (int c = Cc; c < Cc + 3; c++)
         if (S[f][c] == n)
            return false;
   return true;
}

void sudoku(int fil, int col)
{
   bool encontrado = false;
   int f, c;
   for (f = fil; f < 9 && !encontrado; f++)
      for (c = 0; c < 9 && !encontrado; c++)
         if (S[f][c] == 0)
            encontrado = true;
   f--;
   c--;
   if (!encontrado)
   {
      contador++;
      // SOLUCION
      for (int i = 0; i < 9; i++)
         for (int j = 0; j < 9; j++)
            R[i][j] = S[i][j];
   }
   for (int n = 1; n <= 9; n++)
   {
      if (posible(n, f, c))
      {
         S[f][c] = n;
         sudoku(f, c);
         S[f][c] = 0;
      }
   }
}

int main()
{
   int n;
   char d;
   cin >> n;
   cin.ignore();
   for (int x = 0; x < n; x++)
   {
      for (int f = 0; f < 9; f++)
      {
         for (int c = 0; c < 9; c++)
         {
            cin >> d;
            S[f][c] = d - '0';
         }
         cin.ignore();
      }
      contador = 0;
      sudoku(0, 0);
      if (contador == 1)
      {
         cout << "------------------" << endl;
         for (int i = 0; i < 9; i++)
         {
            cout << "|";
            for (int j = 0; j < 9; j++)
            {
               cout << R[i][j];
               if ((j + 1) % 3 == 0)
                  cout << "|";
               else
                  cout << " ";
            }
            cout << endl;
            if ((i + 1) % 3 == 0)
               cout << "------------------" << endl;
         }
      }
      if (contador > 1)
         cout << "Tiene " << contador << " soluciones" << endl;
   }
}