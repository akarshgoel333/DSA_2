/*
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
    void find(Node* root, int &l, int &r, int pos){
        if(!root) return;
        l = min(l,pos);
        r = max(r,pos);
        find(root->left,l,r,pos-1);
        find(root->right,l,r,pos+1);
    }
    vector<int> topView(Node *root) {
        // code here
        int l = 0, r = 0;
        find(root,l,r,0);
        vector<int>ans(r-l+1,0);
        queue<Node*>q;
        queue<int>posi;
        q.push(root);
        posi.push(-l);
        Node* temp;
        int idx;
        while(!q.empty()){
            temp = q.front();
            q.pop();
            idx = posi.front();
            posi.pop();
            if(ans[idx]==0) ans[idx] = temp->data;
            if(temp->left){
                q.push(temp->left);
                posi.push(idx-1);
            }
            if(temp->right){
                q.push(temp->right);
                posi.push(idx+1);
            }
        }
        return ans;
    }
};