/*
Definition for Node
class Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    vector<int> zigZagTraversal(Node* root) {
        // code here
        stack<Node*>ltor;
        stack<Node*>rtol;
        rtol.push(root);
        vector<int>ans;
        Node* temp;
        while(true){
            while(!rtol.empty()){
                temp = rtol.top();
                rtol.pop();
                ans.push_back(temp->data);
                if(temp->left) ltor.push(temp->left);
                if(temp->right) ltor.push(temp->right);
            }
            while(!ltor.empty()){
                temp = ltor.top();
                ltor.pop();
                ans.push_back(temp->data);
                if(temp->right) rtol.push(temp->right);
                if(temp->left) rtol.push(temp->left);
            }
            if(rtol.empty() && ltor.empty()) break;
        }
        return ans;
    }
};