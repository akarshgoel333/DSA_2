class Solution {
  public:
    priority_queue<int>pq1;
    priority_queue<int,vector<int>,greater<int>>pq2;
    vector<double> ans;
    
    void insertHeap(int &x){
        if(pq1.empty()){
            pq1.push(x);
            return;
        }
        if(x>pq1.top()){
            pq2.push(x);
        }
        else pq1.push(x);
        balanceHeaps();
    }
    void balanceHeaps(){
        if(pq2.size()>pq1.size()){
            pq1.push(pq2.top());
            pq2.pop();
        }
        if(pq1.size()-pq2.size()>1){
            pq2.push(pq1.top());
            pq1.pop();
        }
    }
    double getMedian(){
        if(pq1.size()==pq2.size()){
            ans.push_back(double(pq1.top()+pq2.top())/2);
        }
        else if(pq1.size()>pq2.size()) ans.push_back(double(pq1.top()));
        else ans.push_back(double(pq2.top()));
    }
    vector<double> getMedian(vector<int> &arr) {
        // code here
        for(int i=0; i<arr.size(); i++){
            insertHeap(arr[i]);
            getMedian();
        }
        return ans;
    }
};
