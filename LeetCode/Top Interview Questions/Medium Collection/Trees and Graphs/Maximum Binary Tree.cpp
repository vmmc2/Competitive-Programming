/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* build_tree(vector<int> &nums, int left, int right){
        if(left > right){
            return NULL;
        }
        int maxVal = -1, index = -1;
        for(int i = left; i <= right; i++){
            if(nums[i] > maxVal){
                maxVal = nums[i];
                index = i;
            }
        }
        TreeNode *root = new TreeNode(maxVal);
        root->left = build_tree(nums, left, index - 1);
        root->right = build_tree(nums, index + 1, right);
        return root;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if((int)nums.size() == 0) return NULL;
        if((int)nums.size() == 1) return new TreeNode(nums[0]);
        
        int left = 0, right = (int)nums.size() - 1;
        return build_tree(nums, left, right);
    }
};
