class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        /*
        vector <int> ans;
        for (int i = 0; i < nums.size() - k + 1; i++) {
            int j = i;
            vector <int> window;

            while (j < k + i) {
                window.push_back(nums[j]);
                j++;
            }
            int maximum = INT_MIN;
            for (int n = 0; n < window.size(); n++)
                maximum = max(window[n], maximum);

            ans.push_back(maximum);
        }
        return ans;
        */
        /*
        vector <int> ans;
        deque <int> window;
        int maximum = INT_MIN;

        for (int i = 0; i < k; i++) {
            window.push_back(nums[i]);
            maximum = max(maximum, window[i]);
        }
        ans.push_back(maximum);

        for (int i = k; i < nums.size(); i++) {
            window.pop_front();
            window.push_back(nums[i]);
            maximum = *max_element(window.begin(), window.end());
            ans.push_back(maximum);
        }
        return ans;
        */
        vector<int> ans;
        deque<int> window;
        for (int i = 0; i < k; i++) {
            while (!window.empty() && nums[window.back()] <= nums[i])
                window.pop_back();
            window.push_back(i);
        }
        ans.push_back(nums[window.front()]);

        for (int i = k; i < nums.size(); i++) {
            if (!window.empty() && window.front() <= i - k)
                window.pop_front();

            while (!window.empty() && nums[window.back()] <= nums[i])
                window.pop_back();

            window.push_back(i);

            ans.push_back(nums[window.front()]);
        }
        return ans;

    }
};