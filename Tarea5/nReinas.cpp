#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
int minimum;

void minMoves(const vector<int> &queens, const vector<int> &queensCopy, int &moves)
{
    moves = 0;
    for(unsigned i = 0; i < queens.size(); i++)
        if(queens[i] != queensCopy[i])
            moves++;
    minimum = min(minimum, moves);
}

bool threats(const vector<int> &queens, int col, int rows)
{
    int previousRow;
    for(int previousCol = 0; previousCol < col; previousCol++)
    {
        previousRow = queens[previousCol];
        if(rows == previousRow || (previousRow-previousCol == rows-col) || (previousRow+previousCol == rows+col))
            return true; 
    }
    return false; 
}

void backtracking(vector<int> &queens, const vector<int> &queensCopy, int col, int &moves)
{
    if(col == queens.size())
    {
        minMoves(queens,queensCopy,moves);
        return;
    }
    
    for(int rows = 0; rows < queens.size(); rows++)
    {
        if(!threats(queens, col, rows))
        {
            queens[col] = rows; 
            backtracking(queens, queensCopy, col+1, moves);
        }
    }

    queens[col] = queensCopy[col];
}

int main(void)
{
    int n, aux; 
    while(cin >> n && n != 0)
    {
        vector<int> queens(n);
        vector<int> queensCopy(n);
        int moves = 0;
        minimum = n;

        for(unsigned i = 0; i < n; i++)
        {
            cin >> queens[i];
            queens[i]-=1; 
            queensCopy[i] = queens[i];
        }

        backtracking(queens,queensCopy,0,moves);
        cout << minimum << endl;
    }

    return 0;
}