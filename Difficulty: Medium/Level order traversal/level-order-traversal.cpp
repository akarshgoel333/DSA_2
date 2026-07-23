/* A binary tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> levelOrder(Node *root) {
        // code here
        queue<Node*>nxt;
        nxt.push(root);
        vector<int>ans;
        Node* temp;
        while(!nxt.empty()){
            temp = nxt.front();
            nxt.pop();
            ans.push_back(temp->data);
            if(temp->left) nxt.push(temp->left);
            if(temp->right) nxt.push(temp->right);
        }
        return ans;
    }
};