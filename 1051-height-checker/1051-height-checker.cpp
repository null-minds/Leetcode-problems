class Solution {
public:
    int heightChecker(vector<int>& heights) {
        // int n=heights.size();
        // vector<int> expected = heights;
        // sort(expected.begin(), expected.end());
        // int count =0;
        // for(int i=0; i<n; i++){
        //     if(expected[i] != heights[i]){
        //         count++;
        //     }
        // }
        // return count;

        // Frequency array for heights in range [1, 100]
        int count[101] = {0};
        for (int h : heights) {
            count[h]++;
        }

        int mismatches = 0;
        int current_height = 1;

        for (int h : heights) {
            // Find the next height that should appear in sorted order
            while (count[current_height] == 0) {
                current_height++;
            }

            // Compare the actual student height with the expected height
            if (h != current_height) {
                mismatches++;
            }

            // Decrement the count for the placed height
            count[current_height]--;
        }

        return mismatches;
    }
};