#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.size();
        if (n <= 1) return 0; 
        vector<int>as(n,0), bs(n,0);
        for(int i=1;i<n;i++){
            if(s[i-1]=='b') bs[i]=bs[i-1]+1;
            else bs[i] = bs[i-1];
        }
        for(int i=n-2;i>=0;i--){
            if(s[i+1]=='a') as[i]=as[i+1]+1;
            else as[i] = as[i+1];
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            ans = min(ans,as[i]+bs[i]);
        }
        return ans;
    }
};