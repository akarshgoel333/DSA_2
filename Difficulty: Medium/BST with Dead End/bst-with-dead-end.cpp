/* Tree Node structure
class Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){
        data = x;
        left = right = nullptr;
    }
};*/
class Solution {
  public:
    void solve(Node* root, int mini, int maxi, bool &flag){
        if(flag) return;
        if(!root->left && !root->right){
            if(maxi - mini == 2){
                flag = true;
            }
            return;
        }
        if(root->left) solve(root->left,mini,root->data,flag);
        if(root->right) solve(root->right,root->data,maxi,flag);
    }
    bool isDeadEnd(Node *root) {
        // Code here
        int mini = 0, maxi = INT_MAX;
        bool flag = false;
        solve(root,mini,maxi,flag);
        return flag;
    }
};