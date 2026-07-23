class Solution {
  public:
    vector<int> largestValues(Node* root) {
        // code here
        queue<Node*>q;
        q.push(root);
        vector<int>ans;
        Node* temp;
        int gen1 = 1;
        int gen2 = 0;
        int maxi = root->data;
        while(!q.empty()){
            temp = q.front();
            q.pop();
            maxi = max(maxi,temp->data);
            gen1--;
            if(temp->left){
                q.push(temp->left);
                gen2++;
            }
            if(temp->right){
                q.push(temp->right);
                gen2++;
            }
            if(gen1==0){
                ans.push_back(maxi);
                gen1 = gen2;
                gen2 = 0;
                maxi = 0;
            }
        }
        return ans;
    }
};