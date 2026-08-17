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
        vector<int>ans;
        Node* curr;
        while(node){
            if(!node->right){
                ans.push_back(node->data);
                node = node->left;
            }
            else{
                curr = node->right;
                while(curr->left && curr->left!=node){
                    curr = curr->left;
                }
                if(!curr->left){
                    ans.push_back(node->data);
                    curr->left = node;
                    node = node->right;
                }
                else{
                    curr->left = NULL;
                    node = node->left;
                }
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};