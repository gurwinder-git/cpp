#include <iostream>
#include <vector>

using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

public:
    TreeNode(int val)
    {
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class Solution
{
private:
    void inOrderTraversal(TreeNode *root, vector<int> &list)
    {
        if (root == NULL)
            return;

        this->inOrderTraversal(root->left, list);
        list.push_back(root->val);
        this->inOrderTraversal(root->right, list);
    }

public:
    vector<int> getAllElements(TreeNode *root1, TreeNode *root2)
    {
        vector<int> list1;
        vector<int> list2;
        this->inOrderTraversal(root1, list1);
        this->inOrderTraversal(root2, list2);

        vector<int> res(list1.size() + list2.size());
        int i = 0, j = 0, k = 0;
        while (i < list1.size() && j < list2.size())
        {
            if (list1[i] < list2[j])
            {
                res[k] = list1[i];
                i++;
                k++;
            }
            else
            {
                res[k] = list2[j];
                j++;
                k++;
            }
        }

        while (i < list1.size())
        {
            res[k] = list1[i];
            i++;
            k++;
        }
        while (j < list2.size())
        {
            cout << list2[j] << endl;
            res[k] = list2[j];
            j++;
            k++;
        }

        return res;
    }
};

int main()
{
    TreeNode root1 = 5;
    root1.left = new TreeNode(2);
    root1.right = new TreeNode(8);
    TreeNode root2 = 8;
    root2.left = new TreeNode(0);
    root2.right = new TreeNode(9);

    Solution sol;

    vector<int> res = sol.getAllElements(nullptr, &root2);

    for (int i : res)
        cout << i;

    return 0;
}