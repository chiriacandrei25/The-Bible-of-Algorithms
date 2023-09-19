class Solution {
private:
    void ans(vector<vector<char>>& board, vector<vector<char>>& curr, int i, int j, vector<vector<bool>>& col, vector<vector<bool>>& row, vector<vector<bool>>& mat) {
        while(i < 9 && board[i][j] != '.') {
            if (j < 8) j++;
            else {
                j = 0;
                i++;
            }
        }
        if(i == 9) {
            curr = board;
            return;
        }

        for(int k = 1; k <= 9; k++) {
            if(curr.size() > 0) break;
            if(!col[j][k] && !row[i][k] && !mat[3*(i/3) + (j/3)][k]) {
                col[j][k] = true;
                row[i][k] = true;
                mat[3*(i/3) + (j/3)][k] = true;
                board[i][j] = (char)('0'+k);
                ans(board, curr, i, j, col, row, mat);
                col[j][k] = false;
                row[i][k] = false;
                mat[3*(i/3) + (j/3)][k] = false;
                board[i][j] = '.';
            }
        }
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> col(9, vector<bool>(10, false));
        vector<vector<bool>> row(9, vector<bool>(10, false));
        vector<vector<bool>> mat(9, vector<bool>(10, false));
        vector<vector<char>> curr;

        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] != '.') {
                    int x = board[i][j] - '0';
                    row[i][x] = true;
                    col[j][x] = true;
                    mat[3*(i/3) + (j/3)][x] = true;
                }
            }
        }

        ans(board, curr, 0, 0, col, row, mat);
        board = curr;
        return;
    }
};
