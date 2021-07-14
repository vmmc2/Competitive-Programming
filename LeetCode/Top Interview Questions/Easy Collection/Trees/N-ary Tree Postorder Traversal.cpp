/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void auxTraversal(Node *root, vector<int> &answer){
        if(root == NULL) return;
        
        for(int i = 0; i < (int)root->children.size(); i++){
            Node* next = root->children[i];
            auxTraversal(next, answer);
        }
        answer.push_back(root->val);
        
        return;
    }
    vector<int> postorder(Node* root) {
        vector<int> answer;
        
        auxTraversal(root, answer);
        
        return answer;
    }
};
