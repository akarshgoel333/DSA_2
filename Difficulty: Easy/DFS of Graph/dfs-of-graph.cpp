class Solution {
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        vector<int>ans;
        int n = adj.size();
        vector<bool>vis(n,false);
        stack<int>s;
        s.push(0);
        int node;
        while(!s.empty()){
            node=s.top();
            s.pop();
            if(!vis[node]){
                vis[node]=true;
                ans.push_back(node);
                for(int j=adj[node].size()-1; j>=0; j--){
                    if(!vis[adj[node][j]]){
                        s.push(adj[node][j]);
                    }
                }
            }
        }
        return ans;
    }
};