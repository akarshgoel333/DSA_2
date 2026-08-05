/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
  public:
    void find(Node* root, int &l, int pos){
        if(!root) return;
        l = max(l,pos);
        find(root->left,l,pos+1);
        find(root->right,l,pos);
    }
    void preorder(Node* root, vector<vector<int>> &arr, int pos){
        if(!root) return;
        arr[pos].push_back(root->data);
        preorder(root->left,arr,pos+1);
        preorder(root->right,arr,pos);
    }
    vector<int> diagonal(Node *root) {
        // code here
        int l=INT_MIN;
        find(root,l,0);
        vector<vector<int>>arr(l+1);
        preorder(root,arr,0);
        vector<int>ans;
        for(int i=0; i<arr.size(); i++){
            for(int j=0; j<arr[i].size(); j++){
                ans.push_back(arr[i][j]);
            }
        }
        return ans;
    }
};