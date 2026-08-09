class Solution {
private:
    bool bfs(int index, vector<vector<int>> &graph, vector<int> &color){
        color[index] = 0;
        queue<int> q;
        q.push(index);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int it: graph[node]){
                // not visited or colored till now
                if(color[it] == -1){
                    color[it] = !color[node];
                    q.push(it);
                }
                // if it is already visited
                else if(color[it] == color[node]){
                    return false;
                }
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V, -1);

        bool ans;
        for(int i=0; i<V; i++){
            if(color[i] == -1){
                ans = bfs(i, graph, color);
                if(!ans){
                    return false;
                    break;
                }
            }
        }
        return true;
    }
};