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
    void inorder(TreeNode* root,vector<int>&vals){
        if(!root) return ;
        inorder(root->left,vals);
        vals.push_back(root->val);
        inorder(root->right,vals);
    }
    TreeNode* construct(int i,int j,vector<int>& vals){
        if(i>j) return NULL;
        int mid = (i+j)/2;
        TreeNode* newnode = new TreeNode(vals[mid]);
        newnode->left=construct(i,mid-1,vals);
        newnode->right=construct(mid+1,j,vals);

        return newnode;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>vals;
        inorder(root,vals);
        int n=vals.size();
        return construct(0,n-1,vals);
    }
};