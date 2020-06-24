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
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        /*int ans1=0,ans2=0;
        if(root->left){
            ans1=1+countNodes(root->left);
        }
        if(root->right) ans2=1+countNodes(root->right);
        
        
        return ans1+ans2;*/
        
        
        return 1+countNodes(root->left)+countNodes(root->right);
        
    }
};