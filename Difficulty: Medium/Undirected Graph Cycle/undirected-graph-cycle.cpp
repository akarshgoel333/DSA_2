class Solution {
  public:
    bool cyc(int node, int parent,vector<vector<int>>& adj, vector<bool> &vis){
        vis[node] = true;
        for(auto j: adj[node]){
            if(!vis[j]){
                if(cyc(j,node,adj,vis)) return true;
            }
            else if(j!=parent) return true;
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<bool>vis(V,false);
        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(cyc(i,-1,adj,vis)) return true;
            }
        }
        return false;
    }
};