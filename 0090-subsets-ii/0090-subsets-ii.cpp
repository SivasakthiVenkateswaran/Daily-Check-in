class Solution {
public:
    void final_ans(vector<vector<int>> &ans, vector<int> nums, int i, int n){
        if(i==n) return;
        int r=ans.size();
        for(int j=0;j<r;j++){
            vector<int> temp=ans[j];
            temp.push_back(nums[i]);
            sort(temp.begin(),temp.end());
            if(find(ans.begin(),ans.end(),temp)==ans.end())
            ans.push_back(temp);
        }
        final_ans(ans,nums,i+1,n);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        ans.push_back({});
        int n=nums.size();
        ans.push_back({nums[0]});
        final_ans(ans,nums,1,n);
        return ans;
    }
};