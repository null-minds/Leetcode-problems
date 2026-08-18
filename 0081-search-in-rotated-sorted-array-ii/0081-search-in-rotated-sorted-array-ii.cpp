class Solution {
public:
    bool search(vector<int>& nums, int k) {
        int n = nums.size();
        int low = 0, high = n-1;
        while(low<=high){
            int mid = low + (high - low)/2;
            if(nums[mid] == k) return true;

            // check the duplicate elements ex: [3, 1, 2, 3, 3, 3, 3]
            if(nums[low] == nums[mid] && nums[mid] == nums[high]){
                high = high - 1;
                low = low + 1;
                continue;
            }

            // check if the left part is sorted
            if(nums[low] <= nums[mid]){
                // if target is in the left part: eliminate the right part
                if(nums[low] <= k && k <= nums[mid]){
                    high = mid - 1;
                }
                // else eliminate the left part
                else{
                    low = mid + 1;
                }
            }
            // if the right part is sorted
            else{
                if(nums[mid] <= k && k <= nums[high]){
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
        }
        return false;
    }
};