/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    vector<int> preOrder(Node* root) {
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
                    ans.push_back(root->data);
                    curr->right = root;
                    root = root->left;
                }
                else{
                    curr->right = NULL;
                    root = root->right;
                }
            }
        }
        return ans;
    }
};