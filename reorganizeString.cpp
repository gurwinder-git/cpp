#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <utility>
using namespace std;

string reorganizeString(string &s);
int main()
{
    string t = "aaabcd";
    cout << reorganizeString(t);
    return 0;
}

string reorganizeString(string &s)
{
    unordered_map<char, int> helperMap;
    priority_queue<pair<int, char>> pq;
    string res = "";

    for (char c : s)
        helperMap[c] = helperMap[c] + 1;

    for (pair<char, int> obj : helperMap)
        pq.push(pair<int, char>(obj.second, obj.first));

    while (pq.size() > 1)
    {
        pair<int, char> top1 = pq.top();
        pq.pop();
        pair<int, char> top2 = pq.top();
        pq.pop();

        res += top1.second;
        res += top2.second;

        top1.first -= 1;
        top2.first -= 1;

        if (top1.first > 0)
            pq.push(top1);

        if (top2.first > 0)
            pq.push(top2);
    }

    if (!pq.empty())
    {
        if (pq.top().first > 1)
            return "";
        else
            res += pq.top().second;
    }

    return res;
}
