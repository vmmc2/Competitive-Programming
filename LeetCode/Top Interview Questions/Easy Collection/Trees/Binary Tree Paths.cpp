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
    void auxTraverseTree(TreeNode* root, vector<vector<int>> &paths, vector<int> &currentPath){
        if(root->left == NULL && root->right == NULL){
            currentPath.push_back(root->val);
            paths.push_back(currentPath);
            currentPath.pop_back();
            return;
        }
        currentPath.push_back(root->val);
        if(root->left != NULL){
            auxTraverseTree(root->left, paths, currentPath);
        }
        if(root->right != NULL){
            auxTraverseTree(root->right, paths, currentPath);
        }
        currentPath.pop_back();
        return;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<vector<int>> paths;
        vector<int> currentPath;
        vector<string> answer;
        
        if(root == NULL) return answer;
        
        auxTraverseTree(root, paths, currentPath);
        
        for(int i = 0; i < (int)paths.size(); i++){
            vector<int> ss = paths[i];
            string aux = "";
            for(int j = 0; j < (int)ss.size(); j++){
                if(j != ss.size() - 1){
                    aux += to_string(ss[j]);
                    aux += "->";
                }else{
                    aux += to_string(ss[j]);
                }
            }
            answer.push_back(aux);
        }
        
        return answer;
    }
};
