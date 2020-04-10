# TUTORIAL/EXPLANATION ABOUT THESE QUESTIONS

## Maximum Depth of a Binary Tree
* First, we need to check if we received an empty tree or a tree with just onde node. We can check it by make two conditionals: To check if the tree is empty, we just do: if(root == NULL). And to check if the tree has just one node, we should do: if(root->left == NULL && root->right == NULL).
* After that, we should call an auxiliar function to do the traversal. We should also create an empty stack and a variable to store the maximum height of our binary tree.
* We should do the traversal in the same style as a preorder traversal. Checking if NULL and pushing the element to the stack, after we try the traversal to both left and right, then we pop our stack.
