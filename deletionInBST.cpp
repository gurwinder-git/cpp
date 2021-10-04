#include <iostream>
#include <utility>
using namespace std;

class treeNode
{
public:
    treeNode *left;
    int val;
    treeNode *right;

    treeNode()
    {
        this->val = 0;
        this->left = NULL;
        this->right = NULL;
    }

    treeNode(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }

    treeNode(int val, treeNode *left, treeNode *right)
    {
        this->val = val;
        this->left = left;
        this->right = right;
    }

    static void traverse(treeNode *nodePtr)
    {
        if (nodePtr == NULL)
            return;

        traverse(nodePtr->left);
        cout << nodePtr->val << "  ";
        traverse(nodePtr->right);
    }

    static pair<treeNode *, treeNode *> findNodeAndItsParentNode(treeNode *root, int key)
    {
        pair<treeNode *, treeNode *> nodePair;

        nodePair.first = NULL;
        nodePair.second = NULL;

        while (root)
        {
            if (root->val == key)
            {
                nodePair.first = root;
                return nodePair;
            }
            else if (root->val < key)
            {
                nodePair.second = root;
                root = root->right;
            }
            else
            {
                nodePair.second = root;
                root = root->left;
            }
        }
        return nodePair;
    }

    static treeNode *deleteNode(treeNode *root, int key)
    {
        pair<treeNode *, treeNode *> nodePair = findNodeAndItsParentNode(root, key);

        treeNode *node = nodePair.first;
        treeNode *parent = nodePair.second;

        if (!node)
            return root;

        //if node is leaf node
        if (!(node->left) && !(node->right))
        {
            if (parent)
            {
                if (parent->left)
                {
                    if (parent->left->val == node->val)
                    {
                        delete parent->left;
                        parent->left = NULL;
                    }
                    else
                    {
                        delete parent->right;
                        parent->right = NULL;
                    }
                }
                else
                {
                    delete parent->right;
                    parent->right = NULL;
                }
            }
            else
            {
                root = NULL;
            }
        }
        //if node has one child left or right
        else if ((node->left && !(node->right)) || (!(node->left) && node->right))
        {
            //if node not root
            if (node != root)
            {
                if (parent->left)
                {
                    if (parent->left->val == node->val)
                    {
                        parent->left = node->left ? node->left : node->right;
                        delete node;
                    }
                    else
                    {
                        parent->right = node->right ? node->right : node->left;
                        delete node;
                    }
                }
                else
                {
                    parent->right = node->right ? node->right : node->left;
                    delete node;
                }
            }
            else
            {
                treeNode *tempRoot = root;
                root = root->left ? root->left : root->right;
                delete tempRoot;
            }
        }
        else
        {
            treeNode *tempNode = node;

            tempNode = tempNode->left;
            treeNode *prevOfTempNode = tempNode;
            while (tempNode->right)
            {
                prevOfTempNode = tempNode;
                tempNode = tempNode->right;
            }

            if (tempNode != prevOfTempNode)
            {
                node->val = tempNode->val;
                prevOfTempNode->right = tempNode->left;
            }
            else
            {
                node->val = tempNode->val;
                node->left = tempNode->left;
            }
        }

        return root;
    }
};

int main()
{
    treeNode *root = new treeNode(4);
    root->left = new treeNode(2);
    root->right = new treeNode(7);

    //  2
    // / \
    //1   3
    root->left->left = new treeNode(1);
    root->left->right = new treeNode(3);
    // (*(*root).left).right = new treeNode();

    treeNode *res = treeNode::deleteNode(root, 2);
    treeNode::traverse(res);

    return 0;
}
