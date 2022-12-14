class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for (int i = 0; i < numRows; i++)
        {
            vector<int> v(i+1,1);
            for (int j = 0; j < i/2; j++)
            {
                v[j+1] = (res[i-1][j] + res[i-1][j+1]);
                v[i - j - 1] = v[j+1];
            }
            res.push_back(v);
        }
        return res;
    }
};