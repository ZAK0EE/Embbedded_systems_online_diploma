class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans(2);
        
        vector<int> freq1(2001);
        vector<int> freq2(2001);
        
        for(auto i : nums1)
        {
            freq1[i + 1000] = 1;
        }
        
        for(auto i : nums2)
        {
            freq2[i + 1000] = 1;
        }
        
        for(int i = 0, n = freq1.size(); i < n; i++)
        {
            if(freq1[i] != 0 && freq1[i] != freq2[i])
            {
                ans[0].push_back(i - 1000);
            }
            else if(freq2[i] != 0 && freq2[i] != freq1[i])
                ans[1].push_back(i - 1000);
        }
        
        return ans;
    }
};