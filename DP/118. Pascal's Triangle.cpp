class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> nums;
        // nums.push_back({1});
        for (int i = 1; i <= numRows; i++) {
            int ans = 1;
            vector<int> temp;
            temp.push_back(ans);
            for (int j = 1; j < i; j++) {
                ans = ans * (i - j);
                ans = ans / j;
                temp.push_back(ans);
            }
            nums.push_back(temp);
        }
        return nums;
    }
};
