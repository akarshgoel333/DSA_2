class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        int n = adj.size();
        queue<int>q;
        vector<int>ans;
        vector<bool>vis(n,false);
        q.push(0);
        vis[0] = true;
        int node;
        while(!q.empty()){
            node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto j: adj[node]){
                if(!vis[j]){
                    q.push(j);
                    vis[j]=true;
                }
            }
        }
        return ans;
    }
};