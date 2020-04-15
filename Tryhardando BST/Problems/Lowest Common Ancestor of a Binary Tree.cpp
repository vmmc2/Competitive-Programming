/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <unordered_map>
#include <unordered_set>

class Solution {
public:
    void construct_mapa(TreeNode *start, unordered_map<TreeNode*,TreeNode*> &parent, TreeNode *root, stack<TreeNode*> &pilha){
        if(start == NULL) return;
        if(start == root){
            pilha.push(root);
            construct_mapa(start->left, parent, root, pilha);
            construct_mapa(start->right,parent, root, pilha);
            pilha.pop();
        }else{
            parent[start] = pilha.top();
            pilha.push(start);
            construct_mapa(start->left, parent, root, pilha);
            construct_mapa(start->right,parent, root, pilha);
            pilha.pop();
        }    
        return; 
    }
    TreeNode* find_LCA(TreeNode *p, TreeNode *q, TreeNode *root, unordered_set<TreeNode*> &pathp, unordered_set<TreeNode*> &pathq, unordered_map<TreeNode*,TreeNode*> &parent){
        TreeNode *answer;
        int flagpmove = 0;
        int flagqmove = 0;
        while(true){
            if(flagpmove == 0){
                pathp.insert(p);
                if(p == root) flagpmove = 1;
                if(pathq.find(p) != pathq.end()){
                    answer = p;
                    break;
                }
                p = parent[p];
            }
            if(flagqmove == 0){
                pathq.insert(q);
                if(q == root) flagqmove = 1;
                if(pathp.find(q) != pathq.end()){
                    answer = q;
                    break;
                }
                q = parent[q];
            }
        }
        return answer;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_map<TreeNode*,TreeNode*> parent;
        stack<TreeNode*> pilha;
        unordered_set<TreeNode*> pathp;
        unordered_set<TreeNode*> pathq;
        parent[root] = NULL;
        construct_mapa(root, parent, root, pilha);
        
        //ja construi o mapa... agora tem que construir o path dos dois nodes *p e *q...
        TreeNode *answer = find_LCA(p, q, root, pathp, pathq, parent);
        return answer;
    }
};
