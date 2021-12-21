e (!q.empty())
        {
            int qSize = q.size();
            while (qSize--)
            {
                pair<TreeNode *, int> curr = q.front();
                q.pop();

                if (curr.first->left)
                    q.push(pair<TreeNode *, int>(curr.first->left, curr.second * 2));
                if (curr.first->right)
                    q.push(pair<TreeNode *, int>(curr.first->right, (curr.second * 2) + 1));
            }

            if (!q.empty())
            {
                maxWidth = max(q.back().second - q.front().second + 1, maxWidth);
            }
        }
