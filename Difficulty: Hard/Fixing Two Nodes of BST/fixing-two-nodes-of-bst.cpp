/* Structure of a Binary Search Tree node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    Node* correctBST(Node* root) {
        // code here
        Node* first=nullptr, *second=nullptr;
        Node* curr = nullptr, *root1 = root;
        Node* prev = nullptr, *pres = nullptr;
        while(root){
            if(root->left){
                curr = root->left;
                while(curr->right && curr->right!=root){
                    curr = curr->right;
                }
                if(!curr->right){
                    curr->right = root;
                    root = root->left;
                }
                else{
                    pres = root;
                    if(prev && prev->data > pres->data){
                        if(!first) first = prev;
                        second = pres;
                    }
                    prev = root;
                    curr->right = nullptr;
                    root = root->right;
                }
            }
            else{
                // ??
                pres = root;
                if(prev && prev->data > pres->data){
                    if(!first) first = prev;
                    second = pres;
                }
                prev = root;
                root = root->right;
            }
        }
        int temp = first->data;
        first->data = second->data;
        second->data = temp;
        return root1;
    }
};