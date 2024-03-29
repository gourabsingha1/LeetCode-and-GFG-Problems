class Solution {
public:
    vector<int> topoSort(int n, vector<vector<int>> &adj){
        vector<int> res, indegree(n, 0); // indegree = no. of arrows directed towards
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            for(auto &it : adj[i]){
                indegree[it]++;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int i = q.front();
            q.pop();
            res.push_back(i);
            for(auto &it : adj[i]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        return res;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;
        vector<vector<int>> adj(numCourses);
        for (int i = 0; i < prerequisites.size(); i++)
        {
            int u = prerequisites[i][0], v = prerequisites[i][1];
            adj[v].push_back(u);
        }
        res = topoSort(numCourses, adj);
        if(res.size() != numCourses){
            return {};
        }
        return res;
    }
};