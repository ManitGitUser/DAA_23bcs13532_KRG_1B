#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<vector<int>> countFreq(vector<int>& arr) {
        unordered_map<int, int> m;
        
        for (int x : arr)
            m[x]++;

        vector<vector<int>> result;
        for (auto& it : m)
            result.push_back({it.first, it.second});
       
        sort(result.begin(), result.end());
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 2, 2, 3, 3, 5};
    
    vector<vector<int>> ans = sol.countFreq(arr);
    
    cout << "[";
    for (int i = 0; i < ans.size(); i++) {
        cout << "[" << ans[i][0] << ", " << ans[i][1] << "]";
        if (i != ans.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
    
    return 0;
}
