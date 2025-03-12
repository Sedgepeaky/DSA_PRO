1091. Shortest Path in Binary Matrix

class Solution {
    public:
        int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    
    // IF SOURCE IS 1 SO THERE'S NO POINT:
            if(grid[0][0] == 1){
                return -1;
            }
            int n = grid.size();
            priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    
            vector<vector<int>> dis(n, vector<int>(n, 1e9));
            pq.push({0,{0,0}});
            dis[0][0] = 0;
    
    
    
            vector<pair<int, int>> directions = {
                {1, 0}, {0, 1}, {-1, 0}, {0, -1}, // Up, Down, Left, Right
                {1, 1}, {1, -1}, {-1, 1}, {-1, -1} // Diagonals
            };
    
            while(!pq.empty()){
                auto [distance, cell] = pq.top();
                auto [r, c] = cell; 
               
                pq.pop();
    
                for(auto [dr,dc] : directions){
                    int nr = dr+r;
                    int nc = dc + c;
    
                    if(nr<n && nr>=0 && nc<n && nc>=0 && grid[nr][nc] == 0){
                        if(distance + 1 < dis[nr][nc]){
                            dis[nr][nc] = distance + 1;
                            pq.push({distance +1 ,{nr,nc}});
                        }
                    }
                }
            }
            return dis[n-1][n-1] != 1e9 ? dis[n-1][n-1]+1 : -1;
            
        }
    };

    TC : O(n^2(logn))
    SC : O(n^2)
    Approach : Dijkstra Algorithm