//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

bool isSubSequence(vector<int> &v1, vector<int> &v2, int n, int m) {

    if (m == 0) return true;
    if (n == 0) return false;

    if (v1[n - 1] == v2[m - 1]) return isSubSequence(v1, v2, n - 1, m - 1);

    return isSubSequence(v1, v2, n - 1, m);
}


// } Driver Code Ends
/*The function returns a vector containing the
increasing sub-sequence of length 3 if present
else returns an empty vector */
class Solution{
  public:
    vector<int> find3Numbers(vector<int> arr, int N) {
        vector<int> res, pre(N), suf(N);
        pre[0] = arr[0], suf[N - 1] = arr[N - 1];
        for (int i = 1; i < N; i++)
        {
            pre[i] = min(arr[i], pre[i - 1]);
        }
        for (int i = N - 2; i >= 0; i--)
        {
            suf[i] = max(arr[i], suf[i + 1]);
        }
        for (int i = 1; i < N - 1; i++)
        {
            if(pre[i - 1] < arr[i] && arr[i] < suf[i + 1]) {
                return {pre[i - 1], arr[i], suf[i + 1]};
            }
        }
        return {};
    }
};

//{ Driver Code Starts.

// Driver program to test above function
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        auto res = obj.find3Numbers(a, n);

        // wrong format output
        if (!res.empty() and res.size() != 3) {
            cout << -1 << "\n";
        }

        if (res.empty()) {
            cout << 0 << "\n";
        } else if ((res[0] < res[1] and res[1] < res[2]) and
                   isSubSequence(a, res, n, res.size())) {
            cout << 1 << "\n";
        } else {
            cout << -1 << "\n";
        }
    }

    return 0;
}
// } Driver Code Ends