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
    Node* createBST(vector<int> &arr, int st, int end){
        if(st>end) return nullptr;
        int mid = st + (end-st)/2;
        Node* temp = new Node(arr[mid]);
        temp->left = createBST(arr,st,mid-1);
        temp->right = createBST(arr,mid+1,end);
        return temp;
    }
    Node* sortedArrayToBST(vector<int>& arr) {
        // code here
        int n = arr.size();
        Node* root = createBST(arr,0,n-1);
        return root;
    }
};