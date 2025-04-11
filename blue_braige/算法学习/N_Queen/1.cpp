#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    vector<vector<string>> results;
    vector<int> d;
    
    bool isLegal(int row, int col, int n) {
        for (int i = 0; i < row; ++i) {
            if (d[i] == col || i - d[i] == row - col || i + d[i] == row + col) {
                return false;
            }
        }
        return true;
    }
    
    void searchChilds(int row, int n, vector<string>& board) {
        if (row == n) {
            results.push_back(board);
            return;
        }
        
        for (int col = 0; col < n; ++col) {
            if (isLegal(row, col, n)) {
                d[row] = col;
                board[row][col] = 'Q';
                searchChilds(row + 1, n, board);
                board[row][col] = '.';
                d[row] = 0;
            }
        }
    }
    
public:
    vector<vector<string>> solveNQueens(int n) {
        results.clear();
        d.resize(n, 0);
        
        vector<string> board(n, string(n, '.'));
        
        searchChilds(0, n, board);
        
        return results;
    }
};