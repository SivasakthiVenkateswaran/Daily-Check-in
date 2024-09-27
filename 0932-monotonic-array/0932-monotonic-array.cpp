class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        vector<int> inc = nums;
        sort(inc.begin(), inc.end());
        if(inc == nums) return true;        
        sort(inc.begin(), inc.end(), greater<int>());
        if(inc == nums) return true;
        return false;
    }
};