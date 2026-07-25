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
        stack<Node*> st;
        vector<int>ans;
        st.push(root);
        Node* temp;
        while(!st.empty()){
            temp = st.top();
            st.pop();
            ans.push_back(temp->data);
            if(temp->right) st.push(temp->right);
            if(temp->left) st.push(temp->left);
        }
        return ans;
    }
};