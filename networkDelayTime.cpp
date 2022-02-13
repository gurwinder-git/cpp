#include<iostream>
#include<vector>
#include<queue>
#include<climits>

using namespace std;



class Solution {
public:
    class node{
    public:
        int dest;
        int cost;

        node( int _dest, int _cost)
        { 
            dest = _dest;
            cost = _cost;
        }
    };
 
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<int> shortestPath(n + 1, INT_MAX); 
        shortestPath[k] = 0;

        priority_queue<pair<int,int>> minHeap;
        minHeap.push({0, k});

        vector<vector<node>>adjList(n + 1);
        //make adjacancy list
        for (int i = 0; i < times.size(); i++)
        {
            int source = times[i][0];
            int dest = times[i][1];
            int cost = times[i][2];

            adjList[source].push_back(node(dest, cost));
        }

        while (!minHeap.empty())
        {
            int minCostOfSourceNode = minHeap.top().first;
            int SourceNode = minHeap.top().second;
            minHeap.pop();

            for (node &n : adjList[SourceNode])
            {
                int destNode = n.dest;
                int destCost = n.cost;

                if(minCostOfSourceNode + destCost < shortestPath[destNode])
                {
                    shortestPath[destNode] = minCostOfSourceNode + destCost;
                    minHeap.push({minCostOfSourceNode + destCost, destNode});
                }
            }
        }

        int ans = -1;
        for(int i = 1; i < shortestPath.size(); i++)
        {
            if(shortestPath[i] == INT_MAX) return -1;
            if(shortestPath[i] > ans) ans = shortestPath[i];
        }
        
        return ans;
    }
};

int main()
{
    vector<vector<int>>times = {{2,1,1},{2,3,1},{3,4,1}};
    Solution sol;

    cout<<sol.networkDelayTime(times, 4, 2);
    return 0;
}