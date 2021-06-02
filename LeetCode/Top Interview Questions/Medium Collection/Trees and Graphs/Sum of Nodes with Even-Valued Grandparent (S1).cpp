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
    void find_answer(TreeNode* root, int& answer, deque<int> pred){
        if(root->left == NULL && root->right == NULL){
            if(pred.size() < 3){
                pred.push_back(root->val);
            }
            if(pred.size() == 3){
                if(pred[0] % 2 == 0) answer += root->val;
            }
            return;
        }
        if(pred.size() < 3){
            pred.push_back(root->val);
        }
        if(pred.size() == 3){
            if(pred[0] % 2 == 0) answer += root->val;
            pred.pop_front();
        }
        if(root->left != NULL){
            find_answer(root->left, answer, pred);
        }
        if(root->right != NULL){
            find_answer(root->right, answer, pred);
        }
        
        return;
    }
    int sumEvenGrandparent(TreeNode* root) {
        if(root == NULL) return 0;
        
        int answer = 0;
        deque<int> pred;
        find_answer(root, answer, pred);
        return answer;
    }
};
