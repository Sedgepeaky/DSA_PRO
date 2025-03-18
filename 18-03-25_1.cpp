VALID SUDOKU

class Solution {
    public:
        bool isValidSudoku(vector<vector<char>>& board) {
    
            // 1. Check for each row
          
            for(int i = 0 ; i<9;i++){
                vector<int> vis(10,0);
    
                // access each col
                for(int j = 0 ; j<9;j++){
                    if(board[i][j] != '.'){
                        int num = board[i][j] - '0';  // 1 and 0 (31-30 = 1)
                        if (vis[num]) return false;  
                        vis[num] = 1;
                    }
                }
            }
    
            // 2. check for each col
            for(int j = 0 ; j<9;j++){
                vector<int> vis(10,0);
    
                // access each col
                for(int i = 0 ; i<9;i++){
                    if(board[i][j] != '.'){
                        int num = board[i][j] - '0';
                        if (vis[num]) return false;  // Duplicate found
                        vis[num] = 1;
                    }
                }
            }
            // 3. CHECK FOR EACH BOX
            for (int row = 0; row < 9; row += 3) {   
                for (int col = 0; col < 9; col += 3) { 
                    unordered_set<char> seen;
                
                    for (int i = 0; i < 3; i++) {    
                        for (int j = 0; j < 3; j++) {
                            char num = board[row + i][col + j]; 
                            if (num != '.' && seen.count(num)) {
                                return false; 
                            }
                            seen.insert(num);
                        }
                    }
                }
            }
    
            return true;
        }
    };