olve(TreeNode *root)
    {
        if (!root)
            return;
        if (root->left != NULL && root->left->left != NULL)
        {
            if (root->left->left->val % 2 == 0)
                this->sum += root->left->left->val;
        }

        if (root->left != NULL && root->left->right != NULL)
        {
            if (root->val % 2 == 0)
            {
                this->sum += root->left->right->val;
            }
        }

        if (root->right != NULL && root->right->left != NULL)
        {
            if (root->val % 2 == 0)
                this->sum += root->right->left->val;
        }

        if (root->right != NULL && root->right->right != NULL)
        {
            if (root->val % 2 == 0)
                this->sum += root->right->right->val;
        }
        solve(root->left);
        solve(root->right);
    }