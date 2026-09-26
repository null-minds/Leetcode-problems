class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

                    // understandable approach O(n)
        // int maxi = INT_MIN;
        // int prod = 1;
        // for(int i=0; i<n; i++){
        //     prod *= nums[i];
        //     maxi = max(maxi, prod);

        //     if(prod == 0) prod = 1;
        // }

        // prod = 1;
        // for(int i=n-1; i>=0; i--){
        //     prod *= nums[i];
        //     maxi = max(maxi, prod);

        //     if(prod == 0) prod = 1;
        // }
        // return maxi;

                    // approach in one pass: Multiplying by a negative flips numbers: the smallest negative product can instantly become the largest positive product.
                    // By tracking both the running maximum and minimum at every step and swapping them when hitting a negative number

        int maxP = 1, minP = 1, maxi = nums[0];
        for(int it : nums){
            if(it < 0) swap(maxP, minP);

            maxP = max(it, it * maxP);
            minP = min(it, it * minP);

            maxi = max(maxi, maxP);
        }
        return maxi;
    }
};