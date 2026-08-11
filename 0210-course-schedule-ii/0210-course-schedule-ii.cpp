class Solution {
public:
    vector<int> findOrder(int N, vector<vector<int>>& arr) {
        // creating the adjacency list 
        vector<vector<int>> adj(N);
        for(int i=0; i<arr.size() ; i++){
            int u = arr[i][0];
            int v = arr[i][1];

            adj[v].push_back(u);
        }

        // performing the toplogical sort, if all the vertices are included in that, then all the courses will be finished.

        vector<int> inDegree(N, 0);
        for(int i=0; i<N; i++){
            for(int it: adj[i]){
                inDegree[it]++;
            }
        }

        queue<int> q;
        for(int i=0; i<N;i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }

        vector<int> ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(int it: adj[node]){
                inDegree[it]--;
                
                if(inDegree[it] == 0){
                    q.push(it);
                }
            }
        }

        if(ans.size() == N) return ans;
        return {};
    }
};