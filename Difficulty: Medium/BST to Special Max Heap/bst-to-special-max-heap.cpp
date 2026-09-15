/* Binary Tree Node Structure
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
    void inorder(Node* root, vector<int>&arr){
        if(!root) return;
        inorder(root->left,arr);
        arr.push_back(root->data);
        inorder(root->right,arr);
    }
    void postorder(Node* root, int &idx, vector<int>&arr){
        if(!root || idx>=arr.size()) return;
        postorder(root->left,idx,arr);
        postorder(root->right,idx,arr);
        root->data = arr[idx++];
    }
    void convertToMaxHeap(Node* root) {
        // code here
        vector<int>arr;
        inorder(root,arr);
        int idx=0;
        postorder(root,idx,arr);
        return;
    }
};
