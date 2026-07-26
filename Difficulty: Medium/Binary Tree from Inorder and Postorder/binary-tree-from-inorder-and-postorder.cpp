/* Node Structure
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int x) {
        data = x;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
  Node* tree(vector<int> &inorder, vector<int> &postorder, int inSrt, int inEnd, int idx){
        if(inSrt>inEnd) return nullptr;
        Node* temp = new Node(postorder[idx]);
        int nxtsrt;
        for(int i=inSrt; i<=inEnd; i++){
            if(inorder[i] == postorder[idx]){
                nxtsrt = i;
                break;
            }
        }
        temp->left = tree(inorder, postorder, inSrt, nxtsrt-1,idx-inEnd+nxtsrt-1);
        temp->right = tree(inorder, postorder, nxtsrt+1, inEnd,idx-1);
        return temp;
    }
    Node *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // code here
        return tree(inorder,postorder,0,postorder.size()-1,postorder.size()-1);
    }
};