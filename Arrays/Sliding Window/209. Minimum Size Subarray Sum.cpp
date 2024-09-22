class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int l=0,r=0;
        int sum =0; 
        int minLength=INT_MAX;
        while(r<n)
        {
            sum+=nums[r];
            if(sum>=target){
                // cal min length
                minLength=min(minLength,r-l+1);
            }

            while(l<=r && sum>=target){
                sum-=nums[l];
                l++;
                if(sum>=target)
                  minLength=min(minLength,r-l+1);
            }
            r++;
        }
        if(minLength==INT_MAX)
            return 0;

        return minLength;
    }
};