class Solution {
public:
    int longestBalanced(vector<int>& arr) {
        int n = arr.size();
        int res = 0;
        unordered_set<int> evenSet, oddSet;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (arr[j] % 2 == 0)
                    evenSet.insert(arr[j]);
                else
                    oddSet.insert(arr[j]);

                if (evenSet.size() == oddSet.size())
                    res = max(res, j - i + 1);
            }
            evenSet.clear();
            oddSet.clear();
        }
        return res;
    }
};