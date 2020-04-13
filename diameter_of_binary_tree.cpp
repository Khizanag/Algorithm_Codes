/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
int recLenOfBinaryTree(TreeNode * root)
{
	if(root == NULL)
		return -1;
	return max(recLenOfBinaryTree(root->left), recLenOfBinaryTree(root->right)) + 1;
}
    
int diameterOfBinaryTree(TreeNode* root) 
{
	if(root == NULL)
		return 0;
	int leftRecLen = recLenOfBinaryTree(root->left);
	int rightRecLen = recLenOfBinaryTree(root->right);
	int thisRes = leftRecLen + rightRecLen + 2;
	int childRes = max(diameterOfBinaryTree(root->left),
							diameterOfBinaryTree(root->right));
	return max(thisRes, childRes);
}
