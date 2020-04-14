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
    void traversal(TreeNode* start, map<TreeNode*,TreeNode*> &parent, TreeNode *root, stack<TreeNode*> &pilha){
        if(start == NULL) return;
        if(start == root){
            pilha.push(start);
            traversal(start->left, parent, root, pilha);
            traversal(start->right, parent, root, pilha);
            pilha.pop();
        }else{
            parent[start] = pilha.top();
            pilha.push(start);
            traversal(start->left, parent, root, pilha);
            traversal(start->right, parent, root, pilha);
            pilha.pop();
        }
        return;
    }
    void bfs(TreeNode *root, int K, set<TreeNode*> &seen, map<TreeNode*,TreeNode*> &parent, queue<TreeNode*> &fila){
        fila.push(root);
        seen.insert(root);
        int level = 0;
        while(!fila.empty()){
            if(level == K) return;
            int tam = (int)fila.size();
            for(int i = 1; i <= tam; i++){
                TreeNode *temp = fila.front();
                fila.pop();
                if(temp->left != NULL && seen.find(temp->left) == seen.end()){
                    fila.push(temp->left);
                    seen.insert(temp->left);
                }
                if(temp->right != NULL && seen.find(temp->right) == seen.end()){
                    fila.push(temp->right);
                    seen.insert(temp->right);
                }
                if(parent[temp] != NULL && seen.find(parent[temp]) == seen.end()){
                    fila.push(parent[temp]);
                    seen.insert(parent[temp]);
                }
            }
            level++;
        }
        return;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        set<TreeNode*> seen;
        stack<TreeNode*> pilha;
        map<TreeNode*,TreeNode*> parent;
        vector<int> vazio;
        queue<TreeNode*> fila;
        parent[root] = NULL; //setando o parent da raiz como NULL
        //primeira parte: realiza uma travessia pela minha BST para construir o 
        //meu map...
        traversal(root, parent, root, pilha);
        //mapa construido... 
        //parte 2: rodar a bfs
        bfs(target, K, seen, parent, fila);
        while(!fila.empty()){
            TreeNode *z = fila.front();
            fila.pop();
            vazio.push_back(z->val);
        }
        return vazio;
    }
};
