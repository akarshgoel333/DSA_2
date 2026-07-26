/* Structure of a Tree Node
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    Node* tree(vector<int> &inorder, vector<int> &preorder, int inSrt, int inEnd, int idx){
        if(inSrt>inEnd) return nullptr;
        Node* temp = new Node(preorder[idx]);
        int nxtsrt;
        for(int i=inSrt; i<=inEnd; i++){
            if(inorder[i] == preorder[idx]){
                nxtsrt = i;
                break;
            }
        }
        temp->left = tree(inorder, preorder, inSrt, nxtsrt-1,idx+1);
        temp->right = tree(inorder, preorder, nxtsrt+1, inEnd,idx+nxtsrt-inSrt+1);
        return temp;
    }
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        // code here
        return tree(inorder,preorder,0,preorder.size()-1,0);
    }
};