class Solution {
  public:
    void solve(vector<int> &arr, int mini, int maxi, int &idx){
        if(idx==arr.size()) return;
        if(arr[idx]>=maxi || arr[idx]<=mini) return;
        int root = arr[idx++];
        solve(arr,mini,root,idx);
        solve(arr,root,maxi,idx);
        return;
    }
    bool canRepresentBST(vector<int> &arr) {
        // code here
        int idx = 0;
        solve(arr,INT_MIN,INT_MAX,idx);
        if(idx==arr.size()) return true;
        return false;
    }
};