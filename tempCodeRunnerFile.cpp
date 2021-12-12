ht++;
        parent = root->val;
        solve(root->left, x, parent, height);
        solve(root->right, x, parent, height);
        heig