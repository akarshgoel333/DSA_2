/* Structure of a Tree Node
class Node {
    int data;
    Node* right;
    Node* left;
    Node(int x){
        data = x;
        right = nullptr;
        left = nullptr;
    }
}; */

class Solution {
  public:
    void srch(Node* root, int &a, int k, int &sumi){
        if(!root || a>=k) return;
        srch(root->left,a,k,sumi);
        if(a>=k) return;
        a++;
        sumi += root->data;
        srch(root->right,a,k,sumi);
        
        
    }
    int sum(Node* root, int k) {
        // code here
        int sumi = 0;
        int a = 0;
        srch(root,a,k,sumi);
        return sumi;
    }
};