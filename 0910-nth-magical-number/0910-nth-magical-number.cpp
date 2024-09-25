#include<algorithm>

class Solution {
public:
    int gcd(int a, int b){
        if(a==0) return b;
        return gcd(b%a,a);
    }
    int nthMagicalNumber(int n, int a, int b) {
        long long int d=a*b/gcd(a,b);
        long long int start=min(a,b);
        long long int end=n*start;
        long long int mid,c;
        while(start<end){
            mid= start+(end-start)/2;
            c= mid/a+mid/b-mid/d;
            if(c<n){
                start=mid+1;
            }
            else{
                end=mid;
            }
        }
        int mod=1e9+7;
        return start%mod;

    }
};