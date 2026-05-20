class Solution {
public:
    vector<vector<int>> buildPrefixHeights(vector<vector<char>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> psum(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == '1') {
                    psum[i][j] = (i == 0) ? 1 : psum[i - 1][j] + 1;
                } else {
                    psum[i][j] = 0;
                }
            }
        }
        return psum;
    }

    int histo(vector<int>& heights, int n) {
        vector<int> left(n, -1), right(n, n);
        stack<int> st;

        // Right smaller element
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            if (!st.empty())
                right[i] = st.top();
            st.push(i);
        }

        while (!st.empty())
            st.pop();

        // Left smaller element
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            if (!st.empty())
                left[i] = st.top();
            st.push(i);
        }

        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            maxArea = max(maxArea, heights[i] * (right[i] - left[i] - 1));
        }
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return 0;

        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> psum = buildPrefixHeights(matrix);

        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            maxArea = max(maxArea, histo(psum[i], m));
        }

        return maxArea;
    }
};
