Q : 733. Flood Fill

class Solution {
    public:
        vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    
            int row = image.size();
            int col = image[0].size();
            int dx[] = {1,0,-1,0};
            int dy[] = {0,1,0,-1};
    
            //1. find the first elment; => image[sr][sc]
            int val = image[sr][sc];
            image[sr][sc] = color;
            queue<pair<int,int>> q;
            q.push({sr,sc});
            
            if (val == color) return image; // Avoid infinite loop
            // 2. BFS
            while(!q.empty()){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                for(int k = 0;k<4;k++ ){
                    int new_r = dx[k]+r;
                    int new_c = dy[k]+c;
    
                    if( new_r>=0 && new_c>=0 && new_r<row && new_c<col && image[new_r][new_c] == val ){
                        image[new_r][new_c] = color;
                        q.push({new_r,new_c});
                    }
                }
            }
            return image;
            
        }
    };
APPROACH : BFS 

GITHUB REPO : 

TC: O(n*m)
SC : O(n*m)
