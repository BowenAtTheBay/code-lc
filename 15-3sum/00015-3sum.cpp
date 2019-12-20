class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        if (nums.empty())
            return vector<vector<int>> ();
        
        // O(n^2) time, O(n) space
        for (int i = 0; i < nums.size(); ++i) {
            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == 0) {
                    vector<int> s (3, 0);
                    s[0] = nums[i];
                    s[1] = nums[l];
                    s[2] = nums[r];
                    res.push_back(s);
                    
                    while ((nums[l] == s[1]) && (l < r))//compare with s[1] rather than nums[l+1]
                        ++l;
                    while ((nums[r] == s[2]) && (l < r))
                        --r;
                }
                
                else if (sum > 0 && l < r)
                    --r;
                else if (sum < 0 && l < r)
                    ++l;
            }
            
            while (i < nums.size() - 1 && nums[i] == nums[i + 1])
                ++i;
        }
        return res;
    }
};
//13min
​