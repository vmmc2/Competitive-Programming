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
    void inorderTraversal(TreeNode* root, vector<int> &inorder){
        if(root == NULL) return;
        
        inorderTraversal(root->left, inorder);
        inorder.push_back(root->val);
        inorderTraversal(root->right, inorder);
        
        return;
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> answer;
        vector<int> inorder1;
        vector<int> inorder2;
        
        inorderTraversal(root1, inorder1);
        inorderTraversal(root2, inorder2);
        
        int left1 = 0, right1 = inorder1.size();
        int left2 = 0, right2 = inorder2.size();
        
        while(left1 < right1 || left2 < right2){
            if(left1 < right1 && left2 < right2){
                if(inorder1[left1] <= inorder2[left2]){
                    answer.push_back(inorder1[left1]);
                    left1++;
                }else{
                    answer.push_back(inorder2[left2]);
                    left2++;
                }
            }else if(left1 < right1 && left2 >= right2){
                answer.push_back(inorder1[left1]);
                left1++;
            }else if(left1 >= right1 && left2 < right2){
                answer.push_back(inorder2[left2]);
                left2++;
            }
        }
        
        return answer;
    }
};
