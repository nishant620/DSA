#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int checkHeight(TreeNode* root){
        if(!root) return 0;
        
        int leftht = checkHeight(root->left);
        if(leftht==-1) return -1;

        int rightht = checkHeight(root->right);
        if(rightht==-1) return -1;

        if(abs(rightht-leftht)>1) return -1;
        return 1+max(leftht,rightht);
    }
    bool isBalanced(TreeNode* root) {
        return checkHeight(root)!=-1;
    }
};