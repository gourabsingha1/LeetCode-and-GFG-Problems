class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int l = 1, h = 1e5;
        while(l <= h){
            int m = (l+h)/2, sum = 0;
            for(int &x : quantities){
                sum += ((x+m-1)/m);
            }
            if(sum <= n){
                h = m - 1;
            }
            else{
                l = m + 1;
            }
        }
        return l;
    }
};