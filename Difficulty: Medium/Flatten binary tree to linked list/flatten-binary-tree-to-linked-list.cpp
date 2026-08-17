class Solution {
  public:
    void flatten(Node *root) {
        // code here
        Node* temp;
        while(root){
            if(!root->left){
                root = root->right;
            }
            else{
                temp = root->left;
                while(temp->right){
                    temp = temp->right;
                }
                temp->right = root->right;
                root->right = root->left;
                root->left = NULL;
                root = root->right;
            }
        }
        return;
    }
};