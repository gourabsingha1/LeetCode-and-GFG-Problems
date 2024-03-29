class Solution {
public:
    TreeNode* buildBST(int l, int r, vector<int>& nums) {
        if(l > r) {
            return NULL;
        }
        int mid = (l + r) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = buildBST(l, mid - 1, nums);
        root->right = buildBST(mid + 1, r, nums);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildBST(0, nums.size() - 1, nums);
    }
};