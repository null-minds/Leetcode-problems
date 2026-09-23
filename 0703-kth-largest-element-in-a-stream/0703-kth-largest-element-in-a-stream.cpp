class KthLargest {
public:
    int size;
    priority_queue<int, vector<int>, greater<int>> pq;

    KthLargest(int k, vector<int>& nums) {
        int n = nums.size();
        size = k;
        for(int i=0; i<n; i++){
            add(nums[i]);
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > size){
            pq.pop();
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */