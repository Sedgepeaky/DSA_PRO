994. Rotting Oranges

class Solution {
    public:
        int orangesRotting(vector<vector<int>>& grid) {
            int r = grid.size();
            int c = grid[0].size();
            int time = 0;
            int fresh=0;
    
            int dx[] = {1,0,-1,0};
            int dy[] = {0,1,0,-1};
            queue<pair<int,int>> q;
    
            // first roten orange
            for(int i = 0; i<r;i++){
                for(int j = 0 ; j<c;j++){
                    if(grid[i][j] == 2){
                        q.push({i,j});
                       
                    }
                    else if(grid[i][j] == 1){
                        fresh++;
                    }
                }
            }
            if (fresh == 0) return 0;
    
            // bfs
            while(!q.empty()){
                int size = q.size();
                bool rotten = false;
                for(int l = 0 ; l<size;l++){
    
                    auto[i,j] = q.front();
                    q.pop();
                    for(int k = 0 ; k<4;k++){
                        int new_r = i+dx[k];
                        int new_c = j+dy[k];
    
                        if(new_r>=0 && new_r<r && new_c>=0 && new_c<c && grid[new_r][new_c] == 1){
                            grid[new_r][new_c] = 2; // rotten
                            q.push({new_r,new_c});
                            fresh--;
                            rotten = true;
                        } 
                    
                    }
                }
                if(rotten) time++;
            }
    
            return (fresh == 0) ? time : -1;
            
        }
    };
    Approach : BFS

    GITHUB REPO : 

    TC : O(n*m)
    SC: O(n*m)