/* Structure of binary tree Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/
class Solution {
  public:
    bool check(Node* root, int a, int b){
        if(root == NULL) return false;
        if(root->left && root->right){
            if(root->left->data == a && root->right->data == b) return true;
            if(root->left->data == b && root->right->data == a) return true;
        }
        return check(root->left,a,b) || check(root->right,a,b);
    }
    bool areCousins(Node* root, int a, int b) {
        // code here
        queue<Node*>q;
        q.push(root);
        int lvl = 0;
        int l1 = -1, l2 = -1;
        Node* temp;
        while(!q.empty()){
            int n = q.size();
            while(n--){
                temp = q.front();
                q.pop();
                if(temp->data == a) l1 = lvl;
                else if(temp->data == b) l2 = lvl;
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            lvl++;
            if(l1!=l2) return false;
            if(l1!=-1 && l2!=-1) break;
        }
        if(l1==-1 || l2==-1) return false;
        return !check(root,a,b);
    }
};