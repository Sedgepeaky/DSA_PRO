


542. 01 Matrix
class Solution {
    public:
        vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    
            int row = mat.size();
            int col = mat[0].size();
            vector<vector<int>> vis(row,vector<int>(col,0));
            vector<vector<int>> dis(row,vector<int>(col,0));
            int dx[] = {0,1,0,-1};
            int dy[] = {1,0,-1,0};
            queue<pair<pair<int,int> , int> > q;
    // 1. FIND ELEMENTS
    
            for(int i = 0;i<row;i++){
                for(int j = 0; j<col;j++){
                    if(mat[i][j] == 0){
                        q.push({{i,j},0});
                        vis[i][j] = 1;
                    }
                    else{
                        vis[i][j] = 0;
                    }
                }
            }
            
          
    //2.BFS
            while(!q.empty()){
                
                int r = q.front().first.first;
                int c = q.front().first.second;
                int steps = q.front().second;
                q.pop();
                dis[r][c] = steps;
    
                
    
                for(int k = 0 ; k<4;k++){
                    int new_r = dx[k] + r;
                    int new_c = dy[k] + c;
    
                    if(new_r >= 0 && new_r<row && new_c>=0 && new_c<col && vis[new_r][new_c]==0){
                        q.push({{new_r,new_c},steps+1});
                        vis[new_r][new_c] = 1;
                    }
                }
            }
            return dis;
    
            
        }
    };

    TC : O(m*n)
    SC : O(m*n)
    
    Approach : BFS