class Solution {
  public:
    int kthSmallest(vector<vector<int>> &mat, int k) {
        // code here
        int n = mat.size();
        vector<pair<int,pair<int,int>> >temp;
        for(int i=0; i<n; i++){
            temp.push_back(make_pair(mat[i][0], make_pair(i,0)));
        }
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> >pq(temp.begin(),temp.end());
        
        pair<int,pair<int,int>>ans;
        for(int j=0; j<k; j++){
            ans = pq.top();
            pq.pop();
            if(ans.second.second+1<n) pq.push(make_pair(mat[ans.second.first][ans.second.second + 1],make_pair(ans.second.first,ans.second.second + 1)));
        }
        return mat[ans.second.first][ans.second.second];
    }
};
