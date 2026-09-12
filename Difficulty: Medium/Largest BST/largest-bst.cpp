/* Structure of a Binary Search Tree node
class Node {
public:
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Box {
  public:
    bool BST;
    int size;
    int mini;
    int maxi;
    Box(int data){
        BST = true;
        size = 1;
        mini = data;
        maxi = data;
    }
};
class Solution {
  public:
    Box* find (Node* root, int &totalSize){
        if(!root->left && !root->right){
            totalSize = max(totalSize,1);
            return new Box(root->data);
        }
        else if(!root->left && root->right){
            Box* head = find(root->right,totalSize);
            if(head->BST && (head->mini > root->data)){
                head->size++;
                head->mini = root->data;
                totalSize = max(totalSize,head->size);
                return head;
            }
            else{
                head->BST = false;
                return head;
            }
        }
        else if(root->left && !root->right){
            Box* head = find(root->left,totalSize);
            if(head->BST && (head->maxi < root->data)){
                head->size++;
                head->maxi = root->data;
                totalSize = max(totalSize,head->size);
                return head;
            }
            else{
                head->BST = false;
                return head;
            }
        }
        else{
            Box* leftHead = find(root->left,totalSize);
            Box* rightHead = find(root->right,totalSize);
            if(leftHead->BST && rightHead->BST && (leftHead->maxi<root->data) && (rightHead->mini>root->data)){
                Box* head = new Box(root->data);
                head->size += leftHead->size + rightHead->size;
                head->mini = leftHead->mini;
                head->maxi = rightHead->maxi;
                totalSize = max(totalSize,head->size);
                return head;
            }
            else{
                leftHead->BST = false;
                return leftHead;
            }
        }
    }
    int largestBst(Node *root) {
        // code here
        int totalSize = 0;
        find(root,totalSize);
        return totalSize;
    }
};