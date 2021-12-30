#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator
{
private:
    stack<TreeNode *> st;

public:
    BSTIterator(TreeNode *root)
    {
        this->insertAllLeft(root);
    }

    int next()
    {
        TreeNode *topNode = this->st.top();
        this->st.pop();
        this->insertAllLeft(topNode->right);
        return topNode->val;
    }

    bool hasNext()
    {
        return !this->st.empty();
    }

private:
    void insertAllLeft(TreeNode *root)
    {
        while (root)
        {
            this->st.push(root);
            root = root->left;
        }
    }
};

int main()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);

    BSTIterator itr = root;

    while (itr.hasNext())
    {
        cout << itr.next() << "  ";
    }

    return 0;
}
