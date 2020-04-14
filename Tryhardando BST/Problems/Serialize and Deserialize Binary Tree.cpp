/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <bits/stdc++.h>
#include <sstream>
#include <string>

class Codec {
public:
    // Encodes a tree to a single string.
    string sHelper(TreeNode* root){
        if(root == NULL) return "X,";
        string leftsubtree = sHelper(root->left);
        string rightsubtree = sHelper(root->right);
        return to_string(root->val) + "," + leftsubtree + rightsubtree;
    }
    string serialize(TreeNode* root) {
        string finale = sHelper(root);
        finale.pop_back();
        return finale;
    }
    // Decodes your encoded data to tree.
    TreeNode* dHelper(queue<string> &fila ){
        string b = fila.front();
        fila.pop();
        if(b == "X") return NULL;
        TreeNode *novoNode = new TreeNode(stoi(b));
        novoNode->left = dHelper(fila);
        novoNode->right = dHelper(fila);
        return novoNode;
    }
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        queue<string> fila;
        while(ss.good()){
            string a;
            getline(ss, a, ',');
            fila.push(a);
        }
        return dHelper(fila);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
