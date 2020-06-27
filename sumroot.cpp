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

#define ll long long int

class Solution {
public:
    
    ll ans=0;
    
    void dfs(TreeNode* head,ll val){
        if(head==NULL) return ;
        
        val*=10;
        val+=(head->val);
        
        if(head->right==NULL && head->left==NULL){
            ans+=val;
            return;
        }
        
        dfs(head->left,val);
        dfs(head->right,val);
        
    }
    
    int sumNumbers(TreeNode* root) {
        if(root==NULL) return 0;
        
        dfs(root,0);
        return ans;
        
        
    }
};