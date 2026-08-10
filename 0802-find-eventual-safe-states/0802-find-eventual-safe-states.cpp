class Solution {
private:
    void topoSort(int V, vector<vector<int>> &adjList, vector<int> &ans){
        vector<int> inDegree(V, 0);
        for(int i=0; i<V; i++){
            for(int it : adjList[i]){
                inDegree[it]++;
            }
        }

        queue<int> q;
        for(int i=0; i<V; i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(int it: adjList[node]){
                inDegree[it]--;

                if(inDegree[it] == 0){
                    q.push(it);
                }
            }
        }
        // return ans;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
       // reverse the graph 
        vector<vector<int>> adjList(V);
        for(int i=0; i<V; i++){
            for(int it : graph[i]){
                adjList[it].push_back(i);
            }
        }

        vector<int> ans;
        topoSort(V, adjList, ans);

        sort(ans.begin(), ans.end());
        return ans;
    }
};