/* Structure of a Binary Search Tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
}; */

class Solution {
  public:
    void solve(Node* root, vector<int>&arr){
        if(!root) return;
        solve(root->left,arr);
        arr.push_back(root->data);
        solve(root->right,arr);
    }
    vector<int> merge(Node *r1, Node *r2) {
        // code here
        vector<int>a,b;
        solve(r1,a);
        solve(r2,b);
        vector<int>ans;
        int i=0, j=0, k=0;
        while(i<a.size() && j<b.size()){
            if(a[i]<=b[j]) ans.push_back(a[i++]);
            else ans.push_back(b[j++]);
        }
        while(i<a.size()){
            ans.push_back(a[i++]);
        }
        while(j<b.size()){
            ans.push_back(b[j++]);
        }
        return ans;
    }
};