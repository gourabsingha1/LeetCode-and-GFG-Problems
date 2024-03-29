// minHeap will give cur minimum of nums1 which should be logically omitted when size >= k
// sorting nums2 wise will give current minimum
// dry run karle bhai
class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        long long res = 0, curr = 0, n = nums1.size();
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
        {
            v.push_back({nums2[i], nums1[i]});
        }
        sort(v.rbegin(), v.rend());
        
        priority_queue<int, vector<int>, greater<>> minHeap;
        for (int i = 0; i < n; i++)
        {
            curr = (curr + v[i].second);
            minHeap.push(v[i].second);
            if(i + 1 >= k){
                res = max(res, curr * v[i].first);
                curr -= minHeap.top();
                minHeap.pop();
            }
        }
        return res;
    }
};