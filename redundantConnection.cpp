#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
     vector<int> *parent;

    int findParent(int node)
    {
        if((*parent)[node] == node)
            return node;
        
        int p = findParent((*parent)[node]);

        return p;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        parent = new vector<int>(edges.size() + 1);
        for(int i = 1; i <= edges.size(); i++)
            (*parent)[i] = i;


                
        for(vector<int>&e: edges)
        {
            int p1 = findParent(e[0]);
            int p2 = findParent(e[1]);
 

            if(p1 == p2)
                return {e[0], e[1]};
            
            (*parent)[p2] = p1;
        }
 

        return{-1,-1};

    }
};

int main()
{
    vector<vector<int>> edges = {{1,2},{2,3},{3,4},{1,4},{1,5}};
    Solution sol;

    vector<int> res = sol.findRedundantConnection(edges);

    cout<<res[0]<<endl<<res[1];

    return 0;
}



