class Solution{
private: 
    void bfs(int i, int j, int n, int m, vector<vector<char>> &grid, vector<vector<int>> &visited){
        visited[i][j] = 1;
        queue<pair<int, int>> q;
        q.push({i, j});

        int drow[4] = {-1, 0, 1, 0};
        int dcol[4] = {0, 1, 0, -1};


        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(int k=0; k<4; k++){
                int newRow = row + drow[k];
                int newCol = col + dcol[k];

                if(newRow>=0 && newRow<n && newCol>=0 && newCol<m && grid[newRow][newCol] == '1' && !visited[newRow][newCol]){
                    visited[newRow][newCol] = 1;
                    q.push({newRow, newCol});
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>> &grid){
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        int count = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    count++;
                    bfs(i, j, n, m, grid, visited);
                }
            }
        }
        return count;
    }
};
