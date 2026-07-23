/* Node Structure
class Node {
public:
    int data;
    struct Node* left;
    struct Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    int solve(Node* root, int ans){
        if(root == nullptr) return 0;
        return 1+solve(root->left,ans)+solve(root->right,ans);
    }
    int getSize(Node* root) {
        // code here
        return solve(root,0);
    }
};