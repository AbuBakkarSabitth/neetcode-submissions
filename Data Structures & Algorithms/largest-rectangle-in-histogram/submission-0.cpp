#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> st; // {start_index, height}
        int maxArea = 0;
        for (int i = 0; i < heights.size(); i++) {
            int start = i;

            // If current height is smaller → process previous taller bars
            while (!st.empty() && st.top().second > heights[i]) {
                auto [index, height] = st.top();
                st.pop();
                int width = i - index;
                int area = height * width;
                maxArea = max(maxArea, area);

                start = index; // extend current bar to left
            }
            st.push({start, heights[i]});
        }
        // Process remaining bars
        while (!st.empty()) {
            auto [index, height] = st.top();
            st.pop();
            int width = heights.size() - index;
            int area = height * width;
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};