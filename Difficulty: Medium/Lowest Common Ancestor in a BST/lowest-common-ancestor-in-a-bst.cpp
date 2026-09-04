/* Structure of a Binary Search Tree node
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
    Node* findLCA(Node* root, Node* n1, Node* n2) {
        // code here
        if(!root) return nullptr;
        int a = n1->data, b = n2->data;
        if(a>b) swap(a,b);
        int c = root->data;
        if(c>b) return findLCA(root->left,n1,n2);
        else if(c<a) return findLCA(root->right,n1,n2); 
        else return root;
    }
};