/* Node Structure
class Node {
  public:
    int data;
    Node* left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    void leftsub(Node* root, vector<int> &ans){
        if(!root || (!root->left && !root->right)) return;
        ans.push_back(root->data);
        if(root->left) leftsub(root->left,ans);
        else if(root->right) leftsub(root->right,ans);
    }
    void leaf(Node* root, vector<int> &ans){
        if(!root) return;
        if(!root->left && !root->right){
            ans.push_back(root->data);
            return;
        }
        leaf(root->left,ans);
        leaf(root->right,ans);
    }
    void rightsub(Node* root, vector<int> &ans){
        if(!root || (!root->left && !root->right)) return;
        if(root->right) rightsub(root->right,ans);
        else if(root->left) rightsub(root->left,ans);
        ans.push_back(root->data);
    }
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int>ans;
        ans.push_back(root->data);
        leftsub(root->left,ans);
        if(root->left || root->right) leaf(root,ans);
        rightsub(root->right,ans);
        return ans;
        
        
        
        // Node* temp;
        // queue<Node*>q;
        // q.push(root);
        // while(!q.empty()){
        //     temp = q.front();
        //     q.pop();
        //     ans.push_back(temp->data);
        //     if(temp->left) q.push(temp->left);
        //     else if(temp->right) q.push(temp->right);
        // }
        
    }
};