/*
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* constructbst(vector<int> &nums, int low, int high){
        if(low > high) return NULL;
        int mid = low + (high - low)/2;
        TreeNode *temp = new TreeNode(nums[mid]);
        temp->left = constructbst(nums, low, mid - 1);
        temp->right = constructbst(nums, mid + 1, high);
        return temp;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        //treating the conner case: We receive an empty vector. So, our BST must also be an empty tree.
        if((int)nums.size() == 0) return NULL;
        //treating the other cases...
        int n = (int)nums.size();
        return constructbst(nums, 0, n - 1);
    }
};
