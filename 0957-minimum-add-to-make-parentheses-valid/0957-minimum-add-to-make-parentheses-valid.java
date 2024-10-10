class Solution {
    public int minAddToMakeValid(String s) {
        int i,count=0,neg=0;
        for(i=0;i<s.length();i++)
        {
            if(s.charAt(i)=='(')
            {
                count++;
            }else
            {
                if(count>0)
                {
                    count--;
                }
                else
                {
                    neg++;
                }
            }
        }
        return neg+count;
    }
}