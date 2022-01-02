nnect(Node *root)
    {
        queue<Node *> helperQueue({root});

        while (!helperQueue.empty())
        {
            int sizeOfQueue = helperQueue.size();

            Node *pointerToPreviousElement = NULL;

            while (sizeOfQueue--)
            {
                Node *curr = helperQueue.front();
                helperQueue.pop();

                curr->next = pointerToPreviousElement;

                pointerToPreviousElement = curr;

                if (curr->right)
                    helperQueue.push(curr->right);
                if (curr->left)
                    helperQueue.push(curr->left);
            }
        }

        return root;
    }