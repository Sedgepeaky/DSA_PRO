130. Surrounded Regions
class Solution {
    private:
        void dfs(int i , int j ,vector<vector<int>> &vis,vector<vector<char>>& board ){
            vis[i][j] = 1;
            int dx[] = {0,1,0,-1};
            int dy[] = {1,0,-1,0};
    
            for(int k = 0 ; k<4;k++){
                int n_r = dx[k]+i;
                int n_c = dy[k] +j;
    
                if(n_r>=0 ; n_r<board[n_r][n_c] == '0') dfs(i,j,vis,board);
            }
        }
    public:
        void solve(vector<vector<char>>& board) {
            int n = board.size();
            int m = board[0].size();
    
            vector<vector<int>> vis(n,vector<int>(m,0));
    
        // rows
            for(int j = 0 ; j<m;j++){
                if(!vis[0][j] && board[0][j] == '0'){
                    dfs(0,j,vis,board);
    
                }
                else if(!vis[n-1][j] && board[n-1][j] == '0'){
                    dfs(n-1,j,vis,board);
    
                }
            }
        // for colmn
            for(int i = 0 ; i<n ; i++){
                if(!vis[i][0] && board[i][0] == '0'){
                    dfs(i,0,vis,board);
    
                }
                else if(!vis[n-1][j] && board[n-1][j] == '0'){
                    dfs(i,m-1,vis,board);
                }
            }
    
            for(int i = 0 ; i<n ; i++){
                for(int j = 0 ; j<m ;j++){
                    if(!vis[i][j] && board[i][j] == '0'){
                        board[i][j] = 'X';
                    }
                }
            }
            return board;
        }
    };
    TC : O(m*n)
    SC : O(m*n)

    Approaxch : DFS