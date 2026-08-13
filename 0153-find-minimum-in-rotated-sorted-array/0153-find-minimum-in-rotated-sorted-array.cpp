class Solution {
public:
    int findMin(vector<int>& nums) {
        int low =0, high = nums.size()-1;
        int ans = INT_MAX;
        while(low <= high){
            // If the search space is already sorted, nums[low] is the minimum
            if (nums[low] <= nums[high]) {
                ans = min(ans, nums[low]);
                break;
            }
            
            int mid = low + (high - low)/2;

            if(nums[low] <= nums[mid]){
                ans = min(ans, nums[low]);
                // because in the right side, there can be minimum value in sorted arr
                low = mid + 1;
            }
            else{
                ans = min(ans, nums[mid]);
                high = mid - 1;
            }
        }
        return ans;
    }
};