class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        long long n=1;
        int s=rowIndex;
        ans.push_back(1);
        for(int i=1;i<=rowIndex;i++){
            n*=s--;
            n=n/i;
            ans.push_back(n);
        }
        return ans;
    }
};
