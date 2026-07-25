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
        stack<int>vis;
        stack<Node*>st;
        st.push(root);
        vis.push(0);
        vector<int>ans;
        Node* temp;
        int done;
        while(!st.empty()){
            temp = st.top();
            st.pop();
            done = vis.top();
            vis.pop();
            if(done == 1){
                ans.push_back(temp->data);
            }
            else{
                if(temp->right){
                    st.push(temp->right);
                    vis.push(0);
                }
                st.push(temp);
                vis.push(1);
                if(temp->left){
                    st.push(temp->left);
                    vis.push(0);
                }
            }
        }
        return ans;
    }
};