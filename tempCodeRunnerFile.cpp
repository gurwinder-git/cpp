rdered_map<Node *, Node *> oldVsNew;
    // Node *cloneGraph(Node *node)
    // {
    //     if (!node)
    //         return NULL;

    //     // if not mapped
    //     if (oldVsNew.find(node) == oldVsNew.end())
    //     {
    //         Node *newNode = new Node(node->val);
    //         oldVsNew[node] = newNode;

    //         for (Node *&neighbor : node->neighbors)
    //         {
    //             newNode->neighbors.push_back(cloneGraph(neighbor));
    //         }
    //     }

    //     return oldVsNew[node];
    // }