class Solution {
public:
    int minFlips(string target) {
        int res = 0, state = 1;
        for(auto& ch : target) {
            if(ch - '0' == state) {
                res++;
                state = !state;
            }
        }
        return res;
    }
};