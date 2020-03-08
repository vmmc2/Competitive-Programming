/**
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
    TreeNode* ConstructTreeFromArray(vector<int> &num, int left, int right){
        if(left > right) return NULL;
        int middle = left + (right - left)/2;
        TreeNode *node = new TreeNode(num[middle]); //na primeira chamada isso vai funcionar como a raiz.
        node->left = ConstructTreeFromArray(num, left, middle - 1);
        node->right = ConstructTreeFromArray(num, middle + 1, right);
        return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if((int)nums.size() == 0) return NULL;
        return ConstructTreeFromArray(nums, 0, (int)nums.size() - 1);
    }
};
