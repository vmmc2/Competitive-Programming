class KthLargest {
public:
    int k;
    TreeNode *root;
    TreeNode* insertNode(TreeNode* root, int num){
        if(root == NULL){
            return new TreeNode(num);
        }else{
            if(root->val <= num){
                root->right = insertNode(root->right, num);
            }else{
                root->left = insertNode(root->left, num);
            }
        }
        return root;
    }
    void getKthLargest(TreeNode* root, vector<int> &answer){
        if(root == NULL) return;
        getKthLargest(root->right, answer);
        answer.push_back(root->val);
        getKthLargest(root->left, answer);
        return;
    }
    KthLargest(int k, vector<int>& nums) {
        root = NULL;
        this->k = k;
        for(int i = 0; i < (int)nums.size(); i++){
            root = insertNode(root, nums[i]);
        }
    }
    int add(int val) {
        root = insertNode(root, val);
        vector<int> answer;
        getKthLargest(root, answer);
        return answer[k - 1];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
