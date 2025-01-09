// Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of
// all the values of the nodes in the tree.

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:

    void inorder(TreeNode* r, int k, int &i, int &ans){
        if(!r) return;
        inorder(r->left,k,i,ans);
        i++;
        if(i==k) ans=r->val;
        inorder(r->right,k,i,ans);
    }

    int kthSmallest(TreeNode* root, int k) {
        int ans,i=0;
        inorder(root,k,i,ans);
        return ans;
    }
};