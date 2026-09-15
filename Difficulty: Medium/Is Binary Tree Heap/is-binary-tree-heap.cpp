/*
class Node {
   public:
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
    int count(Node* root){
        if(!root) return 0;
        return 1+count(root->left)+count(root->right);
    }
    bool CBT(Node* root, int idx, int num){
        if(!root) return true;
        if(idx>=num) return false;
        return CBT(root->left,2*idx+1,num) && CBT(root->right,2*idx+2,num);
    }
    bool maxheap(Node* root){
        if(!root) return true;
        if(root->left){
            if(root->data < root->left->data) return false;
            if(!maxheap(root->left)) return false;
        }
        if(root->right){
            if(root->data < root->right->data) return false;
            return maxheap(root->right);
        }
        return true;
    }
    bool isHeap(Node* tree) {
        // code here
        int num = count(tree);
        if(!CBT(tree,0,num)) return false;
        return maxheap(tree);
    }
};