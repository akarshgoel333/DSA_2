/* Structure of binary tree Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
    void find(Node* root, int target, Node* &curr){
        if(!root) return;
        if(root->data == target){
            curr = root;
            return;
        }
        find(root->left,target,curr);
        find(root->right,target,curr);
    }
    int height(Node* root){
        if(!root) return 0;
        int left = height(root->left);
        int right = height(root->right);
        return 1+max(left,right);
    }
    int burning(Node* root, int target, int &ans){
        if(!root) return 0;
        if(root->data == target) return -1;
        int left = burning(root->left,target,ans);
        int right = burning(root->right,target,ans);
        if(left<0){
            ans = max(ans, abs(left)+right);
            return left-1;
        }
        else if(right<0){
            ans = max(ans, abs(right)+left);
            return right-1;
        }
        return 1+max(left,right);
        
    }
    int minTime(Node* root, int target) {
        // code here
        Node* curr = nullptr;
        find(root,target,curr);
        int ans = 0;
        burning(root,target,ans);
        ans = max(ans,height(curr)-1);
        
        // int height = 
        return ans;
    }
};