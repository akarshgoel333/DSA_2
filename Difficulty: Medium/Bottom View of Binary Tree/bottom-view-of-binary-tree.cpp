/*
Definition for Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    void find(Node* root, int &l, int &r, int pos){
        if(!root) return;
        l = min(l,pos);
        r = max(r,pos);
        find(root->left,l,r,pos-1);
        find(root->right,l,r,pos+1);
    }
    void solve(Node* root, vector<int> &ans, vector<int> &lvl, int pos, int level){
        if(!root) return;
        if(lvl[pos]<=level){
            ans[pos] = root->data;
            lvl[pos] = level;
        }
        solve(root->left,ans,lvl,pos-1,level+1);
        solve(root->right,ans,lvl,pos+1,level+1);
    }
    vector<int> bottomView(Node *root) {
        // code here
        int l = 0, r = 0;
        find(root,l,r,0);
        vector<int>ans(r-l+1,0);
        vector<int>lvl(r-l+1,INT_MIN);
        solve(root,ans,lvl,-l,0);
        return ans;
    }
};