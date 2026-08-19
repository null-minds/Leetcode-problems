class Solution {
private:
    long long calculateHours(vector<int> & nums, int k){
        long long totalHours = 0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            totalHours += ceil((double)nums[i] / (double)k);
        }
        return totalHours;
    }
public:
    int minEatingSpeed(vector<int>& nums, int h) {
        int low = 1, high = *max_element(nums.begin(), nums.end());

        while(low<=high){
            int mid = low + (high - low)/2;
            long long hours = calculateHours(nums, mid);

            if(hours <= h){
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return low;
    }
};