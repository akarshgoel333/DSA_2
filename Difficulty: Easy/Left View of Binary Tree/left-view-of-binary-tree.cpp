/*
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
};
*/

class Solution {
  public:
    vector<int> leftView(Node *root) {
        // code here
        if(root==nullptr) return {};
        queue<Node*>q;
        q.push(root);
        vector<int>ans;
        Node* temp;
        while(!q.empty()){
            int n = q.size();
            temp = q.front();
            ans.push_back(temp->data);
            while(n--){
                temp = q.front();
                q.pop();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            
        }
        return ans;
    }
};