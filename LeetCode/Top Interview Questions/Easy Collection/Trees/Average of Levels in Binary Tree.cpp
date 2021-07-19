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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> answer;
        queue<TreeNode*> fila;
        fila.push(root);
        int currentSize = 1, nextSize = 0;
        
        while(!fila.empty()){
            vector<TreeNode*> curr;
            for(int i = 1; i <= currentSize; i++){
                TreeNode* tn = fila.front();
                curr.push_back(tn);
                fila.pop();
                if(tn->left != NULL){
                    fila.push(tn->left);
                    nextSize++;
                }
                if(tn->right != NULL){
                    fila.push(tn->right);
                    nextSize++;
                }
            }
            long int currentLevelValue = 0;
            for(int i = 0; i < (int)curr.size(); i++){
                currentLevelValue += (curr[i]->val)*1L;
            }
            currentSize = nextSize;
            nextSize = 0;
            answer.push_back((double)currentLevelValue/curr.size());
        }
        
        return answer;
    }
};
