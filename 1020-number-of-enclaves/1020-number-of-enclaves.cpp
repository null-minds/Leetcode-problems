class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // instead of running 2 for loop O(n*m) for boudary region, we can do it in O(n+m)

        // q for storing the row and col
        queue<pair<int, int>> q;  
        for(int i=0; i<n; i++){
            if(grid[i][0] == 1) q.push({i, 0}); grid[i][0] = 0; 
            if(grid[i][m-1] == 1) q.push({i, m-1}); grid[i][m-1] = 0;
        }

        for(int i=0; i<m; i++){
            if(grid[0][i] == 1) q.push({0, i}); grid[0][i] = 0;
            if(grid[n-1][i] == 1) q.push({n-1, i}); grid[n-1][i] = 0;
        }
        
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i =0; i<4; i++){
                int newR = r + dr[i];
                int newC = c + dc[i];

                if(newR>=0 && newR<n && newC>0 && newC<m && grid[newR][newC] == 1){
                    grid[newR][newC] = 0;
                    q.push({newR, newC});
                }
            }
        }

        int count = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    count++;
                }
            }
        }
        return count;
    }
};