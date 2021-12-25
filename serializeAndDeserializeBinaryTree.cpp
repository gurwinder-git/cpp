#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

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

class Codec
{
public:
    void serialize(TreeNode *root, string &res)
    {
        if (!root)
        {
            res.append("null,");
            return;
        }

        res.append(to_string(root->val) + ",");
        serialize(root->left, res);
        serialize(root->right, res);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        string serializedData;

        this->serialize(root, serializedData);
        serializedData.pop_back();
        return serializedData;
    }

    vector<string> splitString(string &s, char c)
    {
        vector<string> splitedString;

        string temp = "";

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == c)
            {
                splitedString.push_back(temp);
                temp = "";
            }
            else
            {
                temp.push_back(s[i]);
            }
        }

        splitedString.push_back(temp);
        return splitedString;
    }
    // Decodes your encoded data to tree.

    TreeNode *deserializeHelper(vector<string> &splitedString, int &index)
    {
        if (index >= splitedString.size() || splitedString[index] == "null")
        {
            index++;
            return NULL;
        }

        TreeNode *currNode = new TreeNode(stoi(splitedString[index]));
        index++;

        currNode->left = deserializeHelper(splitedString, index);
        currNode->right = deserializeHelper(splitedString, index);

        return currNode;
    }
    TreeNode *deserialize(string data)
    {
        vector<string> splitedString = splitString(data, ',');
        int index = 0;
        TreeNode *ans = deserializeHelper(splitedString, index);
        return ans;
    }
};

void preOrder(TreeNode *root)
{
    if (!root)
        return;

    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int main()
{
    TreeNode *root = new TreeNode(22);
    root->left = new TreeNode(37);
    root->right = new TreeNode(46);

    root->left->left = new TreeNode(55);
    root->left->right = new TreeNode(36);
    root->right->left = new TreeNode(72);
    root->right->right = new TreeNode(8);

    Codec ser, deser;

    string serializedData = ser.serialize(root);
    cout << serializedData << endl;

    TreeNode *deSeriallizedData = deser.deserialize(serializedData);
    preOrder(deSeriallizedData);

    return 0;
}
