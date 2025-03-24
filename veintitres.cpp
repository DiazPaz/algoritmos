#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int opera(int a,int b,int op)
{
   if(op==0)
      return a-b;
   if(op==1)
      return a+b;
   return a*b;
}

bool S23(int i,vector<int> &op,vector<int> &A)
{
   int r;
   if(i>4)
   {
      r=opera(A[0],A[1],op[0]);
      r=opera(r,A[2],op[1]);
      r=opera(r,A[3],op[2]);
      r=opera(r,A[4],op[3]);
      //Evaluar
      if(r==23)
         return true;
      return false;
   }
   for(int x=0;x<3;x++) //por cada operador (0=-,1=+,2=*)
   {
      op.push_back(x);
      if(S23(i+1,op,A)==true)
         return true;
      op.pop_back();
   }
   return false;
}

int main() {
   vector<int> op;
   vector<int> A(5);
   for(int i=0;i<5;i++)
      cin>>A[i];
   if(S23(0,op,A))
      cout<<"Possible";
   else
      cout<<"Impossible";
}