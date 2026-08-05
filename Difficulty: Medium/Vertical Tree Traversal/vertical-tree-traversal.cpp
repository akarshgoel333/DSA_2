/* Structure of binary tree node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
    void find(Node* root, int &l, int &r, int pos){
        if(!root) return;
        l = min(l,pos);
        r = max(r,pos);
        find(root->left,l,r,pos-1);
        find(root->right,l,r,pos+1);
    }
    vector<vector<int>> verticalOrder(Node *root) {
        // code here
        int l = INT_MAX, r = INT_MIN;
        find(root,l,r,0);
        vector<vector<int>>arr(r-l+1);
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
            arr[idx].push_back(temp->data);
            if(temp->left){
                q.push(temp->left);
                posi.push(idx-1);
            }
            if(temp->right){
                q.push(temp->right);
                posi.push(idx+1);
            }
        }
        
        return arr;
    }
};