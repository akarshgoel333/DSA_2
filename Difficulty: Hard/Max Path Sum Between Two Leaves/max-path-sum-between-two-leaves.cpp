/* Node Structure
class Node {
    int data;
    Node left;
    Node right;

    Node(int data) {
        this.data = data;
        left = nullptr;
        right = nullptr;
    }
}
*/

class Solution {
  public:
    int maxi(Node* root, int &ans){
        if(!root) return 0;
        if(!root->left && !root->right) return root->data;
        int left = maxi(root->left,ans);
        int right = maxi(root->right,ans);
        if(root->left && root->right){
            ans = max(ans,left+right+root->data);
            return max(left,right)+root->data;
        }
        if(root->left){
            return left+root->data;
        }
        if(root->right){
            return right+root->data;
        }
        return 0;
    }
    int maxPathSum(Node *root) {
        // code here
        int ans = INT_MIN;
        int val = maxi(root,ans);
        if(root->right && root->left) return ans;
        return max(ans,val);
    }
};