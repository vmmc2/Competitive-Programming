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
    //NAO SAO SO OS VALORES. TEM QUE INVERTER TODA A ESTRUTURA DA BST (INCLUINDO OS NULL NODES).
    TreeNode* invertTree(TreeNode* root) {
        //Corner case.
        if(root == NULL) return root;
        
        //General case.
        queue<TreeNode*> fila;
        fila.push(root);
        int currentSize = 1, nextSize = 0;
        
        while(!fila.empty()){
            vector<TreeNode*> current;
            for(int i = 1; i <= currentSize; i++){
                TreeNode* tn = fila.front();
                fila.pop();
                current.push_back(tn);
                if(tn->left != NULL){
                    fila.push(tn->left);
                    nextSize++;
                }
                if(tn->right != NULL){
                    fila.push(tn->right);
                    nextSize++;
                }
            }
            int left = 0, right = current.size() - 1;
            while(left < right){
                int aux = current[left]->val;
                current[left]->val = current[right]->val;
                current[right]->val = aux;
                left++;
                right--;
            }
            currentSize = nextSize;
            nextSize = 0;
        }
        
        return root;
    }
};
