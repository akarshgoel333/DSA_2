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
    vector<int> inOrder(Node* root) {
        // code here
        vector<int>ans;
        Node* curr;
        while(root){
            if(!root->left){
                ans.push_back(root->data);
                root = root->right;
            }
            else{
                curr = root->left;
                while(curr->right && curr->right!=root){
                    curr = curr->right;
                }
                if(!curr->right){
                    curr->right = root;
                    root = root->left;
                }
                else{
                    curr->right = nullptr;
                    ans.push_back(root->data);
                    root = root->right;
                }
            }
        }
        return ans;
    }
};