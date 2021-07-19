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
    void inorderTraversal(TreeNode* root, vector<int> &nums){
        if(root == NULL) return;
        
        inorderTraversal(root->left, nums);
        nums.push_back(root->val);
        inorderTraversal(root->right, nums);
        
        return;
    }
    bool findTarget(TreeNode* root, int k) {
        //Solucao 1: Travesia "inorder". Monta um array que ja vai ta ordenado. Percorre o array, fazendo two pointers.
        vector<int> nums;
        bool answer = false;
        inorderTraversal(root, nums);
        
        int left = 0, right = (int)nums.size() - 1;
        while(left < right){
            if(left < 0) break;
            if(right >= (int)nums.size()) break;
            if(nums[left] + nums[right] == k){
                answer = true;
                break;
            }else if(nums[left] + nums[right] > k){
                right--;
            }else{
                left++;
            }
        }
        
        return answer;
    }
};
