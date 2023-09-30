#include <bits\stdc++.h>
using namespace std;

/*
    Determine if a 9x9 Sudoku board is valid (no repeats)

    Boolean matrices to store seen values. Check rows, cols, 3x3 sub-boxes

    Time: O(cnt^2)
    Space: O(cnt^2)
    link to simulate the solution
    https://docs.google.com/spreadsheets/d/1WsyJJblD9GIhJIpiD9p8wvrW9aOaWFcegzB58umEiz4/edit?usp=sharing

    problem link : https://leetcode.com/problems/valid-sudoku/  
*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        const int cnt = 9;
        bool row[cnt][cnt] = {false};
        bool col[cnt][cnt] = {false};
        bool sub[cnt][cnt] = {false};
        
        for(int r = 0; r < cnt; ++r){
            for(int c = 0; c < cnt; ++c){
                if(board[r][c] == '.')
                    continue; // if not number pass
                char current = board[r][c];
                int idx = board[r][c] - '0' - 1; //char to num idx
                int area = (r/3) * 3 + (c/3);
                
                //if number already exists
                if(row[r][idx] || col[c][idx] || sub[area][idx]){
                    int x = 10;
                    return false;
                }
                
                row[r][idx] = true;
                col[c][idx] = true;
                sub[area][idx] = true;
            }
        }
        return true;
    }
};

void test_function(){
    vector<vector<char>> test1  = {
                                    {'8','3','.','.','7','.','.','.','.'},
                                    {'6','.','.','1','9','5','.','.','.'},
                                    {'.','9','8','.','.','.','.','6','.'},
                                    {'8','.','.','.','6','.','.','.','3'},
                                    {'4','.','.','8','.','3','.','.','1'},
                                    {'7','.','.','.','2','.','.','.','6'},
                                    {'.','6','.','.','.','.','2','8','.'},
                                    {'.','.','.','4','1','9','.','.','5'},
                                    {'.','.','.','.','8','.','.','7','9'}
                                };
    Solution sol;
    cout << sol.isValidSudoku(test1) << endl;
}

int main(){

    test_function();

return 0;
}
