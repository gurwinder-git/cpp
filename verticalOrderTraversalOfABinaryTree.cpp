#include <iostream>
#include <vector>
#include <set>
#include <map>

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

class Solution
{
public:
    // sorted row order
    // map<int, multiset<int>> mp;

    // void preOrder(TreeNode *root, int col)
    // {
    //     if (!root)
    //         return;

    //     this->mp[col].insert(root->val);
    //     preOrder(root->left, col - 1);
    //     preOrder(root->right, col + 1);
    // }
    // vector<vector<int>> verticalTraversal(TreeNode *root)
    // {
    //     vector<vector<int>> res;
    //     map<int, multiset<int>>::iterator mpItr = this->mp.begin();

    //     this->preOrder(root, 0);

    //     map<int, multiset<int>>::iterator mapItr = this->mp.begin();

    //     for (mapItr; mapItr != this->mp.end(); mapItr++)
    //     {
    //         vector<int> col;
    //         multiset<int>::iterator setItr = mapItr->second.begin();

    //         for (; setItr != mapItr->second.end(); setItr++)
    //         {
    //             col.push_back(*setItr);
    //         }

    //         res.push_back(col);
    //     }

    //     return res;
    // }

    map<int, map<int, multiset<int>>> mp;

    void fillMap(TreeNode *root, int row, int col)
    {
        if (!root)
            return;

        this->mp[col][row].insert(root->val);
        fillMap(root->left, row + 1, col - 1);
        fillMap(root->right, row + 1, col + 1);
    }

    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        vector<vector<int>> res;
        fillMap(root, 0, 0);

        map<int, map<int, multiset<int>>>::iterator mapItr = this->mp.begin();

        for (mapItr; mapItr != this->mp.end(); mapItr++)
        {
            vector<int> colData;
            map<int, multiset<int>>::iterator rowItr = (*mapItr).second.begin();

            for (rowItr; rowItr != (*mapItr).second.end(); rowItr++)
            {
                colData.insert(colData.end(), (*rowItr).second.begin(), (*rowItr).second.end());
            }
            res.push_back(colData);
        }
        return res;
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

    Solution sol;

    vector<vector<int>> res = sol.verticalTraversal(root);

    cout << "[ ";
    for (auto v : res)
    {
        cout << "[";
        for (int i : v)
            cout << " " << i << " ";
        cout << "]";
    }
    cout << " ]";

    return 0;
}
