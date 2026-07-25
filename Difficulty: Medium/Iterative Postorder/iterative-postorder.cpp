/* Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};*/
class Solution {
  public:
    vector<int> postOrder(Node* node) {
        // code here
        stack<Node*>st;
        vector<int>ans;
        st.push(node);
        Node* temp;
        while(!st.empty()){
            temp = st.top();
            st.pop();
            ans.push_back(temp->data);
            if(temp->left) st.push(temp->left);
            if(temp->right) st.push(temp->right);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};