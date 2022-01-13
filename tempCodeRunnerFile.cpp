// O(n) space
//  vector<int> majorityElements(vector<int> &nums)
//  {
//      unordered_map<int, int> frequencyOfElements;
//      vector<int> res;

//     int k = nums.size() / 3;

//     for (int num : nums)
//         frequencyOfElements[num]++;

//     for (pair<int, int> obj : frequencyOfElements)
//     {
//         if (obj.second > k)
//             res.push_back(obj.first);
//     }

//     return res;
// }