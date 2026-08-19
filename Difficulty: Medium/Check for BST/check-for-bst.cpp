/* Structure of a Binary Search Tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    void good(Node* root, bool &flag, int &prev){
        if(!root || !flag) return;
        good(root->left,flag,prev);
        if(root->data <= prev){
            flag = false;
            return;
        }
        prev = root->data;
        good(root->right,flag,prev);
    }
    bool isBST(Node* root) {
        // code here
        bool flag = true;
        int prev = INT_MIN;
        good(root,flag,prev);
        return flag;
    }
};