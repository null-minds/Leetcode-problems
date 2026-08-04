class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int maxi = *max_element(nums.begin(), nums.end());
        int mini = *min_element(nums.begin(), nums.end());

        int n = nums.size();
        // Store all numbers from nums into a Hash Set for O(1) quick lookups
        unordered_set<int> presentElements(nums.begin(), nums.end());

        // Vector to store the missing numbers
        vector<int> missing;

        // Check every number from mini to maxi
        for (int i = mini; i <= maxi; ++i) {
            
            // presentElements.find(i) returns presentElements.end() if 'i' is NOT found
            if (presentElements.find(i) == presentElements.end()) {
                // Since 'i' is missing, add it to our answer array
                missing.push_back(i);
            }
        }
        // Step 5: Return the collected missing elements (already sorted naturally)
        return missing;
    }
};