class Solution {
public:
    int minimumSum(int num) {
        vector<int>ans;
        int num1=0,num2=0;
        while(num){
            ans.push_back(num%10);
            num=num/10;
        }
        reverse(ans.begin(),ans.end());
        sort(ans.begin(),ans.end());
        num1=ans[0]*10+ans[3];
         num2=ans[1]*10+ans[2];

        return num1+num2;
    }
};