class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;

        heights.push_back(0); // Sentinel to process remaining bars

        for (int i = 0; i < heights.size(); i++) {

            while (!st.empty() && heights[i] < heights[st.top()]) {
                int height = heights[st.top()];
                st.pop();

                int width;

                if (st.empty())
                    width = i;
                else
                    width = i - st.top() - 1;

                int area = height * width;
                maxArea = max(maxArea, area);
            }

            st.push(i);
        }

        heights.pop_back();

        return maxArea;
    }
};