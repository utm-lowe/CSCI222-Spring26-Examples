#include <iostream>
#include <vector>

using namespace std;

vector<vector<bool>> makeBoard(int n);
void printBoard(const vector<vector<bool>>& board);
bool isValid(const vector<vector<bool>>& board);
bool isSolved(const vector<vector<bool>>& board);
bool solve(vector<vector<bool>> & board);

int main()
{
    int n;

    // get n
    cout << "Enter the size of the board (n): ";
    cin >> n;

    // make the board
    vector<vector<bool>> board = makeBoard(n);

    if(solve(board)) {
        printBoard(board);
    } else {
        cout << "Impossible" << endl;
    }
}


vector<vector<bool>> makeBoard(int n)
{
    vector<vector<bool>> board(n, vector<bool>(n, false));
    return board;
}


void printBoard(const vector<vector<bool>>& board)
{
    for (const auto& row : board)
    {
        for (bool cell : row)
        {
            cout << (cell ? "Q " : ". ");
        }
        cout << endl;
    }
}

// Returns true if no two queens threaten each other
bool isValid(const vector<vector<bool>>& board)
{
    int n = board.size();

    // Check rows and columns
    for (int i = 0; i < n; ++i)
    {
        int rowCount = 0;
        int colCount = 0;
        for (int j = 0; j < n; ++j)
        {
            if (board[i][j]) rowCount++;
            if (board[j][i]) colCount++;
        }
        if (rowCount > 1 || colCount > 1) return false;
    }

    // Check diagonals
    for (int d = -n + 1; d < n; ++d)
    {
        int diag1Count = 0;
        int diag2Count = 0;
        for (int i = max(0, d), j = max(0, -d); i < n && j < n; ++i, ++j)
        {
            if (board[i][j]) diag1Count++;
            if (board[i][n - 1 - j]) diag2Count++;
        }
        if (diag1Count > 1 || diag2Count > 1) return false;
    }

    return true;
}


bool isSolved(const vector<vector<bool>>& board)
{
    int n = board.size();

    if(!isValid(board)) return false;

    // count the queens
    int count = 0;
    for(auto& row : board) {
        for(bool cell : row) {
            if(cell) count++;
        }
    }

    return count == n;
}


bool solve(vector<vector<bool>> & board)
{
    // base conditions
    if(isSolved(board)) return true;
    if(!isValid(board)) return false;

    // extension (recursively)
    for(int i=0; i<board.size(); i++) {
        for(int j=0; j<board[i].size(); j++) {
            // place a queen on the copy
            auto boardCopy = board;

            if(boardCopy[i][j]) continue;

            boardCopy[i][j] = true;

            if(solve(boardCopy)) {
                board = boardCopy;
                return true;
            }
        }
    }

    // exhausted all possibilities
    return false;
}