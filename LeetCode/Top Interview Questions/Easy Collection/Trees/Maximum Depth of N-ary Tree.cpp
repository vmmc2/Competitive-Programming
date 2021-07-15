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
    void checkDepth(Node* root, int& answer, int current){
        if(root->children.size() == 0){
            answer = max(answer, current);
            return;
        }else{
            for(int i = 0; i < (int)root->children.size(); i++){
                checkDepth(root->children[i], answer, current + 1);
            }
        }
        return;
    }
    int maxDepth(Node* root) {
        if(root == NULL) return 0;
        int answer = 1, current = 1;
        checkDepth(root, answer, current);
        return answer;
    }
};
