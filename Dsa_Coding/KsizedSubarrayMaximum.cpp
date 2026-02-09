class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        vector<int>res;
        priority_queue<pair<int,int>>hp;
        for(int i=0;i<k;i++){
            hp.push({arr[i],i});
        }
        res.push_back(hp.top().first);
        for(int i=k;i<n;i++){
            hp.push({arr[i],i});
            while(hp.top().second<=i-k) hp.pop();
            res.push_back(hp.top().first);
        }
        return res;
    }
};