#include<iostream>
#include<algorithm>

using namespace std;

//  Definition for a binary tree node.
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
    int minDepth(TreeNode* root) {
        
        if(!root)
            return 0;
        
        int leftVal = minDepth(root->left);
        int rightVal = minDepth(root->right);

        if(leftVal == 0)
            return rightVal + 1;
        if(rightVal == 0)
            return leftVal + 1;

        return min(leftVal, rightVal) + 1;
    }
};

int main()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(6);

    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(10);

    Solution sol;


    cout<<"Minimum depth of binary tree: "<<sol.minDepth(root);
    return 0;
}