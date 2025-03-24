#include <iostream>
#include <vector>

using namespace std;

int posCheck(vector<vector<int>>& board, vector<int> &queenPos)
{
    int moves = 0; 
    for(int i = 0; i < board.size(); i++)
    {
        if(board[i][queenPos[i]] == 0)
            moves++;
    }
    return moves;
}

bool horizontalThreat(const vector<vector<int>>& board, int row, int col) 
{
    for (int j = 0; j < col; j++) 
        if (board[row][j] == 1) return true;
    return false;
}

bool diagonalNegThreat(const vector<vector<int>>& board, int row, int col) 
{
    for (int i = row, j = col; i < board.size() && j >= 0; i++, j--)
        if (board[i][j] == 1) return true;
    return false;
}

bool diagonalPosThreat(const vector<vector<int>>& board, int row, int col) 
{
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) 
        if (board[i][j] == 1) return true;
    return false;
}

bool isSafe(const vector<vector<int>>& board, int row, int col) 
{
    return !horizontalThreat(board, row, col) && 
           !diagonalNegThreat(board, row, col) && 
           !diagonalPosThreat(board, row, col);
}

bool placeQueens(vector<vector<int>>& board, vector<int> &queenPos, int col) 
{
    int n = board.size();
    if (col >= n) 
    {
        cout << posCheck(board, queenPos) << endl;
        return true; 
    }
    
    for (int row = queenPos[col]; row < n; row++) 
    {
        if (!(horizontalThreat(board, row, col) && diagonalNegThreat(board, row, col) && diagonalPosThreat(board, row, col))) 
        {
            board[row][col] = 1;
            if (placeQueens(board, queenPos, col + 1)) 
                return true;
            board[row][col] = 0; 
        }
    }
    return false;
}

int main() {

    int n = 1, pos; 
    cin >> n;
    while(n != 0)
    {   
        vector<vector<int>> board(n, vector<int>(n, 0));
        vector<int> queenPos(n);
        while(n--)
        {
            cin >> pos; 
            queenPos.push_back(pos);
        }
        placeQueens(board, queenPos, 0);
        cin >> n;
    } 

    return 0;
}
